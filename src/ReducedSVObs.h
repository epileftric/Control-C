#ifndef REDUCEDSVOBS_H
#define REDUCEDSVOBS_H

#include <Observer.h>

class ReducedSVObs: public Observer
{
	public:
		ReducedSVObs(System *s,complexVector J,Notifier *nt=0);
		bool rebuild(void);
		bool checkDimensions(void);
		void observerLoop( void );

	private:
		Mat *Acc,*Acd,*Adc,*Add,*Bc,*Bd;
		uint desc,con;
};

#endif /* REDUCEDSVOBS_H */ 
