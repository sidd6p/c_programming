#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>//file control options, For O_* constants 
#include <sys/stat.h> //data returned by the stat() function, For mode constants 
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#define MESSAGE_LENGTH 1024
pthread_mutex_t mutex1; 
void * shm_writer(void * arg){ 
 pthread_mutex_lock(&mutex1); 
 printf("Inside thread 1\n"); 
 int shm_fd_writer, len_writer; 
 void *addr_writer; 
 char msg_writer[MESSAGE_LENGTH];  int c = 0, i = 0; 
 
 shm_fd_writer = shm_open("Shm", O_RDWR | O_CREAT, 0666); 
 if (shm_fd_writer == -1){ 
 perror("shm_open"); 
 exit(-1); 
 } 
 if (ftruncate(shm_fd_writer, 1024) == -1){ 
 perror("ftruncate"); 
 exit(-1); 
 } 
 addr_writer = mmap(NULL, 1024, PROT_WRITE, MAP_SHARED, shm_fd_writer, 0); 
 if (addr_writer == MAP_FAILED){ 
 perror("mmap"); 
 exit(-1); 
 } 
 while((c = getchar()) != '\n'){ 
 msg_writer[i++] = c; 
 } 
 msg_writer[i] = '\0'; 
 printf("Message to reader is %s\n", msg_writer); 
 i = 0; 
 while((c = msg_writer[i]) != '\0'){ 
 if((c >= 65 &c <= 90)){ 
 c = c + 5; 
 if (c > 90){ 
 c = c - 81 + 65; 
 } 
 } 
 msg_writer[i++] = c; 
 } 
 msg_writer[i] = '\0'; 
 printf("Encoded Message to reader is %s\n", msg_writer); 
 len_writer = strlen(msg_writer) + 1; 
 memcpy(addr_writer, msg_writer, len_writer); 
 printf("Exiting thread 1\n\n\n"); 
 pthread_mutex_unlock(&mutex1); 
} 
 
void * shm_reader(void * arg){ 
 pthread_mutex_lock(&mutex1); 
 printf("Inside thread 2\n"); 
 int shm_fd_reader; 
 void *addr_reader; 
 char msg_reader[MESSAGE_LENGTH]; 
 int c = 0, i = 0; 
 
 shm_fd_reader = shm_open("Shm", O_RDONLY | O_CREAT, 0666); 
 if (shm_fd_reader == -1){ 
 perror("shm_open"); 
 exit(-1); 
 } 
 addr_reader = mmap(NULL, 1024, PROT_READ, MAP_SHARED, shm_fd_reader, 0); 
 if (addr_reader == MAP_FAILED){  perror("mmap"); 
 exit(-1); 
 } 
 memcpy(msg_reader, addr_reader, MESSAGE_LENGTH); 
 printf("Encoded Message from writer is %s\n", msg_reader); 
 while((c = (msg_reader[i])) != '\0'){ 
 c = c - 5; 
 msg_reader[i++] = c; 
 } 
 msg_reader[i] = '\0'; 
 printf("Dncoded Message from writer is %s\n", msg_reader); 
 printf("Exiting thread 2\n"); 
 pthread_mutex_unlock(&mutex1); 
} 
int main(void){ 
 pthread_t id[2]; // Declare variable for thread's ID:
 pthread_create(&id[0], NULL, shm_writer, NULL); 
 sleep(1); 
 pthread_create( &id[1], NULL, shm_reader, NULL); 
 pthread_join(id[0], NULL); 
 pthread_join(id[1], NULL); 
 return 0; 
} 