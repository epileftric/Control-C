#include "guiHandler.h"


//~ static fullWorkQueue<guiHandler> queue(4);

guiHandler::guiHandler(){
	nt = new QNotifier();
	
	sistema->setNotifier(nt);
	control->setNotifier(nt);

	outU = new ioUDP(0,4097);
	multiU = new ioMulty( outU, new ioUDP(0,4098) );
	inU   = new ioUDP(4098,0);
	inY  = new ioUDP(4096,0);
	outY = new ioUDP(0,4102);
	inX = new ioUDP(4102,0);
	
}

void guiHandler::changeObserver( enum o_type obs ){
	complexVector poles= control->getPoles();
	poles = polyXconst(poles,10.0);
	

	switch (obs){
		case null:
			nt->reportStatus(__func__,"Controlando sin observador de estados");
			if ( observador ){
				observador->stopObserverThread();
				delete observador;
				observador=0;
			}
		break;
		
		case FullSV:
			nt->reportStatus(__func__,"Controlando con observador completo de estados");
			observador = new FullSVObs(sistema,poles,nt);
		break;
		
		case ReducedSV:
			poles.pop_back();
			nt->reportStatus(__func__,"Controlando con observador reducido de estados");
			observador = new ReducedSVObs(sistema,poles,nt);
		break;
		
		case Kalman:
			nt->reportStatus(__func__,"Filtro de Kalman no implementado todavía");
		break;		
	}
	emit reloadObserver();
}

void guiHandler::startController( bool tf , enum o_type obs ){
	if ( tf ) {
		changeObserver(obs);
		multiU->send(0,0);
		
		if ( observador ) {
			observador->startObserver(true,inU,inY,outY);
			control->startController(true,inR,inX,multiU);
		}
		else
			control->startController(true,inR,inY,outU);
	}
	else {
		control->stopControlThread();
		if ( observador ){
			observador->stopObserverThread();
		}
	}
}



void guiHandler::startSimulation(int tipo, double Tf, double To, double A, doubleVector &Xo){
	simu_param *P = new simu_param;
		P->tipo = tipo;
		P->Tf = Tf;
		P->To = To;
		P->A  = A;
		P->Xo = Xo;
	
	emit clearPlot();

	std::thread simu(&guiHandler::simulationThread,this,P);
	simu.detach();

}

void guiHandler::simulationThread(simu_param *P){
	QUdpSocket *socket = new QUdpSocket();
	socket->connectToHost(QHostAddress::LocalHost, UPLOT_LISTEN_PORT);
	
	uint m = sistema->getEntradas();
	uint p = sistema->getSalidas();

	uint vec[2]={m,p};
	socket->write( (const char* ) vec, 2*sizeof(uint) );
	
	
	double pendiente = P->A / (P->To - P->Tf );
	
	doubleVector	timeBase;
	doubleVector entrada[m];
	doubleVector salida[p];
	
	///~ genero la/s entradas:
	double Ts  = sistema->getTSample();
	uint N = ceil( P->Tf / Ts );
	
	nt->reportStatus(__func__,"Generando entradas");
	for (uint i = 0; i < N; i++) {
		if ( i % 64 == 0 )
			nt->updateProgress(__func__, 100 * i /N );

		double t = i*Ts;
		double u = 0.0;

		if ( t > P->To )
			switch ( P->tipo ){
				case signalType::escalon:
					u=P->A;
				break;
				case signalType::rampa:
					u= t-P->To;
					u*= -pendiente;
				break;				
				case signalType::parabola:
					u  = t-P->To;
					u *= u;
					u *= -pendiente;
					u *= -pendiente;
				break;
		}		
		
		timeBase.push_back(t);
		for ( uint j = 0; j < m ; j++) {
			entrada[j].push_back(u);
		}		
	}

	usleep(100000);
	nt->updateProgress(__func__, 0);
	nt->reportStatus(__func__,"Simulando el sistema");
	
	ioVect *ioif= new ioVect(entrada,m,salida,p);
	sistema->setIoIF(ioif);
	
	//~ ioIF *ioudp = new ioUDP(4097,4096);
	//~ sistema->setIoIF(ioudp);
	
	Mat Xo = vect2mat( P->Xo );
	sistema->simulate(&Xo,false);
	
	nt->updateProgress(__func__, 0);
	nt->reportStatus(__func__,"Graficando");
	for (uint i = 0; i < N; i++) {
		if ( i % 64 == 0 )
			nt->updateProgress(__func__, 100 * i /N );
		
		double send[1+m+p];
		send[0]=timeBase[i];
		
		for (uint j = 0; j < m; j++)
			send[j+1]=entrada[j].at(i);
			
		for (uint j = 0; j < p; j++)
			send[1+m+j]=salida[j].at(i);
		

		socket->write( (const char*) send, (1+m+p)*sizeof(double) );
	}
	usleep(100000);
	nt->updateProgress(__func__, 100);
	nt->reportStatus(__func__,"Simulación finalizada");
	
	
	delete socket;
	delete ioif;
	delete P;
	sistema->setIoIF(0);
}


void guiHandler::setABCD(QString A,QString B,QString C,QString D){
	QString	*lista[]={&A,&B,&C,&D};
	
	for ( int i = 0; i <= mat::D ; i++ ){
		const char *str = lista[i]->toStdString().c_str();
		Mat *matx= str2mat(str);
		sistema->setMat( static_cast<mat>(i), matx);
	}
	if ( sistema->rebuild() )
		emit reloadSystem();
}

void guiHandler::updateTs( QString str ){
	bool ok;
	double ts = str.toDouble(&ok);
	
	if ( ok ) {
		sistema->setTSample( ts );
		emit reloadSystem();
	}
}


void guiHandler::guardarPolos(QStringList *strings){
	stringstream sstr_poles;
	int n = strings->size();
	
	for (int i = 0; i < n ; i++) {
		sstr_poles << (*strings)[i].toStdString();
			sstr_poles << " ";
	}
	complexVector poles = str2poly( sstr_poles.str().c_str() );
		
	if ( control->setPoles(poles) )
		emit reloadController();
}

void guiHandler::guardarK(QString *strK){
	string str = strK->toStdString();
	Mat *newK = str2mat( str.c_str() );
	
	control->setMat( mat::k, newK );
	emit reloadController();
}
