#include<stdio.h>
#define MAXLINE 50

int getstring(char s[]);
int firstOccur(char s1[], char s2[]);

int main(){
    char s1[MAXLINE];
    char s2[MAXLINE];
    int position = 0;
    printf("Start\n");
    getstring(s1);
    getstring(s2);
    printf("S1 is %s\n", s1);
    printf("S2 is %s\n", s2);
    position = firstOccur(s1, s2);
    printf("First Position is %d", position);
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

int firstOccur(char s1[], char s2[]){
     int i,j,k;
    k=0;

    for(i=0;s1[i]!='\0';++i)
    {
        for(j=0; (s1[i]!=s2[j]) && s2[j]!='\0' ;++j)
            ;
        if(s1[i] == s2[j])
            return i;
    }
    return -1;
}
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
