//SERVER
#include<stdio.h>
#include<netinet/in.h>//contains definitions for the internet protocol family
#include<sys/types.h>
#include<sys/socket.h>//it contain sockaddr
#include<netdb.h>//htonl and htons are present in it
#include<stdlib.h>
#include<string.h>//bzero is present in it
#include<unistd.h>
#define MAX 400
#define PORT 43459
#define SA struct sockaddr
void func(int sockfd){
    printf("\nPress a key to process:");
    fflush(stdin);
    fflush(stdout);
    getchar();
    fflush(stdin);
    fflush(stdout);
    int buff[MAX];
    int n;
    int test = 0;
    int avg = 0;
    int num = 0;
    int next = 0;
    for(;next == 0;){
        bzero(buff,MAX);
        read(sockfd,buff,sizeof(buff));
        printf("\n");
        avg = buff[0] + buff[1] + buff[2];
        bzero(buff,MAX);
        n=0;
        buff[0] = avg;
        write(sockfd,buff,sizeof(buff));
    }
}
int main(){
    int sockfd,connfd,len;
    struct sockaddr_in servaddr,cli;
    sockfd=socket(AF_INET,SOCK_STREAM,0);
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
    if((bind(sockfd,(SA*)&servaddr, sizeof(servaddr)))!=0){
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
    if(connfd<0){
        printf("server acccept failed...\n");
        exit(0);
    }
    else
    printf("server acccept the client...\n");
    func(connfd);
    close(sockfd);
}
