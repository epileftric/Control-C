#include "Controller.h"

Controller::Controller(System *s, complexVector &J, Notifier *nt): 
	System(),poles(J), sys(s){
	
	setNotifier(nt);
	if ( s == 0 ){
		if (notify)
			notify->reportStatus(__func__,"Sistema no válido para iniciar el controlador");
		return;
	}

	mat_name[mat::Phi] = "Phi(A)";
	Mat_vect[mat::Phi_A]=&Phi_A; 
	Mat_vect[mat::k]=&k;
	
	runControl = false;
	inR=inX=outU = 0;
	
	rebuild();
}

bool Controller::rebuild(void) {
	period_us = 1000000*sys->getTSample();
	
	//~ period_us *= 5;
	
	
	setDimenciones(sys->getVE(), sys->getEntradas(), sys->getSalidas());
	
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
		
	if ( sys->testCntrl() == false )	{
		if (notify)
				notify->reportStatus(__func__,"Sistema no controlable");
			return false;
	}
	
	//~ single input! Uso acker
	if ( m == 1 ) {
		Phi_A = computePhiA(sys->getMat(mat::A),poles);
		
		k = acker(sys->getMat(mat::cntrl),Phi_A);
	}	
	else { //~ m > 1 tendria que usar poleplace
		if( notify )
			notify->reportStatus(__func__,"Falta implementar \"Pole Place\" para sistemas con más de 1 entrada");
		return false;
	}
	Mat *As=sys->getMat(mat::A),
		*Bs=sys->getMat(mat::B),
		*Cs=sys->getMat(mat::C),
		*Ds=sys->getMat(mat::D);
	
	
	B = new Mat(n,n,CV_64FC1,0.0);
	*B = Bs->clone() * k->clone() ;
	
	A = new Mat(n,n,CV_64FC1,0.0);
	*A  = As->clone() - B->clone();
	
	D = new Mat(p,n,CV_64FC1,0.0);
	*D = Ds->clone() * k->clone() ;
	
	C = new Mat(p,n,CV_64FC1,0.0);
	*C  = Cs->clone() - D->clone();
	setDimenciones(A->rows,B->cols,C->rows);
	
	if (notify)
		notify->reportStatus(__func__,"");
		
	return checkDimensions();
}

bool Controller::checkDimensions(void){
	uint fil[mat::MATRIX_NO]={n,n,p,p,n,0,0,0,m,0};
	uint col[mat::MATRIX_NO]={n,n,n,n,n,0,0,0,n,0};
		
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

void Controller::startController( bool threaded, ioIF *R, ioIF *X, ioIF *U  ){
	if ( R != 0 )
		inR = R;
	if ( X != 0 )
		inX = X;
	if ( U != 0 )
		outU = U;
		
	if ( inR  == 0 ){
		if (notify)
			notify->reportStatus(__func__,"No se definió una interfaz de entrada para Setpoints (R)");
		return;		
	}
	if ( inX  == 0 ){
		if (notify)
			notify->reportStatus(__func__,"No se definió una interfaz de entrada para las Variables de Estado (X)");
		return;		
	}
	if ( outU  == 0 ){
		if (notify)
			notify->reportStatus(__func__,"No se definió una interfaz de salida para las Fuerzas de control (U)");
		return;		
	}
	runControl = true;
	if ( threaded == false )
		controlLoop();
	else {
		thr = new std::thread(&Controller::controlLoop,this);
		thr->detach();
	}

}

//~ extern doubleVector VE[3];
void Controller::controlLoop(void){
	
	uint _m = sys->getEntradas();
	
	Mat X_k = Mat(n,1,CV_64FC1,0.0);
	Mat R_k = Mat(n,1,CV_64FC1,0.0);
	Mat U_k = Mat(_m,1,CV_64FC1,0.0);
	
	while( inR->size() > 0 && runControl ){
		
		if ( inR->recv((double*)R_k.data,n) > 0 && inX->recv((double*)X_k.data,n) > 0){
			
			//~ for (int i = 0; i < 3; i++)
					//~ VE[i].push_back( X_k.at<double>(i,0) );
			//~ 
			//~ cout << mat2str(R_k) << endl << endl;
			
			auto start = std::chrono::high_resolution_clock::now();
			
			U_k = k->clone() * ( R_k - X_k );
			outU->send((double*)U_k.data,_m);
			//~ 
			//~ if (  U_k.at<double>(0,0) >= 24.0 )
				//~ U_k.at<double>(0,0) = 24.0;
			//~ 
			//~ if (  U_k.at<double>(0,0) <= 0.0 )
				//~ U_k.at<double>(0,0) = 0.0;
			//~ 

			auto elapsed = std::chrono::high_resolution_clock::now() - start;
			long elapsed_us = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
			
			long time_left = period_us - elapsed_us; 
			if ( time_left > 0 )
				usleep( time_left);
			else {
				if (notify)
					notify->reportStatus(__func__,"period_us no alcanza");
			}
		}
	}
}



