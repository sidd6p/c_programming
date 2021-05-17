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

#define MAX 400
#define PORT 43459
#define SA struct sockaddr

void func(int sockfd){
    int buff[MAX];
    int n;
    for(;;){
        printf("\nPress a key to process:");
        fflush(stdin);
        fflush(stdout);
        getchar();
        fflush(stdin);
        fflush(stdout);
        bzero(buff,sizeof(buff));//void bzero(void *s, size_t n);
        printf("\nEnter the numbers with space: ");
        n=0;
        for(int i = 0; i < 2; i++){
            scanf("%d", &buff[i]);
          }
        write(sockfd,buff,sizeof(buff));
        bzero(buff,sizeof(buff));
        read(sockfd,buff,sizeof(buff));
        printf("\nAverage is = : %f",buff[0]/3.0);
    }
}

int main(){
    int sockfd;
    struct sockaddr_in servaddr_c;

    if((sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1){ //int sockfd = socket(domain, type, protocol)
        perror("socket creation failed...");
        exit(-1);
    }
    else{
    printf("Socket successfully created..\n");
    }
    bzero(&servaddr_c,sizeof(servaddr_c));
    servaddr_c.sin_family=AF_INET;
    servaddr_c.sin_addr.s_addr=inet_addr("127.0.0.1");//htonl(INADDR_ANY)
    servaddr_c.sin_port=htons(PORT);
    if(connect(sockfd,(SA *)&servaddr_c,sizeof(servaddr_c)) != 0){// int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
        perror("connection with the server failed...");
        exit(-1);
    }
    else
    printf("connected to the server..\n");
    func(sockfd);
    close(sockfd);
}

/* int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
Parameter
Description
    sockfd
        The socket descriptor.
    add
        The pointer to a socket address structure containing the address of the socket to which a connection will be attempted.
    address_len
        The size of the socket address pointed to by address in bytes.
    The connect() system call connects the socket referred to by the
    file descriptor sockfd to the address specified by addr.  The
    addrlen argument specifies the size of addr.  The format of the
    address in addr is determined by the address space of the socket
    sockfd; see socket(2) for further details.
*/