#ifndef __WORKQUEUE_H__
#define __WORKQUEUE_H__

#include <condition_variable>
#include <thread>
#include <string>
#include <mutex>
#include <list>

using namespace std;

template <typename T> class workJob
{
	private:
		string m_message;
		void (T::*func)(void*);
		T *obj;
		void* arguments;

	public:
		
		workJob(const char* message, void(T::*f)(void*), T *o , void * args=0) : 
			m_message(message),
			func(f),
			obj(o),
			arguments(args){};
		
		void workToDo(void){
			(obj->*func)(arguments);
			if (arguments != 0)
				free(arguments);
		}
				
		const char* getMessage() { 
			return m_message.c_str(); 
		}
};


 
template <typename T> class workQueue { 
	private: 
		list<workJob<T>*>   queue;
		std::mutex mtx;
		std::condition_variable  condv;
		
    public:			
		void add(workJob<T> *item) {
			mtx.lock();
			queue.push_back(item);
			condv.notify_one();
			mtx.unlock();
		}
		workJob<T>* remove() {
			std::unique_lock<std::mutex> lck(mtx);
			while ( queue.size() == 0 ) {
				condv.wait(lck);
			}
			workJob<T>* item = queue.front();
			queue.pop_front();
			mtx.unlock();
			return item;
		}
		
		int size() {
			mtx.lock();
			int size = queue.size();
			mtx.unlock();			
			return size;
		}
};



template <typename T> class workerThread : public thread {
	workQueue<T>& m_queue;

	public:
		workerThread(workQueue<T> &queue) : 
			thread(&workerThread::run,this), 
			m_queue(queue){}
 
		void run() {
			while(true) {
				workJob<T>* item = (workJob<T>*)m_queue.remove();
				printf("%s: ",item->getMessage());
				item->workToDo();
				delete item;
			}
		}
};

#endif
