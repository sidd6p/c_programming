#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define MAXNAME 50
#define MAXLENGTH 5000

char file1[MAXNAME];
char file2[MAXNAME];
char output_string[MAXLENGTH];


void* copy_file(void * arg){//for thread_1
    FILE *fp1, *fp2;
    int c = 0;
    if(!(fp1 = fopen(file1, "r"))){
        perror("File 1 cannot be opened");
    }
    if(!(fp2 = fopen(file2, "w"))){
        perror("File 2 cannot be opened");
    }
    while((c = fgetc(fp1)) != EOF){
        fputc(c,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    pthread_exit(NULL);
}

void * space_operation(void * arg){//for thread_2
    FILE *fp0, *fp3;
    char d[1];
    int flag = -1;
    if(!(fp0 = fopen(file2, "r"))){
        perror("File 2 cannot be opened");
    }
    while((d[0] = fgetc(fp0)) != EOF){
         if((d[0] == ' ') && (flag == -1)){
            flag = 1;
            strcat(output_string, d);
          }
        if((d[0] == ' ') && (flag == 1)){
           }
           else{
             strcat(output_string, d);
              flag = -1;
           }
    }
    fclose(fp0);
    pthread_exit(NULL);
}

int main(){
    pthread_t t1, t2;

    printf("Enter name of file 1\n");
    scanf("%s",file1);
    printf("Enter name of file 2\n");
    scanf("%s",file2);

    if((pthread_create(&t1, NULL, copy_file, NULL))){
        perror("Thread t1 cannot be created");
    }
    pthread_join(t1, NULL);

    if((pthread_create(&t2, NULL, space_operation, NULL))){
        perror("Thread t2 cannot be created");
    }
    pthread_join(t2, NULL);

    printf("\nString is \n%s\n", output_string);
    return 0;
}


