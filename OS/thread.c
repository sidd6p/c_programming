//https://www.geeksforgeeks.org/thread-functions-in-c-c/
//experiment with fork and thread on data sharing
#include <stdio.h>
#include <pthread.h>

int i = 2; // Global variable:

void * function1(void * arg){
  printf("Thread 1 is executing....it %lu\n", pthread_self());
}

void * stringLength(void * msg){
   char *message = (char *)msg;
   int len = 0;
   while(message[len++]);
   printf("Length of string is %d\n", len);
}

void* foo(void* p){
  // Print value received as argument:
   int *num = (int *)p;
  printf("Value recevied as argument in starting routine: ");
  printf("%d\n", *num);
  i = ++(*num);
  pthread_exit(&i);   // Return reference to global variable:
}

int main(void){
  pthread_t id;   // Declare variable for thread's ID:
  pthread_t tpid[2];
  int j, k;
  char message[25] = "Hello";
  j = k = 1;

  pthread_create(&id, NULL, foo, &j);
  k = pthread_create(&tpid[0], NULL, function1, NULL);
  pthread_create( &tpid[1], NULL, stringLength, &message);

  if(k == 0){
      pthread_join(tpid[0], NULL);
  }
  else{
    perror("tpid[0] not created");
  }
  pthread_join(tpid[0], NULL);
  int* ptr;
  pthread_join(id, (void**)&ptr); // Wait for foo() and retrieve value in ptr;
  printf("Value recevied by parent from child: ");
  printf("%i\n", *ptr);
  printf("\n main thread is about to terminte\n");
  return 0;
}
