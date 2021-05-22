#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>//for using sin function for generating buffer data

#define total_producer 2
#define total_consumer 2
#define Buffer 5

sem_t empty; //keep track of the number of empty spots
sem_t full; //keep track of the number of full

int in = 0; //buffer[in%Buffer] is the first empty position
int out = 0; //buffer[out%Buffer] is the first empty position
int buffer[Buffer]; //shared buffer 
pthread_mutex_t mutex; //for ensuring mutual exclusion to shared data

void *producer(void *arg){   
        int data;
        for(int i = 0; i < Buffer; i++, in = (in + 1) % Buffer){
            data = (int)((sin((i + 9) * (i * 11))) * 100) ; // Produce an random integer
            sem_wait(&empty);//s = s - 1
            pthread_mutex_lock(&mutex);
            //critical section starts
            buffer[in] = data;
            printf("Producer %d writing data %d at position %d\n", i + 1, buffer[in],in);
            //ctitical section ends 
            pthread_mutex_unlock(&mutex);
            sem_post(&full);// s = s + 1
        }
        pthread_exit(NULL);
}

void *consumer(void *arg){   
    for(int j = 0; j < Buffer; j++, out = (out + 1) % Buffer){
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        //critical section starts
        int item = buffer[out];
        printf("\t\t\t\t\tConsumer %d reading data %d from position %d\n",j + 1, item, out);
         //critical section ends
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
    pthread_exit(NULL);
}

int main(){   
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, Buffer);
    pthread_t prod[total_producer], cons[total_consumer];
    pthread_mutex_init(&mutex, NULL);
    for(int p = 0; p < total_producer; p++){
        if(pthread_create(&prod[p], NULL, (void *)producer, NULL)){
            perror("Producer thread");
            exit(-1);
            }
    }
    for(int c = 0; c < total_consumer; c++){
        if(pthread_create(&cons[c], NULL, (void *)consumer, NULL)){
            perror("Consumer thread");
            exit(-1);
            }
    }
    for(int p = 0; p < total_producer; p++){
        pthread_join(prod[p], NULL);
    }
    for(int c = 0; c < total_consumer; c++){
        pthread_join(cons[c], NULL);
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;    
}