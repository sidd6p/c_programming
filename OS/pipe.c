#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
  pid_t pid;
  int pipe_desc[2];
  char mes1[50], mes2[50];
  strcpy(mes1, "Hello");
  if(pipe(pipe_desc) < 0){
    perror("Pipe");
    exit(-1);
  }
  if((pid = fork()) < 0){
    perror("Fork");
    exit(-1);
  }
  if(pid > 0){
    close(pipe_desc[0]);
    write(pipe_desc[1], mes1, strlen(mes1) + 1);
    printf("\nparent writing: %s\n", mes1);

  }
  else{
    close(pipe_desc[1]);
    read(pipe_desc[0], mes2, sizeof(mes2));
    printf("\n child read: %s\n", mes2);
  }
  return 0;
}
