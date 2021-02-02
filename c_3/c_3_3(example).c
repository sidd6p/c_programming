#include<stdio.h>
#define MAXLINE 100

void escape(char s[], char t[]);
int getline(char t[], int lim);


void escape(char s[], char t[]){
    int c, i, j;
    c = i = j = 0;
    while((c =  t[i]) != '\0'){
        switch(c){
            case '\n':
                s[j] = '\\';
                ++j;
                s[j] = 'n';
                break;
            case '\t':
                s[j] = '\\';
                ++j;
                s[j] = 't';
                break;
            default:
                s[j] = c;
                break;
        }
        ++i;
        ++j;

    }
    s[j] = '\0';
}


int getline(char t[], int lim){
    int c, i;
    for(i = 0; i < lim-1 && (c = getchar()) != EOF ; ++i){
        t[i] = c;
    }
    t[i] = '\0';
    return i;
}

int main(){
    char t[MAXLINE];
    char s[MAXLINE];
    int j;
    j = 0;
    j = getline(t, MAXLINE);
    escape(s, t);
    printf("%s\n", t);
    printf("%s\n", s);
    return 0;
}
