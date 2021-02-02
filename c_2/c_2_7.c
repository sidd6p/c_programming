//double sqrt(double);
#include<stdio.h>
#include<math.h>
int main(){
    int i = 5;
    printf("Start");
    printf("%f", (sqrt((double)i)));//sqrt() accept the argument as double, so if we pass int then it will be us as double and it also return a double
    return 0;

}
