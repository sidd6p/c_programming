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
#include<signal.h>
#define MAX 10000
#define PORT 43442
#define SA struct sockaddr

void handle_sigint(int sig){// if client wnats to end from its side
    printf("\tClient exit....\n");
    exit(0);
}

void func(int sockfd){
    char buff[MAX];
    int n;
    for(;;){
        signal(SIGINT, handle_sigint);
        int i = 0;
        bzero(buff,sizeof(buff));
        printf("Enter the Message to sERVER : ");
        n=0;
        fflush(stdin);
        fgets(buff, MAX, stdin);
        write(sockfd,buff,sizeof(buff));
        bzero(buff,sizeof(buff));
        read(sockfd,buff,sizeof(buff));
        if(buff[0] == '\0'){//if server exit from its side
            printf("server exit\n");
            break;
        }
        printf("Message From SERVER :\t %s\n",buff);
        bzero(buff,MAX);
    }
}


int main(){
    int sockfd;
    struct sockaddr_in servaddr_c;
    if((sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1){ 
        perror("socket creation failed...");
        exit(-1);
    }
    else{
    printf("Socket successfully created..\n");
    }
    bzero(&servaddr_c,sizeof(servaddr_c));
    servaddr_c.sin_family=AF_INET;
    servaddr_c.sin_addr.s_addr=inet_addr("127.0.0.1");
    servaddr_c.sin_port=htons(PORT);
    if(connect(sockfd,(SA *)&servaddr_c,sizeof(servaddr_c)) != 0){
        perror("connection with the server failed...");
        exit(-1);
    }
    else
    printf("connected to the server..\n");
    func(sockfd);
    close(sockfd);
}

