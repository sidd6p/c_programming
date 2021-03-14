//https://pubs.opengroup.org/onlinepubs/7908799/xsh/unistd.h.html
#include<unistd.h>
#include<stdio.h>
int main(){
  printf("Hello earth before fork");
  fflush(stdout);//uncomment if not usinf \n in last stdout
  fork();
  printf("\nAfter fork\n");
  return 0;
}
