#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
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
                usleep(2000000);//child will be sleeping for 1 seconds
                //if child is sleeping then parents will get execute and will get terminate causing child as orphan child.
                printf("\nChild Process is executing\n");
                printf("Child Process ID is %d\n" , getpid());
                printf("It's Parent Process ID is %d\n" , getppid());//this will give the ID of the shell owned by us currently
                //getppid() = 1 means that the orphan is get adopted by the init process
                printf("pid variable in child process is %d\n", pid);
                printf("\n..........................\n\n");

        }
        else
        {
                printf("\nParent Process is executing\n");
                printf("Parent Process ID is %d\n" , getpid());
                printf("It's Parent Process ID is %d\n" , getppid());
                printf("pid variable in parent process is %d\n", pid);
                return 0;
        }
        return 0;
}
