//https://pubs.opengroup.org/onlinepubs/7908799/xsh/unistd.h.html
// The <unistd.h> header defines miscellaneous symbolic constants and types, and declares miscellaneous functions.
/*fflush()
Is is typically used for output stream only.
its purpose is to clear (or flush) the output buffer
and move the buffered data to console (in case of stdout)
or disk (in case of file output stream).*/
#include<unistd.h>
#include<stdio.h>
int main(){
  int status = 0;
  printf("Hello earth before fork");
  //printf("Hello earth before fork\n");
  //fflush(stdout);
  fork();
  //printf("Hello earth after fork\n");
  //printf("\n\n");
  //printf("Before fork()\n");
//status = fork();
//  printf("after fork()\n");
//  printf("%d\n", status);
//  printf("Getting id %d\n", getppid());
//    printf("Getting id %d\n", getpid());
  //fork();
  printf("More than one fork\n");
  return 0;
}
