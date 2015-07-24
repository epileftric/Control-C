#ifndef __IOIF_H__
#define __IOIF_H__

class ioIF {
	public:	
		virtual ~ioIF(){};
		virtual int send(double *,uint){return 0;}
		virtual int recv(double *,uint){return 0;}
		virtual uint size(void){ return -1; }
};

#endif
