#include <stdio.h>
#include <unistd.h>
int main()
{
pid_t  pid;
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
                printf("\nParent Process is executing\n");
                printf("Parent Process ID is %d\n" , getpid());
                printf("It's Parent Process ID is %d\n" , getppid());//ID of the parent’s parent process is the ID of the shell owned by us currently
                printf("pid variable in parent process is %d\n", pid);
        }
        return 0;
}
