//SERVER
#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#define MAX 10000
#define PORT 43442
#define SA struct sockaddr
void handle_sigint(int sig){// server wants to end from its side
    printf("\tSever exit....\n");
    exit(0);
}

void func(int sockfd){
    char buff[MAX];
    int n;
    for(;;){
        signal(SIGINT, handle_sigint);
        int avg = 0;
        int i = 0;
        bzero(buff,MAX);
        read(sockfd,buff,sizeof(buff));
        if(buff[0] == '\0'){//if client from its side
            printf("server exit\n");
            break;
        }
        printf("Message from the client: \t");
        printf("%s", buff);
        printf("\n");
        bzero(buff,MAX);
        printf("\nEnter the Message to CLIENT:  \t");
        fgets(buff, MAX , stdin);
        write(sockfd,buff,sizeof(buff));
    }
}
int main(){
    int sockfd,connfd,len;
    struct sockaddr_in servaddr,cli;
    sockfd=socket(AF_INET,SOCK_STREAM,0);
        if(sockfd == -1){
        perror("socket creation failed...");
        exit(-1);
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
        perror("Listen failed...");
        exit(-1);
    }
    else
    printf("Server listening..\n");
    len=sizeof(cli);
    connfd=accept(sockfd,(SA *)&cli,&len);  
    if(connfd<0){
        perror("server acccept failed...");
        exit(-1);
    }
    else
    printf("server acccept the client...\n");
    func(connfd);
    close(sockfd);
}
