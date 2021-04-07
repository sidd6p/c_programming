#include <stdio.h>
#include <pthread.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAXWORD 1000000
#define MAXLETTER 30
#define READLIMIT 15

void read_data();
void process_data();
void display_data();
int check_for_palindrome_word(char, int);
int check_for_palindrome_word_default(int);
long long int index_global = 0;
long long int per_letter[26];
int total_palindorme = 0;
int data[MAXWORD][MAXLETTER];
long long int c = 0, j = 0, i = 0, length = 0, index_i = 0, o = 0;
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

void * function_0(void * index_temp){
    int *index_inside_temp = (int *)index_temp;
    int index_inside = (*index_inside_temp);
    char a[MAXLETTER];
    char b[MAXLETTER];
    int num = 0, i = 0, j = 0;
    for(i = 0; data[index_inside][i] != '\0' ;i++){
        a[i] = data[index_inside][i];
    }
    a[i] = '\0';
   for(index_inside; index_inside < o; index_inside++){
        for(j = 0; data[index_inside][j] != '\0'; j++){
            b[j] = data[index_inside][j];
        }
        b[j] = '\0';
        strrev(b);
        if(strcmp(a, b)){
                num++;
                if(('a' <= a[0]) && (a[0] <= 'z')){
                    per_letter[a[0] -  97] += num;
                }
                else{
                    per_letter[26] += num;
                }
        }
    }
    pthread_exit(NULL);
}


int main(){

   read_data();
   //display_data();//uncomment this for display all data....ALERT set MAXREAD before uncommenting this other wise it will print more than 400000 words
  process_data();
  printf("\ndata word in each letter class\n");
    for(int h = 0; h < 27; h++){
        per_letter[h] = (-1 + (pow(1 + (8 * per_letter[h]), 0.5)))/2;
        printf("%c\t%lld\n",h+97, per_letter[h]);
    }

  return 0;
}


void read_data(){
  FILE *filePointer;
  j = 0;
  length = 0;
  c = 0;
  filePointer = fopen("test.txt", "r");
  if(filePointer == NULL){
    perror("File not opened");
  }
  while(!feof(filePointer) && (o <= 100000)){
       c = getc(filePointer);
      if(c == '\n'){
      data[length++][j] = '\0';
       o++;
      j = 0;

    }
    else{
        if(('a' <= c) && (c <= 'z')){
            data[length][j++] = c;
        }
        else{
      c = tolower(c);
      data[length][j++] = c;
        }
    }
  }
    printf("total number of word is %lld\n", o - 1);
}

void display_data(){
   int k = 0, l = 0, i;
   printf("Printing data\n");
   for(k; k <= length; k++){
       for(l = 0; data[k][l] != '\0';l++){
      printf("%c", data[k][l]);
    }
    printf("\n");
  }
}

void process_data(){
    pthread_t tpid[28];
    int *ptr;
    char c;
    index_global = 0;
    for(index_global; index_global <= o; index_global++){

           pthread_create(&tpid[26], NULL, function_0, &index_global);
           pthread_join(tpid[26], NULL);

    }
}

