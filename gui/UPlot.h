#ifndef UPLOT_H
#define UPLOT_H

#include <QUdpSocket>
#include <iostream>
#include <vector>

#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot_panner.h>

#include <SeriesData.h>
#include <typedef.h>

#define UPLOT_LISTEN_PORT 40404

class UPlot: public QwtPlot
{
	public:
		UPlot(uint listen_port=UPLOT_LISTEN_PORT);
		~UPlot(){
			
		}
		void clear(void);
	private:

		void clearCurves(void);
		void socketHandler(void);
		
		QwtPlotMagnifier  *magnifier;
		QwtPlotZoomer 	  *zoomer;
		QwtPlotPanner	  *panner;
		QwtPlotGrid  	  *grid;
		
		uint 					m,p,N;
		vector<doubleVector*>	rawData;
		vector<SeriesData*> 	salidaData;
		vector<QwtPlotCurve*> 	salidaCurve;
			
		QUdpSocket *socket;
		
		uint 		count;
		double 		buffer[20];
		
		bool 	newplot,ploting;
		
};

#endif /* UPLOT_H */ 
