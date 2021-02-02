#include<stdio.h>
void swap(int *px,int *py);
int main(){
    int a, b;

    a= 5;
    b = 10;

    printf("a = %d and b = %d\n", a, b);
    printf("address of a = %d and address of b = %d\n", &a, &b);
    swap(&a, &b);
    printf("a = %d and b = %d\n", a, b);
     printf("address of a = %d and address of b = %d\n", &a, &b);
    return 0;
}

void swap(int *px, int *py){//this is equivalent to px = &a and py = &b
    int temp;
    printf("px = %d and py = %d\n", *px, *py);
    temp = *px;
    *px = *py;
    *py = temp;
}