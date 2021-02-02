#include<stdio.h>
#define MAXLINE 50

int getstring(char s[]);
void squeeze(char s1[], char s2[]);

int main(){
    char s1[MAXLINE];
    char s2[MAXLINE];
    int len;
    printf("Start\n");
    getstring(s1);
    getstring(s2);
    printf("S1 is %s\n", s1);
    printf("S2 is %s\n", s2);
    squeeze(s1, s2);
    printf("Modified S1 is %s", s1);
    return 0;

}

int getstring(char s[]){
    printf("starting string\n");
    int i, c;
    i = c = 0;
    for(i;(c = getchar()) != EOF && c != '\n'; ++i){
        s[i] = c;

    }
    s[i] = '\0';
    return i;
}

void squeeze(char s1[], char s2[]){
     int i,j,k;
    k=0;

    for(i=0;s1[i]!='\0';++i)
    {
        for(j=0; (s1[i]!=s2[j]) && s2[j]!='\0' ;++j)
            ;
        if(s2[j]=='\0')
            s1[k++] = s1[i];
    }

    s1[k]='\0';
    /*
    int i, j, k;
     i = j = k = 0;
     while(s1[i] != '\0'){
         j = 0;
         k = 0;
         while((s2[j] != '\0') && (s1[i] != s2[j])){
             j = j + 1;
         }
         if(s2[j] == '\0'){
            s1[k] = s1[i];
         i = i + 1;
          k = k + 1;
         }
         else{
             ++i;
         }
     }
     s1[i] = '\0';
     return;*/

}
