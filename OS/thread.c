//https://www.geeksforgeeks.org/thread-functions-in-c-c/
//experiment with fork and thread on data sharing
#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 


int i = 1; // Global variable:

void * function1(void * arg){
  printf("\n\nfunction1\n");
  printf("Thread 1 is executing....it %lu\n", pthread_self());
}

void * stringLength(void * msg){
  printf("\n\nstring length\n");
   char *message = (char *)msg;
   int len = 0;
   while(message[len++]);
   i = i + 10;
   //sleep(5);
   printf("value of i in stringlength is = %d\n", i);
   printf("Length of string is %d\n", len);
}

void* foo(void* p){
  //sleep(1);
  printf("\n\nfoo\n");
  // Print value received as argument:
   int *num = (int *)p;
   int k;
  printf("Value recevied as argument in starting routine: ");
  printf("%d\n", *num);
  i = i + (*num);
 // k = i + 1;//using k as return type will give garbage value.
  //sleep(3);
  printf("value of i in foo is = %d\n", i);
  pthread_exit(&i);   // Return reference to global variable:
}

int main(void){
  pthread_t id;   // Declare variable for thread's ID:
  pthread_t tpid[2];
  int j, k;
  char message[25] = "Hello";
  j = k = 5;
  int* ptr;

  pthread_create(&id, NULL, foo, &j);
  k = pthread_create(&tpid[0], NULL, function1, NULL);
  pthread_create( &tpid[1], NULL, stringLength, &message);

  pthread_join(tpid[1], NULL);
  pthread_join(id, (void**)&ptr); // Wait for foo() and retrieve value in ptr;
  pthread_join(tpid[0], NULL);
  printf("Value recevied by parent from child: ");
  printf("%i\n", *ptr);
  printf("\n main thread is about to terminte\n");
  printf("value of i is %d\n", i);
  return 0;
}


/*
  if(k == 0){
      pthread_join(tpid[0], NULL);
  }
  else{
    perror("tpid[0] not created");
  }*/