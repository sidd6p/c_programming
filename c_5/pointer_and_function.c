#include<stdio.h>
void swap(int *px,int *py);
int main(){
    int a, b;
    a= 5;
    b = 10;
    int *c = &a; // c = &a
    printf("c = %d and *c = %d\n", c, *c);
    printf("a = %d and b = %d\n", a, b);
    printf("address of a = %d and address of b = %d\n", &a, &b);
    swap(&a, &b);
    printf("a = %d and b = %d\n", a, b);
    printf("address of a = %d and address of b = %d\n", &a, &b);

    int arr[5] = {0, 1, 2, 3, 4}, *ptr;
    ptr = arr;
    printf("ptr = %d\n",ptr);//&arr[0]
    printf("*ptr = %d\n",*ptr);//arr[0]
    printf("*ptr + 1 = %d\n",*ptr + 1);//arr[1]
    printf("arr = %d\n",arr);//&arr[0]
    printf("*arr = %d\n",*arr);//arr[0]
    printf("*arr + 1 = %d\n",*(arr + 1));//arr[1]
    return 0;
}

void swap(int *px, int *py){//this is equivalent to px = &a and py = &b
    int temp;
    printf("px = %d and py = %d\n", px, py);
    printf("*px = %d and *py = %d\n", *px, *py);
    temp = *px;
    *px = *py;
    *py = temp;
}
