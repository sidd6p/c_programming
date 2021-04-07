#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main() {
        int pid;
        int fd[2];//one for read end and on e for write end
        pipe(fd);
        pid=fork();

	if( pid < 0 ) {
		perror( "fork");
		exit( -1 );
	}

        if( pid==0) {

                close(1);//no need to write to stdout
                dup (fd[1]);
                close(fd[0]);
                close(fd[1]);
                execl("/usr/bin/ls","ls", "-l",NULL);

        }
        else {
                close(0);//no need to read from stdin
                dup (fd[0]);
                close(fd[0]);
                close(fd[1]);
                execl("/usr/bin/grep","grep", ".c$" ,NULL);
        }
}

