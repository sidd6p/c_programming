#include<stdio.h>
//https://www.geeksforgeeks.org/pointer-array-array-pointer/
void swap(int *px,int *py);
int main(){
    int arr[5] = {0, 1, 2, 3, 4}, *ptr, arr_0[5];
    char *arr_p = "HEllo earth";
    //int (*arr_p_0)[5] = {5, 6, 7, 8, 9};//initialization makes pointer from integer without a cast [-Wint-conversion]
    int (*arr_p_1)[5];//pointer to array of size 5.
    arr_p_1 = &arr;
    ptr = arr;//legal
    //arr_p[0] = 'h';//illegal
    //arr_0 = ptr;//illegal
    ptr[0] = 10;
    printf("ptr = %d\n",ptr);//&arr[0]
    printf("*ptr = %d\n",*ptr);//arr[0]
    printf("*ptr + 1 = %d\n",*ptr + 1);//arr[1]
    printf("arr = %d\n",arr);//&arr[0]
    printf("&arr= %d\n",&arr);//&arr[0]
    printf("*arr = %d\n",*arr);//arr[0]
    printf("*arr + 1 = %d\n",*(arr + 1));//arr[1]
    printf("arr[0]= %d\n",arr[0]);//arr[0]
    //printf("arr++= %d\n",arr++);//illegal
    printf("++ptr= %d\n",++ptr);//&arr[1] = arr[0] + sizeof(int)
    printf("*arr_p= %c\n",*arr_p);//arr_p[0]
    printf("arr_p_1= %d\n",arr_p_1);//&arr[0]
    printf("*arr_p_1= %d\n",*arr_p_1);//&arr[0]
    /*On dereferencing a pointer expression we get a value pointed to by that pointer expression.
    Pointer to an array points to an array, so on dereferencing it,
    we should get the array, and the name of array denotes the base address.
    So whenever a pointer to an array is dereferenced,
    we get the base address of the array to which it points.*/
    return 0;
}

