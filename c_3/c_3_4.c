//cannot take much large number due to the limitation of long
//but long is not working properly
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

long atoimy(char s[]);
long atoimy(char s[]){
    long j, n;
    long sign;
    j = n = 0;;
    for(j = 0; isspace(s[j]); j++){
        ;
    }
    sign = (s[j] == '-') ? -1 : 1;
    if(s[j] == '-' || s[j] == '+'){
        j++;
    }
    for(n = 0; (isdigit(s[j])) && (s[j] != '\0'); j++){
        n = n * 10 + (s[j] - '0');
    }
    return (sign * n);
}

int main(){
    char s0[] = "8794365";
    char s1[] = "HEllo earth";
    char s2[] = "    7203565";
    char s3[] = "     -778464356";
    long i = 0;
    printf("%s\n", s0);
    printf("%s\n", s1);
    printf("%s\n", s2);
    printf("%s\n", s3);
    printf("\n\n");
    i = atoimy(s0);
    printf("%ld\n", i);
    i = atoimy(s1);
    printf("%ld\n", i);
    i = atoimy(s2);
    printf("%ld\n", i);
    i = atoimy(s3);
    printf("%ld\n", i);
    return 0;
}
