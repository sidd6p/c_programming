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
 
    mqDesc = mq_open( queueName, O_RDWR|O_CREAT, 0660, NULL);
    if(  mqDesc == -1 )
    {
        perror( "mq_open ");
        exit( -1 );
    }
strcpy(msg, "Hello World");
    if(  mq_send(mqDesc, msg, strlen(msg), 0) == -1 )
    {
        perror( "mq_send" );
        exit( -1 );
    }
 
    else
    {
        printf( "%s\n", "Message is sent successfully");
    }
 
    return 0;
}