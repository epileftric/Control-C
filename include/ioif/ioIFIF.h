#ifndef __IOIFIF_H__
#define __IOIFIF_H__

#include "ioIF.h"
#include <ioif/ioUDP.h>
#include <ioif/ioVect.h>

class ioIFIF : public ioIF {
	public: 
		ioIFIF( ioIF *in=0, ioIF *out=0 ){
			inIF = in;
			outIF = out;
		}
		virtual ~ioIFIF(){
			delete inIF;
			delete outIF;
		}
		virtual int send(double *src, uint qty ){
			if ( outIF )
				return outIF->send(src,qty);
			else
				return -1;
		}
		virtual int recv(double *dest, uint qty ){
			if ( inIF )
				return inIF->recv(dest,qty);
			else
				return -1;
		}
		
	private:
		ioIF *inIF, *outIF;
	
};


#endif
