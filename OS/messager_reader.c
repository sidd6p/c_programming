#include <stdio.h>
#include <stdlib.h>//exit()
#include <string.h>//bzero() and strlen()
#include <mqueue.h>
#include <errno.h>
//#include <sys/types.h>
//#include <unistd.h>
//#include <fcntl.h>
//#include <sys/stat.h>

int main(){
    mqd_t mqDesc_r = -1;
    char msg_r[128];
    char *queueName = "/mq";
    mqDesc_r = mq_open(queueName, O_RDONLY, 0660, NULL);
    if(mqDesc_r == -1){
        perror("mq_open");
        exit(-1);
    }
    bzero(msg_r, strlen(msg_r));
    if((mq_receive(mqDesc_r, msg_r, 10000, 0)) == -1){//ssize_t mq_receive(mqd_t mqdes, char *msg_ptr,  size_t msg_len, unsigned int *msg_prio);
        perror("Message received");
    }
    printf("Length of message is %ld\n", strlen(msg_r));
    printf("Received message is %s\n", msg_r); 
    bzero(msg_r, strlen(msg_r));
    return 0;
}

/* ssize_t mq_receive(mqd_t mqdes, char *msg_ptr,  size_t msg_len, unsigned int *msg_prio);
       mq_receive() removes the oldest message with the highest priority
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