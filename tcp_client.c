//TCP Client

#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>


void main()
{
 int ser,sent,received;
 struct sockaddr_in server;
 socklen_t socklen;
 char msg[] = "Hello server";
 char buf[70];
 socklen = sizeof(server);
 if((ser = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP)) == -1)
 {
  perror("socket");
  exit(1);
 }
 
 server.sin_family = AF_INET;
 server.sin_port = htons(10111); 
 server.sin_addr.s_addr = inet_addr("127.0.0.1");
 bzero(&server.sin_zero,8);
 
 if((connect(ser,(struct sockaddr*)&server,socklen)) == -1)
 {
  perror("connect");
  exit(1);
 }
 
 sent = send(ser,msg,strlen(msg),0);
 printf("Sent %d bytes to server\n",sent);
 received = recv(ser,buf,70,0);
 printf("Message = %s\nReceived %d bytes from server\n",buf,received);
 close(ser);
}
 
 
