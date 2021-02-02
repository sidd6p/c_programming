#include<stdio.h>
#define MAXLINE 1000

int getline(char line[], int lim);

int main(){
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 10;
    while((len = getline(line, MAXLINE)) > 0){
        if(len - 1 >= max){//because we should not include '\n' as a character 
           printf("%s", line);
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


