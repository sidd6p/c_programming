#include<stdio.h>
#define MAXLINE 200

void escape(char s[], char t[]);
void escapereverse(char r[], char s[]);
int getline(char t[], int lim);

void escape(char s[], char t[]){
    int i, j;
    i = j = 0;
    while(t[i] != '\0'){
        switch(t[i]){
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
                s[j] = t[i];
                break;
        }
        ++i;
        ++j;

    }
    s[j] = t[i];
}

void escapereverse(char r[], char s[]){
    int c, i, j;
    c = i = j = 0;
    while((c =  s[i]) != '\0'){
        switch(c){
            case '\\':
                if((s[i + 1]) == 't'){
                    r[j] = '\t';
                    ++i;
                }
                else if((s[i + 1]) == 'n'){
                    r[j] = '\n';
                    ++i;
                }
                break;
            default:
                r[j] = c;
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
    j = getline(t, MAXLINE);
    t[i] = '\0';
    return i;
}

int main(){
    char t[MAXLINE];
    char s[MAXLINE];
    char r[MAXLINE];
    int j;
    j = 0;
    escape(s, t);
    escapereverse(r, s);
    printf("\n\n\n");
    printf("%s\n", t);
    printf("\n\n\n");
    printf("%s\n", s);
    printf("\n\n\n");
    printf("%s\n", r);
    return 0;
}
