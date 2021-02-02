#include<stdio.h>
int main(){
    int c, i, a, nwhite, nother;
    int ndigit[10];
    char s[] = "Hello earth";

    a = nwhite = nother = 0;
    for(i = 0; i < 10; ++i){
        ndigit[i] = 0;
    }

    while((c = getchar()) != EOF){
        if(c >= '0' && c <= '9'){
            ++ndigit[c - '0'];
        }
        else if( c == ' ' || c == '\n' || c == '\t'){
            ++nwhite;
        }
        else{
            ++nother;
        }
    }
    printf("Digits = ");
    for(i = 0; i < 10; ++i){
        printf("%d ", ndigit[i]);
    }
    printf("White space = %d, other = %d\n", nwhite, nother);

   /* int atoi(char s[]){
        int i, n;
        n = i = 0;
        for(i = 0; s[i] >= '0' && s[i] <= '9'; ++i){
            n = n * 10 + (s[i] - '0');
        }
        return n;
    }
    
    a = atoi(s);
    printf("%d", a);*/
    
}