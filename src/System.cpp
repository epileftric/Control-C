#include "System.h"

System::System(uint VE,uint ent,uint sal):System(){

	setDimenciones(VE,ent,sal);
	
	uint fil[mat::MATRIX_NO]={n,n,p,p,n,n,n  ,n*p,0,0};
	uint col[mat::MATRIX_NO]={n,m,n,m,n,m,n*m,n  ,0,0};
	
	for (int i = 0; i <= mat::Psi; i++){
		if ( fil[i] != 0 ){
			Mat *new_mat = new Mat(fil[i],col[i],CV_64FC1,0.0);
			setMat( static_cast<mat>(i) ,new_mat);
		}
	}
	
}

System::System(Mat*a,Mat*b,Mat*c,Mat*d,double tsample,Notifier *nt):System(){
	A = a; B = b; C = c; D = d;
	if ( D == 0 )
		D = new Mat(C->rows,B->cols,CV_64FC1,0.0);
	
	Ts = tsample;
	
	setNotifier(nt);
	
	rebuild();
}

bool System::rebuild(void){
	setDimenciones(A->rows,B->cols,C->rows);

	if ( Phi ) delete Phi;
	if ( Psi ) delete Psi;
	if ( cntrl ) delete cntrl;	
	if ( obser ) delete obser;
	Phi = Psi = cntrl = obser = 0;
	
	bool ret_val = checkDimensions();
	if( ret_val == true ){
		Phi = computePhi(A,Ts);
		Psi = computePsi(A,B,Phi);
		cntrl = Cntrl(A,B);
		obser = Obser(A,C);
		ret_val &= testCntrl();
		ret_val &= testObser();
	}
	if ( notify && ret_val )
		notify->reportStatus(__func__,"");
	return ret_val;
}

bool System::checkDimensions(void){
	uint fil[mat::MATRIX_NO]={n,n,p,p,n,n,n  ,n*p,0,0};
	uint col[mat::MATRIX_NO]={n,m,n,m,n,m,n*m,n  ,0,0};
		
	bool test = true;
	for (int i = 0; i <= mat::obser; i++) {
		Mat *matrix = getMat(i);
		
		if ( matrix != 0 ) {
			if ( (uint)matrix->cols != col[i] || (uint)matrix->rows != fil[i] ){
				string reporte="Error en la matriz ";
				reporte += mat_name[i];
				
				test = false;

				if (notify != 0)
					notify->reportStatus(__func__,reporte.c_str());
			}
		}
	}
	return test;
}

void System::setTSample(double tsample){
	Ts=tsample;
	if ( Phi )
		delete Phi;
	if ( Psi )
		delete Psi;
	Phi = computePhi(A,Ts);
	Psi = computePsi(A,B,Phi);			
}

bool System::testCntrl(void){
	bool ret_val = true;
	if ( Rank(cntrl) != getVE() ){
		ret_val = false;
	}
	///~  si es falso informo antes!
	if ( notify != 0 && ret_val == false ) {
		notify->reportStatus(__func__,"Sistema NO controlable");
	}
	return ret_val;
}
bool System::testObser(void){
	bool ret_val = true;
	if ( Rank(obser) != getVE() ){
		ret_val = false;
	}
	///~  si es falso informo antes!
	if ( notify != 0 && ret_val == false ) {
		notify->reportStatus(__func__,"Sistema NO observable");
	}
	return ret_val;
}

void System::simulate( Mat *X0 ,bool thread ){
	if ( ioif == 0 ){
		if ( notify ) 
			notify->reportStatus(__func__, "No se puede simular, no se definio interfaz de entrada/salida");
		return;
	}
	if ( thread == false )
		simulateThread(X0);
	else{
		std::thread simulation(&System::simulateThread,this,X0);
		simulation.detach();
	}

}

void System::simulateThread(Mat *X0){
	Mat U_k  =  Mat(m,1,CV_64FC1,0.0);
	Mat X_k  =  Mat(n,1,CV_64FC1,0.0);
	Mat X_k1 =  Mat(n,1,CV_64FC1,0.0);
	Mat Y_k1 =  Mat(p,1,CV_64FC1,0.0);
		
	if ( X0 != 0 )
		X_k = X0->clone();
	
	uint N=ioif->size();
	uint k=0;
	auto start = std::chrono::high_resolution_clock::now();
	while ( ioif->recv( (double*)U_k.data , m ) > 0 ) {
		
		X_k1 = eqnX_k1( &X_k , &U_k );
		Y_k1 = eqnY_k1( &X_k1, &U_k );
		
		ioif->send( (double*)Y_k1.data , p );
		X_k = X_k1;
		
		if ( notify != 0 && N > 1 ) {
			k++;
			if ( k % 128 == 0 )
				notify->updateProgress(__func__, 100 * k / N );
		}
	}
	
	auto elapsed = std::chrono::high_resolution_clock::now() - start;
	long us = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
	
	if ( notify ){
		notify->updateProgress(__func__, 100 );
		stringstream mensaje;
		mensaje << "La simulacion duro: ";
		mensaje << us;
		mensaje << " us";
		notify->reportStatus(__func__, mensaje.str().c_str());
	}
}

System::System(){
	n=0,
	m=0,
	p=0;
	A=0,
	B=0,
	C=0,
	D=0,
	Phi=0,
	Psi=0,
	cntrl=0,
	obser=0;

	Ts=0.001;
	
	Mat_vect[mat::A    ]=&A;
	Mat_vect[mat::B    ]=&B;
	Mat_vect[mat::C    ]=&C;
	Mat_vect[mat::D    ]=&D;
	Mat_vect[mat::Phi  ]=&Phi;
	Mat_vect[mat::Psi  ]=&Psi;
	Mat_vect[mat::cntrl]=&cntrl;
	Mat_vect[mat::obser]=&obser;
	Mat_vect[mat::k    ]=0;
	Mat_vect[mat::l    ]=0;
										
	notify=0;
	ioif=0;
}
