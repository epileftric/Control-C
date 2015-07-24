#include "PolyMat.h"



Mat Matrixes::vect2mat(doubleVector &vect){
	return vect2mat(&vect);
}
Mat Matrixes::vect2mat(doubleVector *vect){
	
	uint n = vect->size();
	Mat mat(n,1,CV_64FC1,0.0);
	double *data = (double*)mat.data;
	
	for (uint i = 0; i < n; i++)	{
		data[i]= (*vect)[i];
	}
	return mat;
}


string Matrixes::mat2str(Mat &mat){
	return mat2str(&mat);
}
string Matrixes::mat2str(Mat *mat){
	if ( mat == 0 )
		return string("");
		
	stringstream text;
	
	text.precision(4);
	
	int n = mat->rows;
	int m = mat->cols;
	
	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < m; j++)	{
			text << mat->at<double>(i,j);
			
			if ( j < m-1 )
				text << "  ";
		}
		if ( i < n-1 )
			text << "\n";
	}
	return text.str();
}


static bool is_numeric (const string& str_ro) {
    
    string str=str_ro;
    const char *str_c = str.c_str();
    
   
    if ( str_c[0] == '(' )
		return true;
    
    istringstream ss(str);
    double dbl;
    ss >> dbl;      // try to read the number
    ss >> std::ws;  // eat whitespace after number

    if (!ss.fail() && ss.eof()) {
        return true;  // is-a-number
    } else {
        return false; // not-a-number
    }
}


Mat* Matrixes::str2mat( const char *str_ro ){
		double value[32][32]={0.0};

		string str(str_ro);
		replace(str.begin(), str.end(), '\n', ';');
		replace(str.begin(), str.end(), '[', ' ');
		replace(str.begin(), str.end(), ']', ' ');
		
		
		stringstream 	ss(str);
		string		 	line;
		string			col;
		int i;
		int j;
		for ( i = 0; getline(ss,line,';') ; i++){
			stringstream line_ss(line);
			for (j = 0; getline(line_ss,col,' ') ; ){
				stringstream elemt(col);
				if ( is_numeric(col) ){
					elemt >> value[i][j];
					j++;
				}
			}			
		}
		
		int _n = i;
		int _m = j;

		Mat *mat= new Mat(_n,_m,CV_64FC1,0.0);
		double *array = (double*)mat->data;

		for (int i = 0; i < _n ; i++) {
			for (int j = 0; j < _m ; j++) {
				array[ j + i*_m] = value[i][j];
			}
		}
		
		
		return mat;
}

complexVector Polynomes::polyXpoly(const complexVector &A,const complexVector &B){
	return polyXpoly(&A,&B);
}
complexVector Polynomes::polyXpoly(const complexVector *A,const complexVector *B){
	
	
	int Al=A->size();
	int Bl=B->size();
	
	int N = Al + Bl -1 ;
	complexVector C;
	
	for (int i = 0; i < N; i++)
		C.push_back( complex_f(0,0) );

	for (int i = 0; i < Al; i++) {
		for (int j = 0; j < Bl; j++) {
			C[i+j] += (*A)[i] * (*B)[j];
		}
	}
	return C;
}

complexVector Polynomes::polyXconst(const complexVector &P,double coef){
	return Polynomes::polyXconst(&P,coef);
}
complexVector Polynomes::polyXconst(const complexVector *P,double coef){
	uint n = P->size();
	complexVector C;
	complex_f ccoef(coef,0);
	for (uint i = 0; i < n; i++) {
		C.push_back( (*P)[i] * coef );
	}
	return C;
}


string  Polynomes::poly2str(const complexVector &A,bool coef_only){
	return poly2str(&A,coef_only);
}
string  Polynomes::poly2str(const complexVector *A,bool coef_only){
	if ( A == 0 )
		return string("");
		
	stringstream str;
	int n = A->size()-1;
	
	if (coef_only == true)
		str << "[ ";
	
	for (int i = 0; i <= n; i++) 	{
		if ( imag((*A)[i]) != 0 )
			str << (*A)[i];
		else
			str << real((*A)[i]);
		 
		if ( i < n &&  coef_only == false )
			str << "*S^" << n-i << " + ";
		else
			str << " ";
	}
	
	if (coef_only == true)
		str << "]";
	
	return str.str();
}


complexVector Polynomes::str2poly(const char * const_str){
	complexVector output;
	string str(const_str);
		replace(str.begin(), str.end(), '\n', ' ');
		replace(str.begin(), str.end(), ';',  ' ');
		replace(str.begin(), str.end(), '[',  ' ');
		replace(str.begin(), str.end(), ']',  ' ');
	
	stringstream 	ss(str);
	string 			termino;
	
	while ( getline(ss,termino,' ') ){
		if ( is_numeric( termino ) ){
			istringstream is(termino);
			complex_f c;
			is >> c;
			output.push_back(c);
		}
	}
	return output;
	
}

complexVector Polynomes::poles2poly ( complexVector &poles ){
	return poles2poly(&poles);
}
complexVector Polynomes::poles2poly ( complexVector *poles ){
	
	complexVector 	poly;
	poly.push_back(1);
	
	for (uint i = 0; i < poles->size(); i++) {
		
		complexVector polo;
		complex_f p = (*poles)[i];
		
		polo.push_back(1);
		polo.push_back(-p);
		
		poly = polyXpoly(poly,polo);
	}
	return poly;
}



bool Polynomes::polyIsReal(const complexVector &A){
	return polyIsReal(&A);
}

bool Polynomes::polyIsReal(const complexVector *A){
	bool ret_val=true;
	
	for (uint i = 0; i < A->size(); i++) {
		if ( imag( (*A)[i] ) != 0 )
			ret_val = false;
	}
	
	return ret_val;
}
