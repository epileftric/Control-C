#ifndef __POLYMAT_H__
#define __POLYMAT_H__

#include <typedef.h>
#include <cv.h>
#include <complex>
#include <string>


using namespace cv;
using namespace std;

namespace Polynomes {

	complexVector polyXconst(const complexVector &P,double coef);
	complexVector polyXconst(const complexVector *P,double coef);

	complexVector polyXpoly(const complexVector &A,const complexVector &B);
	complexVector polyXpoly(const complexVector *A,const complexVector *B);

	string  poly2str(const complexVector &A,bool coef_only=true);
	string  poly2str(const complexVector *A,bool coef_only=true);

	complexVector str2poly(const char * str);


	bool polyIsReal(const complexVector *A);
	bool polyIsReal(const complexVector &A);

	complexVector poles2poly ( complexVector &poles );
	complexVector poles2poly ( complexVector *poles );

}

namespace Matrixes {
	Mat* str2mat( const char *str );

	string mat2str(Mat &mat);
	string mat2str(Mat *mat);

	Mat vect2mat(doubleVector &vect);
	Mat vect2mat(doubleVector *vect);
}

using namespace Polynomes;
using namespace Matrixes;
#endif

