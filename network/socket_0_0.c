//SERVER
#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define MAX 80
#define PORT 43457
#define SA struct sockaddr
void func(int sockfd){
    int buff[MAX];
    int n;
    for(;;){
        int avg = 0;
        int i = 0;
        bzero(buff,MAX);
        read(sockfd,buff,sizeof(buff));
        if(buff[0] == '\0'){
            printf("server exit\n");
            break;
        }
        printf("From client\n");
        for(i = 0; i < 3; i++){
            printf("%d\t", buff[i]);
        }
        printf("\n");
        //putchar(buff[0]);
        printf("\nEnter the string \n");
        for(i = 0; i < 3; i++){
            avg = avg + buff[i];
        }
        avg = avg / 3;
        printf("\n average is %d\n", avg);
       // printf("From client: %d\t To client : ",buff[0]);
        bzero(buff,MAX);
        n=0;
        buff[0] = avg;
        //while((buff[n++]=getchar())!='\n');
        write(sockfd,buff,sizeof(buff));
        /*if(strncmp("exit",buff,4)==0){
            printf("Server Exit...\n");
            break;
        }*/
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
        printf("Listen failed...\n");
        exit(0);
    }
    else
    printf("Server listening..\n");
    len=sizeof(cli);
    connfd=accept(sockfd,(SA *)&cli,&len);  
    if(connfd<0){
        printf("server acccept failed...\n");
        exit(0);
    }
    else
    printf("server acccept the client...\n");
    func(connfd);
    close(sockfd);
}
