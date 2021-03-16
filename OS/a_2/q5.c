#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>


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
                sleep(1);//child will be sleeping for 1 seconds
                printf("This line will npt get print, because parent will kill child before executing of this line\n");

        }
        else
        {
                printf("\nParent Process is executing\n");
                printf("Parent Process ID is %d\n" , getpid());
                printf("It's Parent Process ID is %d\n" , getppid());
                printf("pid variable in parent process is %d\n", pid);
                sleep(1);
                kill(pid, SIGKILL);
                return 0;
        }
        printf("parent");
        kill("myName");


        return 0;
}
