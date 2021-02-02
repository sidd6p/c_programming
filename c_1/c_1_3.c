#include<stdio.h>
#define MAXLINE 1000

int getline(char line[], int lim);
int removeBlanks(char line[], int len);

int main(){
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 10;
    while((len = getline(line, MAXLINE)) > 0){
        len = removeBlanks(line, len);
        if(len > 1){
            printf("%s", line);
            printf("Length is %d\n", len - 1);
        }
    }
    return 0;
}

int getline(char line[], int lim){
    int c, i;
    for(i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i){
        line[i] = c;
    }
    if(c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

int removeBlanks(char line[], int len){
    int i = 0, newLen = len;
    for(i = 0; i < len; ++i){
        if(line[i] == ' ' || line[i] == '\t'){
            line[i] == '\0';
            newLen = newLen - 1;
        }
    }
    return newLen;
}
