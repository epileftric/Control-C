#include "Methods.h"

static ConsoleNotifier nt("ControlMethod");
static uint precision=6;
void ControlMethod::ControlConfig::setPrecision(uint value){
	precision = value;
}
uint ControlMethod::ControlConfig::getPrecision(void){
	return precision;
}


Mat* ControlMethod::acker(Mat *A, Mat *B, complexVector poles){
	Mat *K;
	Mat *control = Cntrl(A,B);
	Mat *phiA = computePhiA(A,poles);
	
	K = acker(control,phiA);
	
	delete control;
	delete phiA;
	
	return K;
}
Mat* ControlMethod::acker(Mat *control, Mat *phiA){
	uint n = phiA->rows;
	Mat *K = new Mat(1,n,CV_64FC1,0.0);
	acker(K,control,phiA);
	return K;
}
void ControlMethod::acker(Mat *K, Mat *control, Mat *phiA){
	uint n = phiA->rows;
	
	Mat unidad = Mat(1,n,CV_64FC1,0.0);
	unidad.at<double>(0,n-1) = 1.0;
	
	*K = unidad * control->inv() * (*phiA);	
}



Mat* ControlMethod::Cntrl(Mat *A, Mat *B){
	uint n = A->cols;
	uint m = B->cols;
	Mat *c= new Mat(n,n*m,CV_64FC1,0.0 );
	Cntrl(c,A,B);
	return c;
}
void ControlMethod::Cntrl(Mat *cntrl, Mat *A, Mat *B){
	
	uint n = A->cols;
	uint m = B->cols;
	
	Mat A_n = Mat::eye(n,n,CV_64FC1);
	Mat Aux = Mat::zeros(n,n,CV_64FC1);
	Aux = A_n * B->clone();
	for( int j = 0 ; j < B->cols ; j++ )
		Aux.col(j).copyTo( cntrl->col(j) );
	
	for (uint i = B->cols ; i < n*m ; i+= B->cols ){
		A_n *= (*A);
		
		Aux = A_n * B->clone();
		for( int j = 0 ; j < B->cols ; j++ )
			Aux.col(j).copyTo( cntrl->col(i+j) );
	}
}

Mat* ControlMethod::Obser(Mat *A, Mat *C){
	uint n = A->cols;
	uint p = C->rows;
	Mat *o = new Mat(n*p,n,CV_64FC1,0.0 );
	Obser(o,A,C);
	return o;
}
void ControlMethod::Obser(Mat *obser, Mat *A, Mat *C){
	
	uint n = A->cols;
	uint p = C->rows;
		
	Mat A_n = Mat::eye(n,n,CV_64FC1);
	Mat Aux = Mat::zeros(n,n,CV_64FC1);
	
	Aux = C->clone() * A_n;
	for ( int j = 0 ; j <  C->rows; j++ )
		Aux.row(j).copyTo( obser->row(j) );

	
	for (uint i = C->rows ; i < n*p; i+= C->rows){
		A_n *= (*A);
		Aux = C->clone() * A_n;
		for( int j = 0 ; j < C->rows ; j++ )
			Aux.row(j).copyTo( obser->row(i+j) );
	}
}

uint MathMethods::Rank(Mat *m){
	///~ Calculo los autovalores
	Mat w;
	SVD::compute(*m,w);
	return countNonZero(w);
}



Mat* ControlMethod::computePhi(Mat *A, double Ts ){
	uint n = A->rows;
	Mat *P = new Mat(n,n,CV_64FC1,0.0 );
	computePhi(P,A,Ts);
	return P;	
}
void ControlMethod::computePhi(Mat *Phi, Mat *A, double Ts){
	uint n = A->rows;
	
	/// termino 0
	// A ^ 0 = identidad
	Mat A_n = Mat::eye(n,n,CV_64FC1);
	// i = 0! = 1;
	double i_n = 1.0; 
	// Ts ^ 0 = 1;	
	double dT_n = 1.0;

	*Phi = A_n.clone();

	///terminos i -> precision
	for ( uint i = 1; i <= precision; i++ ) {
		A_n  *= (*A);
		i_n  *=  i;
		dT_n *=  Ts;

		(*Phi) +=  A_n * (dT_n / i_n)  ;
	}
}

Mat* ControlMethod::computePsi(Mat *A, Mat *B, Mat *Phi){
	uint n = A->rows;
	uint m = B->cols;
	Mat *P = new Mat(n,m,CV_64FC1,0.0 );
	computePsi(P,A,B,Phi);
	return P;
}
void ControlMethod::computePsi(Mat *Psi, Mat *A, Mat *B, Mat *Phi){
	uint n = A->rows;
	Mat I = Mat::eye(n,n,CV_64FC1);
	*Psi = A->inv() * ((*Phi) - I ) * (*B);
}



Mat* ControlMethod::computePhiA(Mat* A, complexVector &poles){
	uint n = A->rows;
	Mat *Phi_A = new Mat(n,n,CV_64FC1,0.0 );
	computePhiA(Phi_A,A,poles);
	return Phi_A;	
}

void ControlMethod::computePhiA(Mat *Phi_A, Mat* A, complexVector &poles){
	uint n = A->rows;
	complexVector poly = Polynomes::poles2poly( poles );
	
	if ( poles.size() != n ){
		*Phi_A =  Mat::zeros(n,n,CV_64FC1);
		nt.reportStatus(__func__,"Cantidad de polos incorrecta");
		return;
	}
	if ( Polynomes::polyIsReal(poly) == false ){
		*Phi_A =  Mat::zeros(n,n,CV_64FC1);
		nt.reportStatus(__func__,"Los polos no son complejos conjugados");
		return;
	}
	
	Mat A_n = Mat::eye(n,n,CV_64FC1);
	double coef = real( poly.at(n) ); 
	*Phi_A = A_n * coef;
	
	for (uint i = 1; i < poly.size(); i++) {
		A_n *= (*A);
		coef = real( poly.at(n-i) );
		*Phi_A += A_n * coef;
	}
}

