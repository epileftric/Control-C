#include "UPlot.h"

QColor color[]= {Qt::red,
				 Qt::green,
				 Qt::blue,
				 Qt::cyan,
				 Qt::magenta,
				 Qt::yellow,
				 Qt::darkRed,
				 Qt::darkGreen,
				 Qt::darkBlue,
				 Qt::darkCyan,
				 Qt::darkMagenta,
				 Qt::darkYellow};
	

UPlot::UPlot(uint listen_port) {
	QwtPlot::replot();
	
	newplot = true;
	
	grid = new QwtPlotGrid;
		grid->attach(this);
		grid->enableXMin(true);
		grid->enableYMin(true);
		grid->setMajorPen( Qt::black, 0, Qt::DotLine );
		grid->setMinorPen( Qt::gray, 0 , Qt::DotLine );
	
	QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
	sizePolicy1.setHorizontalStretch(0);
	sizePolicy1.setVerticalStretch(0);
	setSizePolicy(sizePolicy1);

	
	magnifier = new QwtPlotMagnifier(this->canvas());
		magnifier->setEnabled(true);
	panner	= new QwtPlotPanner(this->canvas());
		panner->setEnabled(true);
	zoomer	= new QwtPlotZoomer(this->canvas());
		zoomer->setEnabled(false);	

	socket = new QUdpSocket();
		socket->bind(QHostAddress::LocalHost, listen_port);
	
	connect(socket,&QUdpSocket::readyRead,this,&UPlot::socketHandler);
	
}


void UPlot::clearCurves(void){
	detachItems(QwtPlotItem::Rtti_PlotCurve);
	rawData.clear();
	salidaData.clear();
	salidaCurve.clear();
}

void UPlot::clear(void){
	clearCurves();
	newplot=true;
	ploting=false;
}




void UPlot::socketHandler(void){
	uint size;
	int k=0;
	while ( socket->hasPendingDatagrams() ) {
		k++;
		if ( k == 64 ) return;
		size = socket->pendingDatagramSize();	
		if ( newplot && size >= 2*sizeof(uint)){
			
			
			
			uint aux[2];
			socket->readDatagram( (char*)aux, 2*sizeof(uint) );
			m = aux[0]; p = aux[1];
		
			N=1+m+p;
			
			//~ este es para guardar la base de tiempo
			rawData.push_back( new doubleVector() );
			
			
			for (uint i = 1; i < N; i++){
				rawData.push_back( new doubleVector() );
				salidaData.push_back( new SeriesData(rawData.at(0),rawData.at(i) ) );
				
				if ( i-1 <= m )
					salidaCurve.push_back( new QwtPlotCurve("Entrada") );
				else
					salidaCurve.push_back( new QwtPlotCurve("Salida") );
					
					salidaCurve[i-1]->setSamples(salidaData[i-1]);
					salidaCurve[i-1]->attach(this);
					salidaCurve[i-1]->setPen(color[i-1],Qt::SolidLine);
			}

			newplot=false;
			ploting=true;
			count = 0;
		}
		int pending = socket->pendingDatagramSize();
		size_t total = N*sizeof(double);
		
		if ( ploting && pending > 0) {
			
			int left = total - count;
			size_t read = left < pending ? pending : left ;
						
			char* dest = (char*) buffer;
			dest+= count;
			count += socket->readDatagram((char*)dest, read );
			
			if ( count == total ){
				for (uint i = 0; i < N; i++)
					rawData.at(i)->push_back( buffer[i] );	
			
				count = 0;
				replot();		
			}
		}
	}
	
}
