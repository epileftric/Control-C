#include <QApplication>

#include <mainWindow.h>
#include <guiHandler.h>

#include <System.h>
#include <Controller.h>
#include <Observer.h>

#include <guiHandler.h>

#include <Notifier.h>


#include <csvExport.h>
#include <ioif/ioVect.h>
#include <ioif/ioMulty.h>
#include <ioif/ioUDP.h>

mainWindow	*window;
guiHandler	*handler;

System  	*sistema;
Controller  *control;
Observer	*observador=0;



void funcTimeBase(double Ts, doubleVector *timeBase){
	for( double t=0.0 ; t < 10.0; t+=Ts )
		timeBase->push_back(t);	
}
void funcEscalones(doubleVector *timeBase, doubleVector *data){
	double a1 = 2.0;
	double a2 = 6.0;
	for (uint i = 0; i < timeBase->size() ; i++){
		double x = timeBase->at(i);
		if ( x < a1 )
			data->push_back(0.0);
		else if ( x < a2 )
			data->push_back( 0.5*M_PI );
		else
			data->push_back(1.5*M_PI);			
	}
}
void funcRampa(doubleVector *timeBase, doubleVector *data){
	
	double a1 = 2.0;
	double a2 = 8.0;
	double m = 1.5 * M_PI / (a2-a1);
	double b = -m * a1;
	for (uint i = 0; i < timeBase->size() ; i++){
		double x = timeBase->at(i);
		if ( x < a1 )
			data->push_back(0.0);
		else if ( x < a2 )
			data->push_back( m*x + b );
		else
			data->push_back(1.5*M_PI);			
	}
}


doubleVector *timeBase,controlFunc[1],referencias[3],VE[3];

int main(int argc,char *argv[]){
	
	ioIF *outU, 
		 //~ *multiU, 
		 //~ *inU, 
		 *inY, 
		 //~ *outY, 
		 //~ *inX, 
		 *inR,*inR2;
	timeBase = new doubleVector();
	//~ controlFunc[0] = new doubleVector();
	//~ VE[0] = new doubleVector();
	//~ VE[1] = new doubleVector();
	//~ VE[2] = new doubleVector();
	
	
	
	///~ Parametros del sistema:	
	//~ Mat *A = str2mat("[ 0.00  3030303.03 ; -10 -2200]");
	//~ Mat *B = str2mat("[ 10 ; 00 ]");
	//~ Mat *C = str2mat("[ 1 0 ]");
	Mat *A = str2mat("[ 0  1  0 ; 0  -0.114  9.9029	 ; 0  -408  -12]");
	Mat *B = str2mat("[ 0 ; 0 ; 20 ]");
	Mat *C = str2mat("[ 1 0 0 ]");
	double Ts = 0.001;

	complexVector Jc = str2poly("[(-2.0,-5.29) (-2.0,5.29)  -18]");
	//~ complexVector Jo = polyXconst(Jc,10.0);
	//~ Jo.pop_back();
		
	///~  Construyo los tres objetos que componen al sistema
	sistema    = new System(A,B,C,0,Ts);
	control    = new Controller(sistema,Jc);
	//~ observador = new ReducedSVObs(sistema,Jo);
	
	funcTimeBase(Ts,timeBase);
	funcRampa(timeBase,controlFunc+0);
	
	
	
	outU = new ioUDP(0,4097);
	//~ multiU = new ioMulty( outU, new ioUDP(0,4098) );
	//~ inU   = new ioUDP(4098,0);
	inY  = new ioUDP(4096,0);
	//~ outY = new ioUDP(0,4102);
	//~ inX = new ioUDP(4102,0);
	
	inR = new ioVect(controlFunc+0,1);
	
	
	system("killall -9 Plotter.exe");
	sleep(1);
	outU->send(0,0);
	control->startController(false,inR,inY,outU);

	for (uint i = 0; i < VE[0].size(); i++)
	{
		referencias[0].push_back(VE[0].at(i));
		referencias[1].push_back(VE[1].at(i));
		referencias[2].push_back(VE[2].at(i));
	}

	VE[0].clear();
	VE[1].clear();
	VE[2].clear();
	inR2 = new ioVect(referencias,3);

	system("killall -9 Plotter.exe");
	sleep(1);
	outU->send(0,0);
	control->startController(false,inR2,inY,outU);

	
	
	csvExport(timeBase,referencias,3,VE,3);	
	
	
	//~ 
	//~ /// genero la aplicacion Qt
	QApplication app(argc,argv);
	//~ /// ventana principal y el handler
	//~ handler = new guiHandler();
	//~ window = new mainWindow();
	//~ window->show();
	//~ 
	//~ return app.exec();
}
