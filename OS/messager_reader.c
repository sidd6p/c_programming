#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h> 
#include <string.h> 
#include <stdio.h>  
#include <stdlib.h> 
 
int main(  )
{
    mqd_t mqDesc = -1;
    char msg[128];
    char *queueName = "/test";
 
    mqDesc = mq_open( queueName, O_RDONLY|O_CREAT, 0660, NULL);
    if(  mqDesc == -1 )
    {
        perror( "mq_open ");
        exit( -1 );
    }
    mq_receive(mqDesc, msg, 1000, 0) ;
    printf("Received message is %s", msg);
 
    return 0;
}