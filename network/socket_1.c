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
void func(int sockfd){
    char buff[MAX];
    int n;
    for(;;){
        bzero(buff,sizeof(buff));
        printf("Enter the string : ");
        n=0;
        while((buff[n++]=getchar())!='\n');
        write(sockfd,buff,sizeof(buff));
        bzero(buff,sizeof(buff));
        read(sockfd,buff,sizeof(buff));
        printf("From Server : %s",buff);
        if((strncmp(buff,"exit",4))==0){
            printf("Client Exit...\n");
            break;
        }
    }
}

int main(){
    int sockfd;
    struct sockaddr_in servaddr_c;
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd==-1){
        printf("socket creation failed...\n");
        exit(0);
    }
    else
    printf("Socket successfully created..\n");
    bzero(&servaddr_c,sizeof(servaddr_c));
    servaddr_c.sin_family=AF_INET;
    servaddr_c.sin_addr.s_addr=htonl(INADDR_ANY);//inet_addr("127.0.0.1");
    servaddr_c.sin_port=htons(PORT);
    if(connect(sockfd,(SA *)&servaddr_c,sizeof(servaddr_c))!=0){// int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    /*The connect() system call connects the socket referred to by the
       file descriptor sockfd to the address specified by addr.  The
       addrlen argument specifies the size of addr.  The format of the
       address in addr is determined by the address space of the socket
       sockfd; see socket(2) for further details.
*/
        printf("connection with the server failed...\n");
        exit(0);
    }
    else
    printf("connected to the server..\n");
    func(sockfd);
    close(sockfd);
}

