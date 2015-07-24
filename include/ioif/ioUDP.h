#ifndef __IOUDP_H__
#define __IOUDP_H__

#include "ioIF.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <string.h>

typedef struct __attribute__((__packed__)) {
	unsigned char sH;
	char H[3];
	unsigned char C;
	unsigned int S;
	union {
		double U[32];
		double Y[32];
		double X[32];
	};
	unsigned char sT;
	char T[3];
} message;


class ioUDP : public ioIF  {

	public:
		ioUDP(uint local=0,uint remote=0,const char *remote_addr="127.0.0.1"){
			sockfd=socket(AF_INET,SOCK_DGRAM,0);
		
			bzero(&servaddr,sizeof(servaddr));
			   servaddr.sin_family = AF_INET;
			   servaddr.sin_addr.s_addr=inet_addr(remote_addr);
			   servaddr.sin_port=htons(remote);
			
			bzero(&cliaddr,sizeof(cliaddr));
				cliaddr.sin_family = AF_INET;
				cliaddr.sin_addr.s_addr=INADDR_ANY;
				cliaddr.sin_port=htons(local);

			int ret_val = bind ( sockfd, (const struct sockaddr*)&cliaddr, sizeof(cliaddr) );
			
			if (ret_val ){
				perror("bind");
			}
		}
		virtual ~ioUDP(){
			shutdown(sockfd,SHUT_RDWR);
		}
		
		virtual int send(double *src, uint qty ){
			message *msg= new message;
			initMsg(msg);
			
			memcpy(msg->U,src, qty*sizeof(double) );
			
			sendto( sockfd, (char*)msg, sizeof(message), 0,
								(struct sockaddr *)&servaddr,sizeof(servaddr));
			delete msg;
			return qty*sizeof(double);
		}			
		
		virtual int recv(double *dest, uint qty){
			message *msg= new message;
			
			int ret_val = (int) recvfrom( sockfd, (char*)msg, sizeof(message),MSG_PEEK,NULL,NULL);
			if ( ret_val == sizeof(message) && dest != 0 ){
				
				ret_val = (int) recvfrom( sockfd, (char*)msg, sizeof(message),MSG_WAITALL,NULL,NULL);
				memcpy(dest, msg->X, qty*sizeof(double) );
			}

			delete msg;
			
			if ( ret_val == sizeof(message) )
				return qty*sizeof(double);
			return -1;
		}
			
	private:
		void initMsg(message *msg){
			strncpy(msg->H,"ORG",3);
			msg->sH=3;
			msg->C='D';
			msg->S=0xEB90EB90;
			strncpy(msg->T,"END",3);
			msg->sT=3;
			for (int i = 0; i < 32; i++)
				msg->X[i]=0.0;
		}
		int sockfd;
		struct sockaddr_in servaddr,cliaddr;
};

#endif /* IOUDP_H */ 

