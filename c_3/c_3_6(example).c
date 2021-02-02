#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define APLHABATE 26

void expand(char s1[], char s2[]){

    return;
}

int main(){
    char s_a[] ="a-z";
    char s_b[] ="a-b-c";
    char s_c[] ="a-z0-9";
    char s_d[] ="-a-z";
    char s_r[APLHABATE];

    printf("%s\n", s_a);
    printf("%s\n", s_b);
    printf("%s\n", s_c);
    printf("%s\n", s_d);

    printf("\n");

    expand(s_a, s_r);
    printf("%s\n", s_r);

    expand(s_b, s_r);
    printf("%s\n", s_r);

    expand(s_c, s_r);
    printf("%s\n", s_r);

    expand(s_d, s_r);
    printf("%s", s_r);

    return 0;
}
