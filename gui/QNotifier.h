#ifndef QNOTIFIER_H
#define QNOTIFIER_H

#include <QObject>
#include <QString>

#include <Notifier.h>

class QNotifier: public QObject, public Notifier{
	Q_OBJECT
	
	public:
		QNotifier(){}
		virtual void reportStatus(const char *, const char *msg){
				emit updateStatus( msg );
			}
		virtual void updateProgress(const char *, int val){
				emit updateProgressBar(val);
			}
		
	signals:
		void updateStatus(const char *);
		void updateProgressBar(int);
		
};
#endif /* QNOTIFIER_H */ 
