#ifndef PLOTDATA_H
#define PLOTDATA_H

#include <qwt_series_data.h>
#include <QPointF>
#include <vector>



class SeriesData: public QwtSeriesData<QPointF>
{
	
	public:

		size_t size() const {
			return x->size();  
		}

		QRectF boundingRect() const { 
			double Ymax = 0;
			for ( uint i = 0; i < y->size(); i++) {
				if ((*y)[i] > Ymax )
					Ymax = (*y)[i];
			}
			if ( x->size() > 0 )
				return QRectF(0,0,x->back() , Ymax);
			else 
				return QRectF(0,0,1,1);
		}

		QPointF sample(size_t i) const {
			if ( x->size() > 0 )
				return QPointF( (*x)[i], (*y)[i] ); 
			else return QPointF(0,0);
		};

		SeriesData( std::vector<double> *_x, std::vector<double> *_y )
			: QwtSeriesData<QPointF>()  {
			x= _x;
			y= _y;
		}
		
		
	private:
		std::vector<double> *x,*y;
		//~ double Y_max;
};

#endif /* PLOTDATA_H */ 
