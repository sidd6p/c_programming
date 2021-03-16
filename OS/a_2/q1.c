#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
  int i = 0;
  printf("Example to show execl() call\n");
  //printf("Example to show system() call\n");
  execlp("/bin/ls", "ls","-l",  NULL);
  //system("ls -l");
  //printf("This line will get execute, even it is after system() call\n");
  printf("This line will not get execute, as it is after execl()\n");

return 0;
}
