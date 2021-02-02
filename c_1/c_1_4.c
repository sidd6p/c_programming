#include<stdio.h>
#define MAXLINE 50

void reverse(char s[]);
int getline(char s[], int len);
int main(){
    int len;
    char s[MAXLINE];

    printf("start\n");

    while((len = getline(s, MAXLINE)) > 0){
        if(len > 1){
            printf("Original is %s", s);
            reverse(s);
            printf("Reverse is %s\n", s);
        }
    }
    return 0;

}

int getline(char s[], int lim){
    int c, i;
    for(i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i){
        s[i] = c;
    }
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void reverse(char s[]){
    int i = 0, j = 0;
    char c;
    char s_reverse[MAXLINE];
    while((c = s[i])!= '\0'){
        s_reverse[i] = c;
        i = i + 1;
    }
     i = i - 2;//for eleminating '\n' and '\0'
    while(j <= i){
        s[j] = s_reverse[i - j];
        j = j + 1;
    }
    s[j] = '\0';
}

