//s –ef | grep username | wc –l 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){

    int p_id[2], fd_1[2], fd_2[2];
    char username[256];

    if(pipe(fd_1) == -1){
        perror("pipe");
        exit(-1);
    }
    p_id[0] = fork();
    if(p_id[0] == -1)    {
        perror("fork 1");
        exit(-1);
    }
    if(p_id[0] == 0){
        if (pipe(fd_2) == -1){
            perror("pipe");
            exit(-1);
        }
        p_id[1] = fork();
        if(p_id[1] == -1){
            perror("fork 2");
            exit(-1);
        }
        if(p_id[1] == 0){//grand child: writing to stdout
            close(fd_1[1]);
            close(fd_1[0]);
            close(fd_2[1]);
            dup2(fd_2[0],0);//to read from pipe2
            close(fd_2[0]);
            if(execl("/usr/bin/wc","wc", "-l" ,NULL) == -1){
                perror("Execl");
                exit(-1);
            }
        }
        else{//child
            close(fd_1[1]);
            dup2(fd_1[0],0);//read from pipe1
            close(fd_1[0]);
            close(fd_2[0]);
            dup2(fd_2[1],1);//writing to pipe2
            close(fd_2[1]);
            if(getlogin_r(username, 256) != 0){//for getting username
                perror("Username");
                exit(-1);
                }
            if(execl("/usr/bin/grep","grep", username ,NULL) == -1){
                perror("Execl");
                exit(-1);
            }
        }
    }
    else{//Parent process
        close(fd_1[0]);
        dup2(fd_1[1],1);//writing to pipe1
        close(fd_1[1]);
        if(execl("/usr/bin/ps","ps", "-ef",NULL) == -1){
            perror("Execl");
            exit(-1);
        }
    }  
    return 0;
}