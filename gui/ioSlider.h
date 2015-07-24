#ifndef IOSLIDER_H
#define IOSLIDER_H

#include <ioif/ioIF.h>

#include <QSlider>

class ioSlider: public ioIF
{
	public:
		ioSlider(QSlider *ref):slider(ref){};
		
		virtual int recv(double *dest,uint qty){
				dest[0] = slider->value()/1000.0;
				dest[1] = 0.0;
				dest[2] = 0.0;
				
			return sizeof(double)*qty;
		}
		virtual uint size(void){
			return 1;
		}
	private:
		QSlider *slider;
};

#endif /* IOSLIDER_H */ 
