#include<stdio.h>

int binaryserach(int x, int v[], int n);
int binarysearchimproved(int x, int v[], int n);

int binaryserach(int x, int v[], int n){
    int low, high, mid;
    low = mid = 0;
    high = n - 1;
    while(low <= high){
        mid = (low + high) / 2;
        if(x < v[mid]){
            high = mid - 1;
        }
        else if(x > v[mid]){
            low = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int binarysearchimproved(int x, int v[], int n){
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (high + low) / 2;
    while((low <= high) && (x != v[mid])){
        if(x < v[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
         mid = (low + high) / 2;
    }
    if( x == v[mid]){
        return mid;
    }
    return -1;
}

int main(void)
{
    int arr[]={2,4,6,7,9,29,45,46,49,50,51};
    int position = 0;
    printf("%d\n", position);
    position = binaryserach(51, arr, 11);
    //position = binarysearchimproved(51, arr, 11);

    printf("%d\n", position);

    return 0;
}
