#ifndef GUIHANDLER_H
#define GUIHANDLER_H

#include <thread>

#include <QUdpSocket>

#include <QStringList>
#include <QObject>
#include <QString>
#include <QNotifier.h>

#include <System.h>
#include <Controller.h>
#include <ReducedSVObs.h>
#include <FullSVObserver.h>


#include <Observer.h>


#include <UPlot.h>
#include <ioif/ioVect.h>
#include <ioif/ioMulty.h>
#include <ioif/ioUDP.h>
#include <ioSlider.h>

enum signalType{ escalon=0,rampa,parabola };

typedef struct {
	int tipo;
	double Tf; 
	double To; 
	double A;
	doubleVector Xo;
} simu_param;

typedef struct {
	ioIF *inX,*inR,*outU;
} control_param;


class guiHandler: public QObject{
	Q_OBJECT
	
	public:
		guiHandler();
		
	///~ Funciones del sistema:
		void setABCD(QString ,QString ,QString ,QString );
		void updateTs(QString);
		void startSimulation(int tipo, double Tf, double To, double A, doubleVector &Xo);
		
		
	///~ Funciones del controlador
		void guardarPolos(QStringList *);
		void guardarK(QString *);
		void startController(bool tf, enum o_type obs = o_type::null);
		
		
		void changeObserver( enum o_type obs );
	
	///~ Funciones generales;
		
		QNotifier* getNotifier(void){
			return nt;
		}
		void setSliderRef(QSlider *ref){
			inR  = new ioSlider(ref);;
		}
	private: 
		QNotifier   *nt=0;
		ioIF *outU, *multiU, *inU, *inY, *outY, *inX, *inR;
		
		
		void simulationThread(simu_param *P);


	signals:
		void reloadSystem(void);
		void reloadController(void);
		void reloadObserver(void);
		void addPlot(doubleVector &time_base,doubleVector &axis);
		void clearPlot(void);
};


extern guiHandler *handler;

#endif /* GUIHANDLER_H */ 
