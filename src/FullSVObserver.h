#ifndef FULLOBSERVER_H
#define FULLOBSERVER_H

#include <Observer.h>

class FullSVObs: public Observer
{
	public:
		FullSVObs(System *sys,complexVector poles,Notifier *nt=0);

		bool rebuild(void);
		bool checkDimensions(void);
		void observerLoop(void);
		
};

#endif /* FULLOBSERVER_H */ 
