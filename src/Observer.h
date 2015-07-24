#ifndef OBSERVER_H
#define OBSERVER_H

#include <unistd.h>
#include <System.h>

enum o_type { null=0, FullSV, ReducedSV, Kalman};

class Observer: public System
{
	public:
		Observer():System() {
			Mat_vect[mat::l]= &l;
			setType( o_type::null );
		};
		virtual ~Observer(){
			if ( l != 0 )
				delete l;
		};
		virtual bool rebuild(void) = 0;
		virtual bool checkDimensions(void) =0;
		virtual void observerLoop( void ) = 0;
		
		
		inline System* getSys(void){
			return sys; 
		}
		inline complexVector getPoles(void){
			return poles;
		}
		bool setPoles(complexVector J){
			complexVector aux = poles;
			poles = complexVector(J);
			
			if ( rebuild() == false){
				poles = aux;
				return false;
			}
			
			return true;
		}
		
		using System::setTSample;
		using System::eqnX_k1;
		using System::eqnY_k1;
		using System::setMat;
		using System::getMat;
		using System::getMatName;
		using System::getTSample;
		using System::setVE;
		using System::setEntradas;
		using System::setSalidas;
		using System::setDimenciones;
		using System::getVE;
		using System::getEntradas;
		using System::getSalidas;
		using System::setNotifier;
		using System::getNotifier;
		using System::setName;
		using System::getName;
		using System::printSystem;
		
		enum o_type getType(void){
			return observer_type;
		}
		void stopObserverThread(void){
			runObserver = false;
			
			if ( thr->joinable() ) 
				thr->join();
		}
		
		
		
		void startObserver( bool thread , ioIF *U=0, ioIF *Y=0, ioIF *X=0 ){
			if ( U != 0 )
				inU = U;
			if ( Y != 0 )
				inY = Y;
			if ( X != 0 )
				outX = X;
				
			if ( inU  == 0 ){
				if (notify)
					notify->reportStatus(__func__,"No se definió una interfaz de entrada para las fuerzas de acción (U)");
				return;		
			}
			if ( inY  == 0 ){
				if (notify)
					notify->reportStatus(__func__,"No se definió una interfaz de entrada para las Variables de Estado medidas (Y)");
				return;		
			}
			if ( outX  == 0 ){
				if (notify)
					notify->reportStatus(__func__,"No se definió una interfaz de salida para las Variables de estado estimadas (Y^)");
				return;		
			}
			
			runObserver = true;
			if ( thread == false )
				observerLoop();
			else {
				thr = new std::thread(&Observer::observerLoop,this);
				thr->detach();
			}

		}
		
		void setIOs(ioIF *inU, ioIF *inY, ioIF *outX ){
			outX=outX;
			inU=inU;
			inY= inY;	
		}
		
			
			
	protected:

		void setType(enum o_type t){
			observer_type =t;
		}
		
		uint period_us;
		ioIF  *outX=0, *inU=0, *inY=0;
		std::thread *thr;
		
		
		complexVector poles;
		System	*sys;
		Mat  	*l;
		double 	Ts;
		
		bool runObserver = false;
		
	private:
		
		enum o_type observer_type;

};


extern Observer	*observador;

#endif /* OBSERVER_H */ 
