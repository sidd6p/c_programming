//CLIENT
#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#define MAX 80
#define PORT 43454
#define SA struct sockaddr
int main(){
    char buff_c[MAX];
    int sock_fd,len,n;
    struct sockaddr_in servaddr_c;
    sock_fd=socket(AF_INET,SOCK_DGRAM,0);
    if(sock_fd==-1){
        printf("socket creation failed...\n");
        exit(0);
    }
    else
    printf("Socket successfully created..\n");
    bzero(&servaddr_c,sizeof(len));
    servaddr_c.sin_family=AF_INET;
    servaddr_c.sin_addr.s_addr=htonl(INADDR_ANY);//inet_addr("127.0.0.1");//The IP address 127.0.0.1 is a special-purpose IPv4 address and is called the localhost or loopback address. All computers use this address as their own, but it doesn't let computers communicate with other devices as a real IP address does.
    servaddr_c.sin_port=htons(PORT);
    len=sizeof(servaddr_c);
    for(;;){
        printf("\nEnter string : ");
        n=0;
        while((buff_c[n++]=getchar())!='\n');
        sendto(sock_fd,buff_c,sizeof(buff_c),0,(SA *)&servaddr_c,len);////ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,const struct sockaddr *dest_addr, socklen_t addrlen);
        bzero(buff_c,sizeof(buff_c));
        recvfrom(sock_fd,buff_c,sizeof(buff_c),0,(SA *)&servaddr_c,&len);////ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen);
        printf("From Server : %s\n",buff_c);
        if(strncmp("exit",buff_c,4)==0){
            printf("Client Exit...\n");
            break;
        }
    }
    close(sock_fd);
}
