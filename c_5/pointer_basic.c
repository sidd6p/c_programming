#include<stdio.h>
int main(){
    int x = 1, y = 2, z[10];
    int *p_1, *p_2;
    z[0] = 100;
    p_1 = &x;
    y = *p_1;
    *p_1 = 0;
    p_1 = &z[0];
    p_1 = p_2;
    printf("Value of p_1 is = %d\n", p_1);
    printf("Value of p_2 is = %d\n", p_2);
    printf("Value of y is = %d\n", y);
    printf("Value of x is = %d\n", x);
    printf("Value of z[0] is = %d\n", z[0]);
}
