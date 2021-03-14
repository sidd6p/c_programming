#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int main()
{

//sleep
printf("Hello earth, befor sleep\n");
sleep(1);
printf("After sleep(1)\n");
usleep(1000000);//1 microsecond = 10e-6 seconds
printf("After unsleep(1000000)\n");


//sleep in fork
pid_t  pid;
        pid = fork();
        if (pid < 0) {
                fprintf(stderr, "Fork Failed");
                return 1;
        }
        else if (pid == 0) {
          printf("Inside child\n");
          sleep(5);//if child is sleeping then parents will get execute nad will get terminate causing child as orphan child.
                printf("\nChild Process is executing\n");
                printf("Child Process ID is %d\n" , getpid());
                printf("It's Parent Process ID is %d\n" , getppid());
                printf("pid variable in child process is %d\n", pid);
                printf("\n..........................\n\n");
        }
        else
        {
          printf("Inside parent\n");
          sleep(5);//if parents is sleeping then child will get execute first and then Parent
                printf("\nParent Process is executing\n");
                printf("Parent Process ID is %d\n" , getpid());
                printf("It's Parent Process ID is %d\n" , getppid());
                printf("pid variable in parent process is %d\n", pid);
        }


return 0;
}
