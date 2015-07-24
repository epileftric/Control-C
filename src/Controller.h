#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <System.h>
#include <Methods.h>
#include <unistd.h>

class Controller: public System
{
	public:
		Controller();
		~Controller(){};
		Controller(System *s, complexVector &poles, Notifier *nt=0);
		
		bool rebuild(void);
		bool checkDimensions(void);
		void startController( bool threaded = true, ioIF *R=0, ioIF *X=0, ioIF *U=0 );
		
		void stopControlThread(void){
			runControl = false;
						
			if ( thr->joinable() ) 
				thr->join();
		}
		bool isRunning(void){
			return runControl;
		}
		inline System* getSys(void){
			return sys;
		}
		complexVector getPoles(void){
			return poles;
		}
		bool setPoles(complexVector J){
			complexVector aux = poles;
			poles = complexVector(J);
			bool retval = rebuild();
			
			if ( retval == false)
				poles = aux;
			
			return retval;
		}
		void setIOs( ioIF *R,ioIF *X,ioIF *U){
			inR = R;
			inX = X;
			outU = U;
		}
	private:
		void controlLoop(void);
		std::thread *thr;
		complexVector poles;
		bool 	runControl;
		ioIF 	*inR,*inX,*outU;
		System	*sys;
		Mat  	*Phi_A = 0;
		Mat  	*k = 0;
		uint 	period_us=0;
		
};

extern Controller *control;

#endif /* CONTROLLER_H */ 
