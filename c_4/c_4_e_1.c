#include<stdio.h>
#define MAXLINE 1000

int getlines(char line[], int len);
int strrindex(char source[], char pattern[]);

char line[MAXLINE];
char pattern[] = "hello";

int main(){
  int len;
  len = MAXLINE;
  while(getlines(line, len) > 0){
    printf("Position is %d\n", strrindex(line, pattern));
  }
}

int getlines(char line[], int len){
  int i, c;
  i = 0;
  while(--len > 0 && (c = getchar()) != EOF && c != '\n'){
    line[i++] = c;
  }
  if(c == '\n'){
    line[i++] = '\n';
  }
  line[i] = '\0';
  return i;
}

int strrindex(char source[], char pattern[]){
  int i, j, k, pos;
  i = j = k = 0;
  pos = -1;
  for(i; source[i] != '\0'; i++){
    for(j = i, k = 0; source[j] == pattern[k]; j++, k++){
      ;
    }
    if(k != 0 && pattern[k] == '\0'){
      if(i > pos){
        pos = i;
      }
    }
  }
  return pos;
}
