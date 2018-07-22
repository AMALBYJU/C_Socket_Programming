//UDP Client

#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<netdb.h>

void main()
{
 int ser,sent,received;
 struct sockaddr_in server;
 socklen_t addrlen;
 char msg[] = "Hello server";
 char buf[70];
 addrlen = sizeof(struct sockaddr);
 
 if((ser = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP)) == -1)
 {
  perror("socket");
  exit(1);
 }
 
 server.sin_family = AF_INET;
 server.sin_port = htons(10110);
 server.sin_addr.s_addr = inet_addr("127.0.0.1");
 bzero(&server.sin_zero,8);
 
 sent = sendto(ser,msg,strlen(msg),0,(struct sockaddr*)&server,addrlen);
 printf("Sent %d bytes to server\n",sent);
 received = recvfrom(ser,buf,70,0,(struct sockaddr*)&server,&addrlen);
 printf("Message = %s\nReceived %d bytes from server\n",buf,received);
 close(ser);
}
