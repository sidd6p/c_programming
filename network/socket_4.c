//SERVER
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
    int n,clen;
    struct sockaddr_in cli;
    clen=sizeof(cli);
    for(;;){
        bzero(buff,MAX);
        recvfrom(sockfd,buff,sizeof(buff),0,(SA *)&cli,&clen);//ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen);
        /*Parameter
        Description
        socket
        The socket descriptor.
        buffer
        The pointer to the buffer that receives the data.
        length
        The length in bytes of the buffer pointed to by the buffer parameter. If the MSG_CONNTERM flag is set, the length of the buffer must be zero.
        flags
        A parameter that can be set to 0, MSG_CONNTERM, MSG_PEEK, MSG_OOB, or MSG_WAITALL. The MSG_CONNTERM flag is mutually exclusive with other flags.
        address
        A pointer to a socket address structure from which data is received. If address is nonzero, the source address is returned.
        address_length
        Must initially point to an integer that contains the size in bytes of the storage pointed to by address. On return,
        that integer contains the size required to represent the address of the connecting socket. If this value is larger than the size supplied on input, then the information contained in sockaddr is truncated to the length supplied on input. If address is NULL, address_length is ignored.*/
        printf("From client %s To client",buff);
        bzero(buff,MAX);
        n=0;
        while((buff[n++]=getchar())!='\n');
        sendto(sockfd,buff,sizeof(buff),0,(SA *)&cli,clen);//ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,const struct sockaddr *dest_addr, socklen_t addrlen);
        /*Parameter
        Description
        socket
        The socket descriptor.
        buffer
        The pointer to the buffer containing the message to transmit.
        length
        The length of the message in the buffer pointed to by the msg parameter.
        flags
        Setting these flags is not supported in the AF_UNIX domain.
        address
        The address of the target.
        addr_len
        The size of the address pointed to by address. */
        if(strncmp("exit",buff,4)==0){
            printf("Server Exit...\n");
            break;
            }
    }
}

int main(){
    int sockfd;
    struct sockaddr_in servaddr;
    sockfd=socket(AF_INET,SOCK_DGRAM,0);
    if(sockfd==-1){
        printf("socket creation failed...\n");
        exit(0);
    }
    else
    printf("Socket successfully created..\n");
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(PORT);
    if((bind(sockfd,(SA *)&servaddr,sizeof(servaddr)))!=0){
        printf("socket bind failed...\n");
        exit(0);
    }
    else
    printf("Socket successfully binded..\n");
    func(sockfd);
    close(sockfd);
}


