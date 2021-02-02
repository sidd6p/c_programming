#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse(char s[]){
    int c, j, i;
    c = i = j = 0;
    for(i, j = strlen(s) - 1; i < j;  ++i, --j){
        c = s[i];//c = s[i], s[i] = s[j], s[j] = c;
        s[i] = s[j];
        s[j] = c;
    }
    return;
}

int main(){
    char s[] ="HEllo Earth";
    printf("%s\n", s);
    reverse(s);
    printf("%s",s);
    return 0;
}
