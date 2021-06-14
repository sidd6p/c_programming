#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main ()
{
pid_t child_pid;
child_pid = fork ();
if (child_pid > 0) {
    printf("Parent start\n");
    sleep (600);
    printf("Parent complete\n");
}
else {
    printf("Child start\n");
    //exit (0);//not needed
    printf("child complete\n");
}
return 0;
}
