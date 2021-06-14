#include<stdio.h>
int main(){

  char c;
  int i, j;
  float f;

  printf("started\n");

  f = 10.67;
  printf("%.0f\n", f);//%.0f suppresses the printing of the decimal points and the fraction part, which is zero.

  c = getchar();//Declaration: int getchar(void)
  printf("Entered character is: ");
  printf("%c\n", c);
  putchar('A');//Declaration: int putchar(int char)
  putchar('\n');
  
  j = getchar();
  printf("j = %d\n", j);
  printf("j != EOF = %d\n", j != EOF);
  i = 5 != 5;// i = 0 and the precedency of != operator is higher than = operator.
  printf("i = %d\n", i);
  printf("value of EOF is %d\n", EOF);//value of EOF is -1.

  printf("Hello Geek\b\b\b\b\bF\n");// \b - backspace character transfers the cursor one character back with or without deleting on different compilers.
  printf("Testing \\ backslash\n");
  printf("\' testing single and \" single quotes\n");
  printf("5 = \0725\n");
  //'as', value inside the single quotes represent the character constant which is a numerical value for the machine to understand.
  //Here 000 is one to three octal digits(0….7) means there must be atleast one octal digit after \ and maximum three.
  //Here 072 is the octal notation, first it is converted to decimal notation that is the ASCII value of char ‘:’.
  // At the place of \072 there is : and the output is A:5.
  //printf("testing the \c\n");//\c is an unknown escape sequence.
  //printf("%%\n");
  //printf("\%\n");//Why this is working properly.

return 0;
}