// https://www.tutorialspoint.com/semaphores-in-operating-system
// https://www.guru99.com/semaphore-in-operating-system.html
// https://www.geeksforgeeks.org/use-posix-semaphores-c/
// https://www.geeksforgeeks.org/semaphores-in-process-synchronization/

// C program to demonstrate working of Semaphores
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

void* thread(void* arg)
{
	//wait
	sem_wait(&mutex);
	printf("\nEntered..\n");

	//critical section
	sleep(2);

	//signal
	printf("\nJust Exiting...\n");
	sem_post(&mutex);
}


int main()
{
	sem_init(&mutex, 0, 0);
	pthread_t t1,t2;
	pthread_create(&t1,NULL,thread,NULL);
	sleep(1);
	pthread_create(&t2,NULL,thread,NULL);

    sem_destroy(&mutex);
	while(1){}
	return 0;
}

