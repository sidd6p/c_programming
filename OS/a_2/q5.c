#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char process_name[100];
  char kill_command[] = "pkill ";
  int status = 868;
  printf("Enter the process name to kill\n");
  scanf("%s", process_name);
  strcat(kill_command, process_name);
  status = system(kill_command);
  if(!status){
    printf("Process killed successfully\n");
  }
  else{
    printf("Process killing unsuccessfully\n");
  }
  return 0;
}
