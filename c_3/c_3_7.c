//solve for INT_MIN and INT_MAX
#include<stdio.h>
#include<limits.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#define MAXLEN 100

void itoaMy(int n_my, int len, char s_my[]);// need to send the length as no inbuitfunction to find the length of the integer
void itoa(int n, char s[]);

void itoa(int n, char s[]){
    int i, sign;
    i = sign = 0;
    if((sign = n) < 0){
        n = -n;
    }
    do{
        s[i++] = n % 10 + '0';
    }while((n /= 10) > 0);
    if(sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';
    strrev(s);
    return;
}

void itoaMy(int n_my,int len, char s_my[]){
    int i, sign;
    i = sign = 0;
    if((sign = n_my) < 0){
        n_my = -n_my;
    }
    if(sign < 0){
        s_my[i++] = '-';
    }
    for(i; (len - 1) >= 0 ;i++){
        s_my[i] = n_my/(pow(10, (len - 1))) + '0';
        n_my = n_my % (int)((pow(10, (len - 1))));
        --len;
    }
    s_my[i] = '\0';
    return;
}

int main(){
    int i = -83453;
    char s[MAXLEN];
    char s_my[MAXLEN];
    itoa(i, s);
    printf("%d\n", i);
    printf("%s\n", s);
    printf("%d\n", i);
    itoaMy(i, 5, s_my);
    printf("%d\n", i);
    printf("%s\n", s_my);
    return 0;
}
