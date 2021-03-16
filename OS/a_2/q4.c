#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
pid_t  pid;int status;
        pid = fork();
        if (pid < 0) {
                fprintf(stderr, "Fork Failed");
                return 1;
        }
        else if (pid == 0) {
                printf("\nChild Process is executing\n");
                printf("Child Process ID is %d\n" , getpid());
                printf("It's Parent Process ID is %d\n" , getppid());
                printf("pid variable in child process is %d\n", pid);
                printf("\n..........................\n\n");
            }
        else
        {
          //wait(NULL);
          //parent will not wait for the child temination status and child PCB will be maintained leaving it as zombie proess
          while(1);//this will never give the chance to parent process to delete entry of child in PCB.
                printf("\nParent Process is executing\n");
                printf("Parent Process ID is %d\n" , getpid());
                printf("It's Parent Process ID is %d\n" , getppid());
                printf("pid variable in parent process is %d\n", pid);
                return 0;
        }
        return 0;
}
