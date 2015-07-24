#include "FullSVObserver.h"


FullSVObs::FullSVObs(System *s,complexVector J,Notifier *nt)
	: Observer()
{
	if ( s == 0 ){
		if (nt)
			nt->reportStatus(__func__,"Sistema no válido para iniciar");
		return;
	}
	
	sys = s;
	notify=nt;
	setType(o_type::FullSV);
	
	poles = J;
	
	rebuild();
}

	
bool FullSVObs::rebuild(void) { 
	setDimenciones(sys->getVE(), sys->getEntradas(), sys->getSalidas());
	Ts = sys->getTSample();
	
	period_us = 1000000*sys->getTSample();
	
	if ( poles.size() != n ){
		if (notify)
			notify->reportStatus(__func__,"Cantidad de polos incorrecta");
		return false;	
	}
	
	if ( polyIsReal(poles2poly(poles)) != true ){
		if (notify)
			notify->reportStatus(__func__,"Las raices no son complejas conjugadas");
		return false;	
	}
		
	if ( sys->testObser() == false )	{
		if (notify)
			notify->reportStatus(__func__,"Sistema no observable");
		return false;
	}

	//~ single input! Uso acker
	if ( p == 1 ) {
		l = acker(sys->getMat(mat::A),sys->getMat(mat::B),poles);
		cv::transpose(*l,*l);					
	}	
	else { //~ p > 1 tendria que usar poleplace
		if( notify )
			notify->reportStatus(__func__,"Falta implementar \"Pole Place\" para sistemas con más de 1 salida");
		return false;
	}

	D = 0;

	C = new Mat(n,n,CV_64FC1,0.0);
	*C  = Mat::eye(n,n,CV_64FC1);

	
	Mat *As=sys->getMat(mat::A),
		*Bs=sys->getMat(mat::B),
		*Cs=sys->getMat(mat::C);
	
	B = new Mat(n,m+p,CV_64FC1,0.0);
	for(uint i = 0; i < m ; i++){
		Bs->col(i).copyTo( B->col(i) );
	}
	for(uint i = 0; i < p ; i++){
		l->col(i).copyTo( B->col(m+i) );
	}
	A = new Mat(n,n,CV_64FC1,0.0);
	*A  = As->clone() - l->clone() * Cs->clone();
	
	Phi = new Mat(n,n,CV_64FC1,0.0);
	Phi = computePhi(A,Ts);
	
	Psi = new Mat(n,n,CV_64FC1,0.0);
	Psi = computePsi(A,B,Phi);

	setDimenciones(A->rows,B->cols,C->rows);
	
	if (notify)
		notify->reportStatus(__func__,"");
	return checkDimensions();
}

void FullSVObs::observerLoop(void){
	Mat U_k  =  Mat(m,1,CV_64FC1,0.0);
	Mat X_k  =  Mat(n,1,CV_64FC1,0.0);
	Mat X_k1 =  Mat(n,1,CV_64FC1,0.0);
		
	uint m_sys = sys->getEntradas();
	uint p_sys = sys->getSalidas();
	
	
	while ( runObserver ) {
		
		double *dest = (double*) U_k.data;
		inU->recv(  dest , m_sys );
		dest+= m_sys;
		inY->recv(  dest , p_sys );
		
		auto start = std::chrono::high_resolution_clock::now();
	
		X_k1 = eqnX_k1( &X_k , &U_k );
				
		outX->send( (double*)X_k1.data , n );
		
		X_k = X_k1;
		
		auto elapsed = std::chrono::high_resolution_clock::now() - start;
		long elapsed_us = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
		
		long time_left = period_us - elapsed_us; 
		if ( time_left > 0 )
			usleep( time_left);
		else if (notify)
				notify->reportStatus(__func__,"Period_us no alcanza");			
	}
	

}



bool FullSVObs::checkDimensions(void) {
	uint fil[mat::MATRIX_NO]={n,n,n,0,n,n,0,0,0,p};
	uint col[mat::MATRIX_NO]={n,m,n,0,n,m,0,0,0,n};

	bool test = true;
	for (int i = 0; i < mat::obser; i++) {
	Mat *matrix = getMat(i);
	
		if ( matrix != 0 ) {
			if ( (uint)matrix->cols != col[i] || (uint)matrix->rows != fil[i] ){
				if ( notify ) {
					string reporte="Error en la dimenciones de la matriz ";
					reporte += mat_name[i];
					notify->reportStatus(__func__,reporte.c_str());
				}
				test = false;
			}
		}
	}
	return test;
}
