#include<stdio.h>
#include<ctype.h>
//int tolower(int c);
int lower(int );

int main(){
   int i;
   char c;
   printf("Enter the input\t");
   //c = getchar();
   //i = lower(c);
   /*putchar(tolower(c));
   printf("\n");
   putchar(i);
   printf("\n");*/
   scanf("%c",&c);
   printf("%c", c);
   printf("%c", c);
   putchar(tolower(c));
   printf("\n%c", tolower(c));
   return 0;
}

int lower(int a){
    return((a >= 'A' && a <= 'Z') ? a + 'a' - 'A' : a); 
    /*if(a >=  'A' && a <= 'Z'){
        return a + 'a' - 'A';
    }
    else{
        return a;
    }*/
}