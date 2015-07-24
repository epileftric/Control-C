#include "ReducedSVObs.h"


ReducedSVObs::ReducedSVObs(System *s,complexVector J,Notifier *nt)
	: Observer()
{
	if ( s == 0 ){
		if (nt)
			nt->reportStatus(__func__,"Sistema no válido para iniciar");
		return;
	}
	
	sys = s;
	notify=nt;
	setType(o_type::ReducedSV);
	
	poles = J;
	
	rebuild();
	
}


bool ReducedSVObs::rebuild(void){
	setDimenciones(sys->getVE(), sys->getEntradas(), sys->getSalidas());
	Ts = sys->getTSample();
	
	period_us = 1000000*sys->getTSample();
	
	if ( poles.size() >= n ){
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


	
	
	desc = poles.size();
	con  = n - poles.size();
	
	
	Mat *As=sys->getMat(mat::A),
		*Bs=sys->getMat(mat::B);
	
	
	Acc = new Mat( con , con , CV_64FC1, 0.0);
	Add = new Mat( desc, desc, CV_64FC1, 0.0);
	Acd = new Mat( con , desc, CV_64FC1, 0.0);
	Adc = new Mat( desc, con , CV_64FC1, 0.0);
	
	Bc = new Mat( con , m, CV_64FC1, 0.0);
	Bd = new Mat( desc, m, CV_64FC1, 0.0);

	*Acc = (*As)( Range(0,con), Range(0,con) );
	*Add = (*As)( Range(con,desc+1), Range(con,desc+1) );
	*Acd = (*As)( Range(0,con), Range(con,desc+1) );
	*Adc = (*As)( Range(con,desc+1), Range(0,con) );
	
	*Bc = (*Bs)( Range(0,con), Range::all() );
	*Bd = (*Bs)( Range(con,desc+1), Range::all() );
	
		//~ single input! Uso acker
	if ( p == 1 ) {
		l = acker(Add,Adc,poles);
		cv::transpose(*l,*l);					
	}	
	else { //~ p > 1 tendria que usar poleplace
		if( notify )
			notify->reportStatus(__func__,"Falta implementar \"Pole Place\" para sistemas con más de 1 salida");
		return false;
	}

	A = new Mat( desc, desc, CV_64FC1, 0.0);
	B = new Mat( desc, m+con,  CV_64FC1, 0.0);
	C = 0;
	D = 0;
	
	*A = Add->clone() - l->clone() * Acd->clone();
	
	Mat aux = A->clone()*l->clone() + ( Adc->clone() - l->clone() * Acc->clone() );
	
	for( uint j = 0 ; j < con ; j++ )
		aux.col(j).copyTo( B->col(j) );
	
	aux = Bd->clone() - l->clone() * Bc->clone();
	for( uint j = 0 ; j < m ; j++ )
		aux.col(j).copyTo( B->col(con+j) );
	
	
	Phi = new Mat(n,n,CV_64FC1,0.0);
	Phi = computePhi(A,Ts);
	
	Psi = new Mat(n,n,CV_64FC1,0.0);
	Psi = computePsi(A,B,Phi);
	
	setDimenciones(A->rows,B->cols,con+desc);
	
	return true;
}

bool ReducedSVObs::checkDimensions(void){
	int i =0;
	i++;
	if (i < 0 )
		i--;

	return true;
}
void ReducedSVObs::observerLoop(void){

	Mat U_k  =  Mat(m,1,CV_64FC1,0.0);
	Mat X_k  =  Mat(n,1,CV_64FC1,0.0);
	Mat X_k1 =  Mat(n,1,CV_64FC1,0.0);
	Mat Y_k  =  Mat(con+desc,1,CV_64FC1,0.0);
		
	uint m_sys = sys->getEntradas();
	
	while ( runObserver ) {
		
		
		double *dest = (double*) U_k.data;
		inY->recv(  dest , con );
		dest+= con;
		inU->recv(  dest , m_sys );
	
		auto start = std::chrono::high_resolution_clock::now();
		
		X_k1 = eqnX_k1( &X_k , &U_k );
		
		
		///~ rearmo el vector de estados para el controlador
		//~ primero pongo las medidas 
		for (uint i = 0; i < con; i++)
			U_k.row(i).copyTo( Y_k.row(i) );
		//~ y después las estimadas
		for (uint i = 0; i < desc; i++)
			X_k1.row(i).copyTo( Y_k.row(con+i) );
		
		
		
				
		outX->send( (double*)Y_k.data , n );
		
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
