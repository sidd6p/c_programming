//All of these functions read a character from input and return an integer value.
#include <stdio.h>
#include <conio.h>
int main()
{
   printf("Getc: ");
   printf("%c", getc(stdin));//need to press some key to contiuue
   fflush(stdin);
   fflush(stdout);
   printf("Getchar: ");
   printf("%c", getchar());//need to press some key to continue
   fflush(stdin);
   fflush(stdout);
   printf("Getch: ");
   printf("%c", getch());//no need to press any key to continue
   fflush(stdin);
   fflush(stdout);
   printf("Getche: ");
   printf("%c", getche());//no need to press any key to continue//display the input immediately
   fflush(stdin);
   fflush(stdout);
   return 0;
}
