#include<stdio.h>
int main(){
   const int a[50];//give permission for read only
    for(int i = 0; i < 50; i++){
        a[i] = 0;
    }
    for(int i = 0; i < 50; i++){
        a[i] += 1;
    }
    for(int i = 0; i < 50; i++){
        printf("%d\t", a[i]);
    }
    void a_change(const int a[]){//give permission for read only
        for(int i = 0; i < 50; i++){
            a[i] += 0;
        }
        return;
    }
     a_change(a);
     for(int i = 0; i < 50; i++){
        printf("%d\t", a[i]);
    }
    return 0;
}
