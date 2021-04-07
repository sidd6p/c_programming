#include <stdio.h>
#include <pthread.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAXWORD 1000000
#define MAXLETTER 30
#define MAXREAD 1000

void read_data();
void process_data();
void display_data();
int check_for_palindrome_word(char, int);
int index_global = 0;
int per_letter[26];

void * function_a(void * index_temp){
   int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('a', (*index_inside));
   pthread_exit(&index_global);
}
void * function_b(void * index_temp){
   int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('b', (*index_inside));
   pthread_exit(&index_global);
}
void * function_c(void * index_temp){
   int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('c', (*index_inside));
   pthread_exit(&index_global);

}
void * function_d(void * index_temp){
   int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('d', (*index_inside));
   pthread_exit(&index_global);

}
void * function_e(void * index_temp){
   int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('e', (*index_inside));
   pthread_exit(&index_global);

}
void * function_f(void * index_temp){
   int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('f', (*index_inside));
   pthread_exit(&index_global);

}
void * function_g(void * index_temp){
   int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('g', (*index_inside));
   pthread_exit(&index_global);

}
void * function_h(void * index_temp){
   int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('h', (*index_inside));
   pthread_exit(&index_global);

}
void * function_i(void * index_temp){
   int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('i', (*index_inside));
   pthread_exit(&index_global);

}
void * function_j(void * index_temp){
   int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('j', (*index_inside));
   pthread_exit(&index_global);
}
void * function_k(void * index_temp){
   int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('k', (*index_inside));
   pthread_exit(&index_global);

}
void * function_l(void * index_temp){
     int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('l', (*index_inside));
   pthread_exit(&index_global);

}
void * function_m(void * index_temp){
     int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('m', (*index_inside));
   pthread_exit(&index_global);

}
void * function_n(void * index_temp){
     int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('n', (*index_inside));
   pthread_exit(&index_global);

}
void * function_o(void * index_temp){
     int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('o', (*index_inside));
   pthread_exit(&index_global);

}
void * function_p(void * index_temp){
     int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('p', (*index_inside));
   pthread_exit(&index_global);

}
void * function_q(void * index_temp){
     int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('q', (*index_inside));
   pthread_exit(&index_global);

}
void * function_r(void * index_temp){
     int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('r', (*index_inside));
   pthread_exit(&index_global);

}
void * function_s(void * index_temp){
     int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('s', (*index_inside));
   pthread_exit(&index_global);

}
void * function_t(void * index_temp){
     int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('t', (*index_inside));
   pthread_exit(&index_global);

}
void * function_u(void * index_temp){
     int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('u', (*index_inside));
    pthread_exit(&index_global);

}
void * function_v(void * index_temp){
     int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('v', (*index_inside));
   pthread_exit(&index_global);

}
void * function_w(void * index_temp){
     int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('w', (*index_inside));
   pthread_exit(&index_global);

}
void * function_x(void * index_temp){
     int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('x', (*index_inside));
   pthread_exit(&index_global);

}
void * function_y(void * index_temp){
  int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('y', (*index_inside));
   pthread_exit(&index_global);

}
void * function_z(void * index_temp){
  int *index_inside = (int *)index_temp;
   index_global = check_for_palindrome_word('z', (*index_inside));
   pthread_exit(&index_global);
}

int total_palindorme = 0;
int data[MAXWORD][MAXLETTER];
long long int c = 0, j = 0, i = 0, length = 0, index_i = 0, o = 0;


int main(){
    for(int h = 0; h < 26; h++){
        per_letter[h] = 0;
    }
    read_data();
    //display_data();
    process_data();
    printf("\ndata word in each letter class\n");
    for(int h = 0; h < 27; h++){
            per_letter[h] = (-1 + (pow(1 + (8 * per_letter[h]), 0.5)))/2;
        printf("%c\t%d\n",h + 97, per_letter[h]);
    }
  return 0;
}

int check_for_palindrome_word(char ch, int ind){
  long long int length;
  long long int num, i, j, temp_count;
  int word[30];
  i = j = num = temp_count = 0;
  int q = 0;
  printf("\n");

    for(ind; data[ind][0] - ch == 0; ind++){

            for(length = 0; data[ind][length] != '\0'; length++){
                word[length] = data[ind][length];
            }
            q = 0;
            for(i = ind; i < o; i++){
                      for(j = 0; (word[j] - data[i][length - j - 1]) == 0; j++){
                          ;
                    }
           if(j == (length - 1)){
            num++;
         }
            }
     }
     per_letter[ch -  97] += num;
  return ind;
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
  while(!feof(filePointer) && (o < MAXREAD)){
       c = getc(filePointer);
      if(c == '\n'){
      data[length++][j] = '\0';
       o++;
      j = 0;

    }
    else{
      c = tolower(c);
      data[length][j++] = c;
    }
  }
    printf("total number of word is %lld", o);
}

