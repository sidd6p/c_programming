#include<stdio.h>
#define MAXLINE 1000
int getlines(char line[], int max);
int strindex(char source[], char searchfor[]);
void strindex_modified(char source[], char searchfor[]);
void null_return();
int test_retunr();

char pattern[] = "ould";
char output_string[MAXLINE];
static int index = 0;

int main(){
  int i = 100;
  char line[MAXLINE];
  int found = 0;
  while(getlines(line, MAXLINE) > 0){
  /*  if(strindex_modified(line, pattern) >= 0){
      printf("%s", line);
      found++;
    }*/
    strindex_modified(line, pattern);
  }
  output_string[index] = '\0';
  printf("%s", output_string);
//  i = null_return();
  //printf("%d", i);
  printf("%d", test_retunr());
  return 0;
}

int getlines(char s[], int lim){
  int c, i;
  i = 0;
  while(--lim > 0 && (c=getchar()) != EOF && c != '\n'){
    s[i++] = c;
  }
    if(c == '\n'){
      s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

int strindex(char s[], char t[]){
  int i, j , k;
  for(i = 0; s[i] != '\0'; i++){
    for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++){
      ;
    }
    if(k > 0 && t[k] == '\0'){
      return i;
    }
  }
  return -1;
}

void strindex_modified(char source[], char searchfor[]){
  int i, j, k;
  i = j = k = 0;
  for(i; source[i] != '\0'; i++){
    for(j = i, k = 0; searchfor[k] == source [j]; j++, k++){
      ;
    }
    if((k != 0) && (searchfor[k] == '\0')){
      i = 0;
      do{
        output_string[index] = searchfor[i];
        i++;
        index++;
      }while(source[i] != '\0');
      return ;
    }
  }
}

void null_return(){
  return ;//retunr value will be 0, but it depends on the OS
}

int test_retunr(){
  return 13.2;//this will get converted into int
}
