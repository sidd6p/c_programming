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
#define MAX 80
#define PORT 43457
#define SA struct sockaddr

void handle_sigint(int sig){
    printf("\tClient exit....\n");
    exit(0);
}

void func(int sockfd){
    int buff[MAX];
    int n;
    for(;;){
        signal(SIGINT, handle_sigint);
        int i = 0;
        bzero(buff,sizeof(buff));
        printf("Enter the string : ");
        n=0;
        for(i = 0; i < 3; i++){
            scanf("%d", &buff[i]);
        }
        //while((buff[n++]=getchar())!='\n');
        write(sockfd,buff,sizeof(buff));
        bzero(buff,sizeof(buff));
        read(sockfd,buff,sizeof(buff));
        if(buff[0] == '\0'){
            printf("server exit\n");
            break;
        }
        printf("From server AVERAGE is %d\n", buff[0]);
       /* for(int i = 0; i < 2; i++){
            printf("%d\t", buff[i]);
        }
        printf("\n");*/
        //putchar(buff[0]);
        /*if((strncmp(buff,"exit",4))==0){
            printf("Client Exit...\n");
            break;
        }*/
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