void display_data(){
   int k = 0, l = 0;
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
    index_global = 0;
    for(index_global; index_global <= o;index_global++){
        switch(data[index_global][0]){
        case 'a':
            pthread_create(&tpid[0], NULL, function_a, &index_global);
            pthread_join(tpid[0], (void**)&ptr);
            index_global = (*ptr) - 1;
            break;
        case 'b':
            pthread_create(&tpid[1], NULL, function_b, &index_global);
            pthread_join(tpid[1], (void**)&ptr);
            index_global = (*ptr) - 1;
            break;

        case 'c':
            pthread_create(&tpid[2], NULL, function_c, &index_global);
            pthread_join(tpid[2], (void**)&ptr);
            index_global = (*ptr) - 1;
            break;
        case 'd':
            pthread_create(&tpid[3], NULL, function_d, &index_global);
            pthread_join(tpid[3], (void**)&ptr);
            index_global = (*ptr) - 1;
            break;
        case 'e':
            pthread_create(&tpid[4], NULL, function_e, &index_global);
            pthread_join(tpid[4], (void**)&ptr);
            index_global = (*ptr) - 1;
            break;
        case 'f':
            pthread_create(&tpid[5], NULL, function_f, &index_global);
            pthread_join(tpid[5], (void**)&ptr);
            index_global = (*ptr) - 1;
            break;
        case 'g':
            pthread_create(&tpid[6], NULL, function_g, &index_global);
            pthread_join(tpid[6], (void**)&ptr);
            index_global = (*ptr) - 1;
            break;
        case 'h':
            pthread_create(&tpid[7], NULL, function_h, &index_global);
            pthread_join(tpid[7], (void**)&ptr);
            index_global = (*ptr) - 1;
            break;
        case 'i':
            pthread_create(&tpid[8], NULL, function_i, &index_global);
            pthread_join(tpid[8], (void**)&ptr);
            index_global = (*ptr) - 1;
            break;
        case 'j':
            pthread_create(&tpid[9], NULL, function_j, &index_global);
            pthread_join(tpid[9], (void**)&ptr);
            index_global = (*ptr) - 1;
            break;
        case 'k':
            pthread_create(&tpid[10], NULL, function_k, &index_global);
            pthread_join(tpid[10], (void**)&ptr);
            index_global = (*ptr) - 1;
            break;
        case 'l':
            pthread_create(&tpid[11], NULL, function_l, &index_global);
            pthread_join(tpid[11], (void**)&ptr);
            index_global = (*ptr) - 1;
             break;
        case 'm':
            pthread_create(&tpid[12], NULL, function_m, &index_global);
            pthread_join(tpid[12], (void**)&ptr);
            index_global = (*ptr) - 1;
            break;
        case 'n':
            pthread_create(&tpid[13], NULL, function_n, &index_global);
            pthread_join(tpid[13], (void**)&ptr);
            index_global = (*ptr) - 1;
            break;
        case 'o':
            pthread_create(&tpid[14], NULL, function_o, &index_global);
            pthread_join(tpid[14], (void**)&ptr);
            index_global = (*ptr) - 1;
            break;
        case 'p':
            pthread_create(&tpid[15], NULL, function_p, &index_global);
            pthread_join(tpid[15], (void**)&ptr);
            index_global = (*ptr) - 1;
            break;
        case 'q':
            pthread_create(&tpid[16], NULL, function_q, &index_global);
            pthread_join(tpid[16], (void**)&ptr);
            index_global = (*ptr) - 1;
             break;
        case 'r':
            pthread_create(&tpid[17], NULL, function_r, &index_global);
            pthread_join(tpid[17], (void**)&ptr);
            index_global = (*ptr) - 1;
            break;
        case 's':
            pthread_create(&tpid[18], NULL, function_s, &index_global);
            pthread_join(tpid[18], (void**)&ptr);
            index_global = (*ptr) - 1;
            break;
        case 't':
            pthread_create(&tpid[19], NULL, function_t, &index_global);
            pthread_join(tpid[19], (void**)&ptr);
            index_global = (*ptr) - 1;
            break;
        case 'u':
            pthread_create(&tpid[20], NULL, function_u, &index_global);
            pthread_join(tpid[20], (void**)&ptr);
            index_global = (*ptr) - 1;
            break;
        case 'v':
            pthread_create(&tpid[21], NULL, function_v, &index_global);
            pthread_join(tpid[21], (void**)&ptr);
            index_global = (*ptr) - 1;
            break;
        case 'w':
            pthread_create(&tpid[22], NULL, function_w, &index_global);
            pthread_join(tpid[22], (void**)&ptr);
            index_global = (*ptr) - 1;
            break;
        case 'x':
            pthread_create(&tpid[23], NULL, function_x, &index_global);
            pthread_join(tpid[23], (void**)&ptr);
            index_global = (*ptr) - 1;
            break;
        case 'y':
            pthread_create(&tpid[24], NULL, function_y, &index_global);
            pthread_join(tpid[24], (void**)&ptr);
            index_global = (*ptr) - 1;
            break;
        case 'z':
            pthread_create(&tpid[25], NULL, function_z, &index_global);
            pthread_join(tpid[25], (void**)&ptr);
            index_global = (*ptr) - 1;
            break;
        default:
            break;
        }

    }
}
