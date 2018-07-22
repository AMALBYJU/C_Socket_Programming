//UDP Server

#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

void main()
{
 int ser,cli,received,sent;
 struct sockaddr_in server,client;
 char msg[] = "Socket Programming";
 char buf[70];
 socklen_t addrlen;
 addrlen = sizeof(server);
 if((ser = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP)) == -1)
 {
  perror("socket");
  exit(1);
 } 
 
 server.sin_family = AF_INET;
 server.sin_port = htons(10110);
 server.sin_addr.s_addr = INADDR_ANY;
 bzero(&server.sin_zero,8);
 
 if((bind(ser,(struct sockaddr*)&server,addrlen)) == -1)
 {
  perror("bind");
  exit(1);
 }
 
 received = recvfrom(ser,buf,70,0,(struct sockaddr*)&client,&addrlen);
 printf("Message = %s\nReceived %d bytes from client\n",buf,received);
 sent = sendto(ser,msg,strlen(msg),0,(struct sockaddr*)&client,addrlen);
 printf("Sent %d bytes to client\n",sent);
 close(ser);
 close(cli);
}
