#ifndef NOTIFIER_H
#define NOTIFIER_H

#include <iostream>
#include <string>

using namespace std;

class Notifier{
	public:
		Notifier(){};
		virtual ~Notifier(){};
		virtual void reportStatus(const char *, const char*){};
		virtual void updateProgress(const char *, int){};
};

class ConsoleNotifier : public Notifier
{
	public:
		ConsoleNotifier(const char *name=0){
			my_name = name;
		}
		virtual void reportStatus(const char *func,const char *str){
			if ( my_name != 0 && *str != '\0' ) 
				cout << my_name << ": ";
			if ( *str != '\0' )
				cout << func << ": " << str << endl;
		}
		virtual void updateProgress(const char *func,int progreso){
			if ( progreso >= 0 && progreso <= 100 ){
				if ( my_name != 0 )
					cout << my_name << ": ";
				cout << func << ": "<< "Progreso: " << progreso << " %" << endl;
			}
		}
	private:
		const char * my_name;
};

#endif
