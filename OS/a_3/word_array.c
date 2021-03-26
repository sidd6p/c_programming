#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAXCHARACTER 1000
void arry_operation();
int main()
{
pid_t  pid;
        pid = fork();
        if (pid < 0) {
                fprintf(stderr, "Fork Failed");
                return 1;
        }
        else if (pid == 0) {
                printf("\nChild Process is executing\n");
                printf("Enter the sentence\n");
                arry_operation();

        }
        else
        {
          wait(NULL);//this will ot stop child from becoming orphan

                printf("\nParent Process is executing\n");

        }
        return 0;
}

void arry_operation(){
  int c, i, j, k, l, m;
  char ncharcte1[MAXCHARACTER][MAXCHARACTER];
  i = j = k = l = m = 0;
  fflush(stdin);
  while((c = getchar()) != '\n'){
    if(c == ' '){
      ncharcte1[i][j] = '\0';
          i++;
          j = 0;
          fflush(stdin);
          fflush(stdout);
    }
   ncharcte1[i][j] = c;
   j++;
}
fflush(stdin);
fflush(stdout);
printf("Printing word with length more than 4\n");
for(k = 0; k <= i; k++){
  for(l = 0; ncharcte1[k][l] != '\0'; l++){
    }
    l--;
  if(l > 4){//for printing only those aray whose length is more than 4
   for(m = 0; ncharcte1[k][m] != '\0'; m++){
     fflush(stdout);
     fflush(stdin);
     printf("%c",ncharcte1[k][m]);
     }
     m = 0;
   }
 }
}
