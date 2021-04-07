#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#define MAXNAME 50

char file1[MAXNAME];
char file2[MAXNAME];

void * space_operation(void * arg);

void * copy_file(void * arg){
    pthread_t t2;
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
    if((pthread_create(&t2, NULL, space_operation, NULL))){
        perror("Thread t2 cannot be created");
    }
    pthread_join(t2, NULL);
    pthread_exit(NULL);
}

void * space_operation(void * arg){
    FILE *fp2, *fp3;
    int c = 0;
    int flag = -1;

    if(!(fp2 = fopen(file2, "r"))){
        perror("File 2 cannot be opened");
    }
    if(!(fp3 = fopen("test_3.txt", "w"))){
        perror("File 2 cannot be opened");
    }
    while((c = fgetc(fp2)) != EOF){
        if((c == ' ') && (flag == -1)){
            flag = 1;
            fputc(c,fp3);
          }
        if((c == ' ') && (flag == 1)){
           }
           else{
              fputc(c,fp3);
              flag = -1;
           }
    }
    fclose(fp2);
    fclose(fp3);
    if(!(fp2 = fopen(file2, "w"))){
        perror("File 2 cannot be opened");
    }
    if(!(fp3 = fopen("test_3.txt", "r"))){
        perror("File 2 cannot be opened");
    }
    while((c = fgetc(fp3)) != EOF){
        fputc(c,fp2);
    }
    fclose(fp3);
    fclose(fp2);
    printf("ok.,..");
    pthread_exit(NULL);
}

int main(){

    pthread_t t1;
    int i;

    printf("Enter name of file 1\n");
    scanf("%s",file1);
    printf("Enter name of file 2\n");
    scanf("%s",file2);

    if((pthread_create(&t1, NULL, copy_file, NULL))){
        perror("Thread t1 cannot be created");
    }
    pthread_join(t1, NULL);
    return 0;
}


