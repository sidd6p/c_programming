#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
        pid_t pid;
        int pipeDesc[2];
//      char msg1[50], msg2[50];
//      strcpy (msg1, "Hello");
        if (pipe( pipeDesc ) < 0 ) {
                perror( "pipe" );
                exit( -1 );
        }
        pid = fork();
        if ( pid > 0 ) {
                close( 1 );
                dup( pipeDesc[1] ) ;
                close( pipeDesc[0]);
                close(pipeDesc[1] );
                execl("/bin/ls", "ls", "-l", NULL);
                }
        else
        {
                printf("in child");
                close( 0 );
                dup ( pipeDesc [0]);
                close(pipeDesc[1]);
                close(pipeDesc[0]);
                execl("/bin/grep", "grep","a.out",  NULL);
        }
        return 0;
}
