#include <sys/types.h>
#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>
#include <sys/wait.h>
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
/*
//FOR MARKING CHILD ORPHAN
        else if (pid == 0) {
                printf("Inside child\n");
                printf("\nCHILD \tChild Process is executing\n");
                printf("CHILD \tChild Process ID is %d\n" , getpid());
                printf("CHILD \tIt's Parent Process ID is %d\n" , getppid());
                printf("CHILD \tpid variable in child process is %d\n", pid);
                printf("\n..........................\n\n");
                sleep(3);//if child is sleeping then parents will get execute and will get terminate causing child as orphan child.
                printf("\nCHILD \tChild Process is executing\n");
                printf("CHILD \tChild Process ID is %d\n" , getpid());
                printf("CHILD \tIt's Parent Process ID is %d\n" , getppid());
                printf("CHILD \tpid variable in child process is %d\n", pid);
                printf("\n..........................\n\n");
                printf("Child ends\n");
        }
        else
        {
                //wait(NULL);//comment wait(NULL), so that parent donot wait for child to get complete
                printf("Inside parent\n");
                sleep(1);//if parents is sleeping then child will get execute first and then Parent
                printf("\n PARENTS \tParent Process is executing\n");
                printf("PARENTS \tParent Process ID is %d\n" , getpid());
                printf("PARENTS \tIt's Parent Process ID is %d\n" , getppid());
                printf("PARENTS \tpid variable in parent process is %d\n", pid);
                printf("Parent ends \n");
                exit(-1);
        }

*/

//FOR MAKING CHILD ZOMBIE
                else if (pid == 0) {
                printf("Inside child\n");
                printf("\nCHILD \tChild Process is executing\n");
                printf("CHILD \tChild Process ID is %d\n" , getpid());
                printf("CHILD \tIt's Parent Process ID is %d\n" , getppid());
                printf("CHILD \tpid variable in child process is %d\n", pid);
                printf("\n..........................\n\n");
                }
                else
                {
                //wait(NULL);
                printf("Inside parent\n");
                sleep(5);//if parents is sleeping then child will get execute first and then Parent
                printf("\n PARENTS \tParent Process is executing\n");
                printf("PARENTS \tParent Process ID is %d\n" , getpid());
                printf("PARENTS \tIt's Parent Process ID is %d\n" , getppid());
                printf("PARENTS \tpid variable in parent process is %d\n", pid);
                printf("Parent ends \n");
                exit(-1);
        }


/*
                     // A C program to demonstrate Zombie Process.
                // Child becomes Zombie as parent is sleeping
                // when child process exits.

                        // Parent process
                        if (pid > 0)
                                sleep(5);

                        // Child process
                        else		
                                exit(0);




                else if (pid == 0) {
                        printf("Inside child\n");
                        printf("\nCHILD \tChild Process is executing\n");
                        printf("CHILD \tChild Process ID is %d\n" , getpid());
                        printf("CHILD \tIt's Parent Process ID is %d\n" , getppid());
                        printf("CHILD \tpid variable in child process is %d\n", pid);
                        printf("\n..........................\n\n");
                        exit(0);
                }
                else{
                        //wait(NULL);
                        printf("Inside parent\n");
                        sleep(1);//if parents is sleeping then child will get execute first and then Parent
                        printf("\n PARENTS \tParent Process is executing\n");
                        printf("PARENTS \tParent Process ID is %d\n" , getpid());
                        printf("PARENTS \tIt's Parent Process ID is %d\n" , getppid());
                        printf("PARENTS \tpid variable in parent process is %d\n", pid);
                        printf("Parent ends \n");
                        exit(-1);
                        }



//why child isgetting execute if while(1) is uncomment
                else if (pid == 0) {
                        printf("\nChild Process is executing\n");
                        printf("Child Process ID is %d\n" , getpid());
                        printf("It's Parent Process ID is %d\n" , getppid());
                        printf("pid variable in child process is %d\n", pid);
                        printf("\n..........................\n\n");
                        }

                else{
                        //wait(NULL);
                        //parent will not wait for the child temination status and child PCB will be maintained leaving it as zombie process
                        while(1);//this will never give the chance to parent process to  delete entry of child in PCB.
                        printf("\nParent Process is executing\n");
                        printf("Parent Process ID is %d\n" , getpid());
                        printf("It's Parent Process ID is %d\n" , getppid());
                        printf("pid variable in parent process is %d\n", pid);
                        return 0;
                        }
*/
return 0;
}
