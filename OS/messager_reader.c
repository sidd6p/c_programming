#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h> 
#include <string.h> 
#include <stdio.h>  
#include <stdlib.h> 
 
int main(){
    mqd_t mqDesc = -1;
    char msg[128];
    char *queueName = "/test"; 
    mqDesc = mq_open(queueName, O_RDONLY|O_CREAT, 0660, NULL);
    if(mqDesc == -1){
        perror("mq_open");
        exit(-1);
    }
    mq_receive(mqDesc, msg, 1000, 0);// ssize_t mq_receive(mqd_t mqdes, char *msg_ptr,  size_t msg_len, unsigned int *msg_prio);
    /* mq_receive() removes the oldest message with the highest priority
       from the message queue referred to by the message queue
       descriptor mqdes, and places it in the buffer pointed to by
       msg_ptr.  The msg_len argument specifies the size of the buffer
       pointed to by msg_ptr; this must be greater than or equal to the
       mq_msgsize attribute of the queue (see mq_getattr(3)).  If
       msg_prio is not NULL, then the buffer to which it points is used
       to return the priority associated with the received message.

       If the queue is empty, then, by default, mq_receive() blocks
       until a message becomes available, or the call is interrupted by
       a signal handler.  If the O_NONBLOCK flag is enabled for the
       message queue description, then the call instead fails
       immediately with the error EAGAIN.*/
    printf("Received message is %s\n", msg); 
    return 0;
}