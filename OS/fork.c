//https://pubs.opengroup.org/onlinepubs/7908799/xsh/unistd.h.html
#include<unistd.h>
#include<stdio.h>
int main(){
  int i = 0;
  printf("Fork example\n");
  printf("Hello earth before fork");
  fflush(stdout);//uncomment if not using \n in last stdout
  fork();
  i++;
  printf("\nAfter fork, i = %d\t", i);
  printf("\n");
  return 0;
}
