#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAXCHARACTER 256

int anagram_check();
int isomorphic_check();

int anagram_check(){
  fflush(stdin);
  fflush(stdout);
  int c, ncharcte1[MAXCHARACTER], ncharcte2[MAXCHARACTER], i;
  i = 0;
  for(i; i < MAXCHARACTER; i++){
    ncharcte1[i] = ncharcte2[i] = 0;
  }
    printf("Enter first string\n");
    fflush(stdin);
    while((c = getchar()) != '\n'){
      ncharcte1[c - '0']++;
    }
    printf("Enter second string\n");
    fflush(stdin);
    while((c = getchar()) != '\n'){
      ncharcte2[c - '0']++;
    }
    for(i = 0; i < MAXCHARACTER; i++){
      if(ncharcte1[i] != ncharcte2[i]){
        return 0;
      }
    }
    return 1;
}

int isomorphic_check(){
  fflush(stdin);
  fflush(stdout);
  int c, ncharcte1[MAXCHARACTER], ncharcte2[MAXCHARACTER], i;
  i = 0;
  for(i = 0; i < MAXCHARACTER; i++){
    ncharcte1[i] = ncharcte2[i] = 0;
  }
    printf("Enter first string\n");
    fflush(stdin);
    while((c = getchar()) != '\n'){
      ncharcte1[c - '0']++;
    }
    printf("Enter second string\n");
    fflush(stdin);
    while((c = getchar()) != '\n'){
      ncharcte2[c - '0']++;
    }
    for(i = 0; i < MAXCHARACTER; i++){
      for(int j = 0; j < MAXCHARACTER; j++){
        if(ncharcte1[i] == ncharcte2[j]){
          ncharcte1[i] = ncharcte2[j] = 0;
          break;
        }
      }
    }
    for(i = 0; i < MAXCHARACTER; i++){
      if((ncharcte1[i] != 0) || (ncharcte2[i] != 0)){
        return 0;
      }
    }
    return 1;

}


int main()
{
pid_t  pid;
        pid = fork();
        if (pid < 0) {
                fprintf(stderr, "Fork Failed");
                return 1;
        }
        else if (pid == 0) {
                printf("\nChild Process is executing isomorphic\n");
                if(isomorphic_check()){
                  printf("Given string are isomorphic\n");
                }
                else{
                  printf("Given string are not isomorphic\n");
                }
        }
        else
        {
          wait(NULL);
                printf("\nParent Process is executing anagram\n");
                if(anagram_check()){
                  printf("Given string are anagram\n");
                }
                else{
                  printf("Given string are not anagram\n");
                }

        }
        return 0;
}
