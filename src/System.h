#ifndef SYSTEM_H
#define SYSTEM_H

#include <chrono>
#include <thread>

#include <cv.h>
#include <PolyMat.h>
#include <Methods.h>

#include <ioif/ioIF.h>
#include <Notifier.h>

enum mat{ A=0,B,C,D,Phi,Phi_A=Phi,Psi,cntrl,obser,k,l,MATRIX_NO };
static	const char *mat_name[mat::MATRIX_NO]={"A",
											  "B",
											  "C",
											  "D",
											  "Phi",
											  "Psi",
											  "Controlabilidad",
											  "Observabilidad",
											  "K",
											  "L"};

class System
{
	public:
		System();
		System(uint VE,uint ent=1,uint sal=1);
		System(Mat*a,Mat*b,Mat*c,Mat*d=0,double tsample=0.001,Notifier *nt=0);

		bool testObser(void);
		bool testCntrl(void);
		void setTSample(double tsample);
		void simulate(Mat *X0=0, bool threaded=false);
		bool rebuild(void);
		bool checkDimensions(void);		
		
		virtual Mat eqnX_k1( Mat *X_k , Mat *U_k){
			return (*Phi) * (*X_k) + (*Psi) * (*U_k);
		}	
		virtual Mat eqnY_k1( Mat *X_k1 , Mat *U_k){
			return (*C) * (*X_k1) + (*D) * (*U_k);
		}
		virtual void setMat(enum mat num, Mat value){
			**Mat_vect[num] = value;
		}		
		virtual void setMat(enum mat num, Mat* value){
			if ( *(Mat_vect[num]) != 0 )
				delete *(Mat_vect[num]);
			*Mat_vect[num] = value;
		}
		
		virtual Mat* getMat(int num){
			if ( num >= 0 && num < mat::MATRIX_NO )
				return *(Mat_vect[num]);
			else
				return 0;
		}
		virtual Mat* getMat(enum mat num){
			return *(Mat_vect[num]);
		}
		virtual const char* getMatName(int num){
			if ( num >= 0 && num < mat::MATRIX_NO )
				return mat_name[num];
			else
				return 0;
		}
		virtual const char* getMatName(enum mat num){
			return mat_name[num];
		}
		
		
		virtual inline double getTSample(void ){return Ts;}
		virtual inline void setVE(uint VE){n=VE;}
		virtual inline void setEntradas(uint Entradas){m= Entradas;}
		virtual inline void setSalidas(uint Salidas){p=Salidas;}
		virtual void setDimenciones(uint VE,uint Entradas,uint Salidas){
			setVE(VE); setEntradas(Entradas); setSalidas(Salidas);
		}
		virtual inline uint getVE(void)		{return n;}
		virtual inline uint getEntradas(void)	{return m;}
		virtual inline uint getSalidas(void)	{return p;}
		
		virtual inline void setNotifier(Notifier* nt){
			notify = nt; 
		}
		virtual inline Notifier * getNotifier(void){
			return notify;
		}
		virtual inline void setIoIF( ioIF * io ) {
			ioif = io; 
		}
		virtual void setName(const char *n){
			name=n;
		}
		virtual const char* getName( void ){
			return name;
		}
		void printSystem(void){
			
			
		}
		
	protected:	
		uint n, // variables de estado
			 m, // entradas
			 p; // salidas
		Mat	*A,*B,*C,*D,*Phi,*Psi,*cntrl,*obser;

		Mat **Mat_vect[mat::MATRIX_NO];
										

		Notifier *notify=0;
		
	private:
		ioIF 	 *ioif=0;
		double 	Ts;
		void simulateThread(Mat *X0=0);
		const char *name;
				
};

extern System *sistema;

#endif /* SYSTEM_H */ 
