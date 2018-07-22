//TCP Server
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
 struct sockaddr_in server,client;
 int ser,cli,sent,received;
 char buf[70];
 socklen_t socklen;
 char msg[] = "Socket Programming"; 
 socklen = sizeof(server);
 if((ser = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP)) == -1)
 {
  perror("socket");
  exit(1);
 }
 
 server.sin_family = AF_INET;
 server.sin_addr.s_addr = INADDR_ANY;
 server.sin_port = htons(10111);
 bzero(&server.sin_zero,8);
 
 if((bind(ser,(struct sockaddr*)&server,socklen)) == -1)
 {
  perror("bind");
  exit(1);
 }
 
 if((listen(ser,5)) == -1)
 {
  perror("listen");
  exit(1);
 }  
 
 if((cli = accept(ser,(struct sockaddr*)&client,&socklen)) == -1)
 {
  perror("accept");
  exit(1);
 }
 
 received = recv(cli,buf,70,0);
 printf("Message = %s\nReceived %d bytes from client\n",buf,received);
 sent = send(cli,msg,strlen(msg),0);
 printf("Sent %d bits to client\n",sent);
 close(ser);
 close(cli);
}
