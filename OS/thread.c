#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

/*void * function1(void * arg){
  printf("Thread 1 is executing....it %lu\n", pthread_self());
}
void * function2(void * arg){
  printf("Thread 2 is executing....it %lu\n", pthread_self());

}*/

void * stringLength(void * msg){
   char *message = (char *)msg;
   int len = 0;
   while(message[len++]);
   printf("Length of string is %d\n", len);
}
void * factorial(void * num){
  int *n=(int *) num;
  long fact = 1;
  for(int i = 1; i <= *n; i++){
    fact *= i;
  }
  printf("Factrial is %ld\n", fact);
}

int main(){
  pthread_t tpid1, tpid2;
  int n;
  char message[25];
  printf("Input an integer\n");
  scanf("%d", &n);
  printf("Input a string\n");
  scanf("%s", message);
  if(pthread_create( &tpid1, NULL, stringLength, (void*)&message) < 0){
      perror("pthread_create");
      exit(-1);
    }
    if(pthread_create( &tpid2, NULL, factorial, (void*)&n) < 0){
      perror("pthread_create");
      exit(-1);
    }
/*  if(pthread_create( &tpid1, NULL, function1, NULL) < 0){
    perror("pthread_create");
    exit(-1);
  }
  if(pthread_create( &tpid2, NULL, function2, NULL) < 0){
    perror("pthread_create");
    exit(-1);
  }*/
  pthread_join(tpid1, NULL);
  pthread_join(tpid2, NULL);
  printf("\n main thread is about to terminte\n");

  return 0;
}
