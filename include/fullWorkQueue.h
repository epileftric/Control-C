#ifndef __FULLWORKQUEUE_H__
#define __FULLWORKQUEUE_H__

#include <workQueue.h>



template <typename T> class fullWorkQueue {
	workQueue<T>  queue;
	list<workerThread<T>*> workers;
	
	
	public:
		fullWorkQueue<T>(int n=1) {
			if( n < 1 ) n = 1;
			
			for (int i = 0; i < n; i++) 
				workers.push_back( new workerThread<T>(queue) );
		}

		void newWorkJob(const char* message, void(T::*f)(void*), T *obj, void* arg=0 ){
			queue.add( new workJob<T>( message, static_cast<void (T::*)(void*)>(f) ,obj,arg) );
		}
	
		int size(void) {
			return queue.size();
		}
};


#endif
