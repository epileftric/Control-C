#ifndef POLESMETHODS_H
#define POLESMETHODS_H

#include <typedef.h>
#include <PolyMat.h>

#include <Notifier.h>

namespace ControlMethod {
	Mat* acker(Mat *A, Mat *B, complexVector poles);
	Mat* acker(Mat *control, Mat *phiA);
	void acker(Mat *dest, Mat *control, Mat *phiA);
	
	void Cntrl(Mat* dest, Mat *A, Mat *B);
	Mat* Cntrl(Mat *A, Mat *B);
	
	void Obser(Mat* dest, Mat *A, Mat *C);
	Mat* Obser(Mat *A, Mat *C);
	
	void computePhi(Mat* dest, Mat *A, double Ts);
	Mat* computePhi(Mat *A, double Ts);
	
	void computePsi(Mat *dest, Mat *A, Mat *B, Mat *Phi);
	Mat* computePsi(Mat *A, Mat *B, Mat *Phi);
	
	void computePhiA(Mat *dest,Mat *A, complexVector &poles);	
	Mat* computePhiA(Mat *A, complexVector &poles);
	
	namespace ControlConfig{
		void setPrecision(uint value);
		uint getPrecision(void);
	}	
}

namespace MathMethods {
	uint Rank(Mat *m);
	
}
using namespace ControlMethod;
using namespace MathMethods;
#endif /* POLESMETHODS_H */ 
