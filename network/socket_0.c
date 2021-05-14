//SERVER
#include<stdio.h>
#include<netinet/in.h>//contains definitions for the internet protocol family
#include<sys/types.h>
#include<sys/socket.h>//it contain sockaddr
//This header file contains macro definitions related to the creation of sockets, for example, the type of socket (stream, datagram, or raw), the options supported, and the address family.
//The <sys/socket.h> header file contains declarations for most of the functions that operate on sockets.
//You must include the <sys/types.h> header file before this header file. The structures in the <sys/socket.h> header file are described in the following sections.
#include<netdb.h>//This header file contains structures returned by the network database library. Internet addresses and port numbers are stored in network byte order,
//htonl and htons are present in it
#include<stdlib.h>
#include<string.h>//bzero is present in it
#include <unistd.h>
#define MAX 80
#define PORT 43454
#define SA struct sockaddr
void func(int sockfd){
    char buff[MAX];
    int n;
    for(;;){
        bzero(buff,MAX);//void bzero(void *s, size_t n);
       /*The bzero() function erases the data in the n bytes of the memory
       starting at the location pointed to by s, by writing zeros (bytes
       containing '\0') to that area.*/
        read(sockfd,buff,sizeof(buff));
        printf("From client: %s\t To client : ",buff);
        bzero(buff,MAX);
        n=0;
        while((buff[n++]=getchar())!='\n');
        write(sockfd,buff,sizeof(buff));
        if(strncmp("exit",buff,4)==0){
            printf("Server Exit...\n");
            break;
        }
    }
}
int main(){
    int sockfd,connfd,len;
    struct sockaddr_in servaddr,cli;
    /*struct sockaddr_in {
   short int            sin_family; //It represents an address family. In most of the Internet-based applications, we use AF_INET.
   unsigned short int   sin_port; //A 16-bit port number in Network Byte Order.
   struct in_addr       sin_addr; //A 32-bit IP address in Network Byte Order.
   unsigned char        sin_zero[8]; //You just set this value to NULL as this is not being used.
};*/
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    //int sockfd = socket(domain, type, protocol)
    //sockfd: socket descriptor, an integer (like a file-handle)
    //domain: integer, communication domain e.g., AF_INET (IPv4 protocol) , AF_INET6 (IPv6 protocol)
    //type: communication type
    //SOCK_STREAM: TCP(reliable, connection oriented)
    //SOCK_DGRAM: UDP(unreliable, connectionless)
    //protocol: Protocol value for Internet Protocol(IP), which is 0. This is the same number which appears on protocol field in the IP header of a packet.(man protocols for more details)
    if(sockfd == -1){
        printf("socket creation failed...\n");
        exit(0);
    }
    else
    printf("Socket successfully created..\n");
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(PORT);
    /*htons host to network short
    ntohs network to host short
    htonl host to network long
    ntohl network to host long
    long is 32 bits. short is 16 bits.*/
    if((bind(sockfd,(SA*)&servaddr, sizeof(servaddr)))!=0){
        //int bind(int socket, const struct sockaddr *addr, int address_len);
        //The bind() function binds a unique local name to the socket with descriptor socket. After calling socket(), a descriptor does not have a name associated with it.
        //If the socket descriptor socket was created in the AF_INET domain, the format of the name buffer is expected to be sockaddr_in, as defined in the include file netinet/in.h
        printf("socket bind failed...\n");
        exit(0);
    }
    else
    printf("Socket successfully binded..\n");
    if((listen(sockfd,5))!=0){
        //int listen(int sockfd, int backlog);
        printf("Listen failed...\n");
        exit(0);
    }
    else
    printf("Server listening..\n");
    len=sizeof(cli);
    connfd=accept(sockfd,(SA *)&cli,&len);//  int accept(int sockfd, struct sockaddr *restrict addr, socklen_t *restrict addrlen);
    /*The argument sockfd is a socket that has been created with
       socket(2), bound to a local address with bind(2), and is
       listening for connections after a listen(2).

       The argument addr is a pointer to a sockaddr structure.  This
       structure is filled in with the address of the peer socket, as
       known to the communications layer.  The exact format of the
       address returned addr is determined by the socket's address
       family (see socket(2) and the respective protocol man pages).
       When addr is NULL, nothing is filled in; in this case, addrlen is
       not used, and should also be NULL.

       The addrlen argument is a value-result argument: the caller must
       initialize it to contain the size (in bytes) of the structure
       pointed to by addr; on return it will contain the actual size of
       the peer address.*/
    if(connfd<0){
        printf("server acccept failed...\n");
        exit(0);
    }
    else
    printf("server acccept the client...\n");
    func(connfd);
    close(sockfd);
}
