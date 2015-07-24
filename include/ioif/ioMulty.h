#ifndef __IOMULTY_H__
#define __IOMULTY_H__

#include <ioif/ioIF.h>
#include <thread>


class ioMulty : public ioIF {
	public:
		ioMulty(ioIF *out1, ioIF *out2, ioIF *out3=0, ioIF *out4=0, ioIF *out5=0){
			ioIF *vect[5] = {out1,out2,out3,out4,out5};
			for (int i = 0; i < 5; i++)	{
				
				if ( vect[i] == 0 ) break;
				
				outputs.push_back(vect[i]);
			}
		
		}
		~ioMulty(){
			outputs.clear();
		}
		virtual int send(double *src,uint qty) {
			for ( uint i = 0; i < outputs.size(); i++ )
				outputs[i]->send(src,qty);
			
			return 0;
		}
				
		
			
	private:
		vector<ioIF *>  outputs;	
};
#endif
