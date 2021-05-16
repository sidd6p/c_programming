#include <fcntl.h>//file control options, For O_* constants 
#include <sys/stat.h> //data returned by the stat() function, For mode constants 
#include <mqueue.h>//message queues (REALTIME), this also contain <fcntl.h> 
#include <string.h> 
#include <stdio.h>  
#include <stdlib.h> 
 
int main(){
    mqd_t mqDesc_w = -1; //In the QNX implementation, an mqd_t is a file descriptor.
     char msg_w[128];
    char *queueName = "/mq";
    bzero(msg_w, strlen(msg_w));
    mqDesc_w = mq_open(queueName, O_RDWR|O_CREAT, 0660, NULL);// mqd_t mq_open(const char *name, int oflag, mode_t mode, struct mq_attr *attr);
    if(mqDesc_w == -1){
        perror("mq_open");
        exit( -1 );
    }
    strcpy(msg_w, "Hello World");
    if(mq_send(mqDesc_w, msg_w, strlen(msg_w) + 1, 0) == -1){//int mq_send(mqd_t mqdes, const char *msg_ptr, size_t msg_len, unsigned int msg_prio);
        perror("mq_send");
        exit(-1);
    } 
    else{
        printf("Length of message is %ld\n", strlen(msg_w));
        printf("%s\n", "Message is sent successfully");
    } 
    bzero(msg_w, strlen(msg_w));
    return 0;
}


/*The mqueue.h header defines the mqd_t type, which is used for message queue descriptors.
This will not be an array type.
A message queue descriptor may be implemented using a file descriptor, in which case applications can open up to at least OPEN_MAX file and message queues.*/

/*In the QNX implementation, an mqd_t is a file descriptor.
Like pipes and FIFOs, all message queue operations are performed based on message queue descriptors (an mqd_t).
Thus, in addition to the POSIX message queue API, the programmer may call almost any I/O routine that takes a file descriptor.*/

/*mqd_t mq_open(const char *name, int oflag, mode_t mode, struct mq_attr *attr);
The mode argument specifies the permissions to be placed on the new queue
Chmod 660 (chmod a+rwx,u-x,g-x,o-rwx) sets permissions so that,
(U)ser / owner can read, can write and can't execute.
(G)roup can read, can write and can't execute. 
(O)thers can't read, can't write and can't execute.
The fields of the struct mq_attr pointed to attr specify the
maximum number of messages and the maximum size of messages that
the queue will allow.
If attr is NULL, then the queue is created with implementation-
defined default attributes.*/

/*mq_send() adds the message pointed to by msg_ptr to the message
queue referred to by the message queue descriptor mqdes.  The
msg_len argument specifies the length of the message pointed to
by msg_ptr; this length must be less than or equal to the queue's
mq_msgsize attribute.  Zero-length messages are allowed.
The msg_prio argument is a nonnegative integer that specifies the
priority of this message.  Messages are placed on the queue in
decreasing order of priority, with newer messages of the same
priority being placed after older messages with the same
priority.*/