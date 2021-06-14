#include <stdio.h>
#include <unistd.h>//coontain execlp()
int main()
{
  /*int i = 0;
  printf("Parent is executing now.\n");
  execlp("/bin/ls", "ls","-l",  NULL);//	int execlp(const char *file, const char *arg, ...);
  printf("Value of i is %d ", i);
  printf("Not getting executed\n");*/

pid_t  pid;
       pid = fork();
        if (pid < 0) {
                fprintf(stderr, "Fork Failed");
                return 1;
        }
        else if (pid != 0) {
                printf("\nParent Process is executing\n");
                printf("Parent Process ID is %d\n" , getpid());
                printf("It's Parent Process ID is %d\n" , getppid());//ID of the parent’s parent process is the ID of the shell owned by us currently
                printf("pid variable in parent process is %d\n", pid);
                execlp("/bin/ls", "ls","-l", NULL);//why child is getting executed after exclep
                printf("Inside parent process after execlp\n");
        }
        else{
                printf("\nChild Process is executing\n");
                printf("Child Process ID is %d\n" , getpid());
                printf("It's Parent Process ID is %d\n" , getppid());
                printf("pid variable in child process is %d\n", pid);
                execlp("/bin/ls", "ls", NULL);
                printf("\n..........................\n\n");//this line will not get execute after execlp
               
        }
        //both execlp will get execute after child and parent.
        return 0;
}
