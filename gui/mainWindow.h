#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <UPlot.h>

#include <QMainWindow>
#include <QProgressBar> 

#include <QNotifier.h>
#include <System.h>
#include <Controller.h>
#include <Observer.h>
#include <guiHandler.h>

#include <ui_gui.h>
#include <LabelList.h>


class mainWindow: public QMainWindow , public Ui_ControlModerno
{
	Q_OBJECT
	
	public:
		mainWindow();
		void update(void);
		void updateStatus(const char *str);
		
		
	//~ funciones del tab sistema
		void reloadSystem(void);
		void setABCD(void);
		void finishedEditingTs(void ){
			handler->updateTs( lineTs->text() );
		}
	
	//~ funciones del tab simulacion
		void startSimulation(void);
		void computeN (void){
			bool ok1,ok2;
			double Ts = lineTs->text().toDouble(&ok1);
			double Tf = lineTf->text().toDouble(&ok2);
			if ( ok1 && ok2 ){
				uint N = ceil(Tf/Ts);
				lineN->setText( QString("%1").arg(N) );
			}
		}
	
	//~ funciones del tab Control
		void reloadController(void);
		void guardarPolos(void);
		void guardarK(void);
		void startController(bool tf );
		//~ void changeObserver( int i );
	
	//~ funciones del tab Control
		void reloadObserver(void);
		
	
	
	
		
		

		
	private:
		UPlot 		 *uPlot;
		QProgressBar *progressBar;
		
		
		LabelList *condicionesIniciales,
				  *polosLazoCerrado;
		

			
};

extern mainWindow 	*window;

#endif /* MAINWINDOW_H */ 
