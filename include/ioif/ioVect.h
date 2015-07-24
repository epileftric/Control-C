#ifndef __IOVECT_H__
#define __IOVECT_H__

#include "ioIF.h"
#include <typedef.h>


class ioVect : public ioIF {
	public:
		ioVect(doubleVector *ent, uint n_, doubleVector *sal=0, uint m_=0){
			entrada = ent;
			n = n_;
			salida = sal;
			m = m_;
			count = 0;
		}
		virtual int recv(double *dest, uint qty){
			if ( count == entrada[0].size() )
				return -1;
			
			if ( dest && entrada != 0 ){
				for ( uint i = 0; i < n ; i++ ) {
					dest[i] = entrada[i][count];
				}	
				for( uint i = n ; i < qty ; i++ )
					dest[i] = 0.0;
				count++;
			}
			return sizeof(double) * qty;
		}

		virtual int send(double *src, uint qty){
			if ( src && qty == m && salida != 0 ){
				for ( uint i = 0 ; i < qty ; i++ ) {
					salida[i].push_back( src[i] ) ;
				}		
			}
			return sizeof(double) * qty;
		}
		virtual void clear(void){
			count = 0;
		}
		virtual uint size(void) {
			if ( entrada != 0 )
				return entrada[0].size() - count;
			return -1;
		}
				
	private:
		doubleVector *entrada;
		uint n;
		doubleVector *salida;
		uint m;
		uint count;
		
};

#endif
