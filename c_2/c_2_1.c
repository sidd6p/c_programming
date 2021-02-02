//single-precision is called binary32(1, 8, 32) and double precision(1, 11, 52) is caleed binary64
//In single-precision, 32-bit format, one bit is used to tell whether the number is positive or negative. Eight bits are reserved for the exponent, which (because it’s binary) is 2 raised to some power. The remaining 23 bits are used to represent the digits that make up the number, called the significand
#include<stdio.h>
#include<limits.h>//Limits.h header file in C is used to determine the set limits of variable data stypes. Macros(symbolic constant/symbolic name) defined in limits.h are used to find the limit of the values of various data types.
//1234 is int and 1234L or 1234l is a long int
//31 can be written as 037 in octal and 0x1f/0X1F in hex
//0XFUL is unsigned long constant with value 15
//CHARACTER CONSTANT is an integer written as 'x'. For example '0' has the value of 48
//sequence of charcter in double quotes is called CHARACTER CONSTANT string or STRING CONSTANT or STRING LITEERAL. Example "Hello Earth\n"
//'/n' stand for value of the newline charcter, which is 10  ASCII
//CONSTANT EXPRESSION is an expression that involve only constant and evulated during compliation instead of run-time. Example #define MAXLINE 1000
#include<float.h>
int main(){


    int _sidd;//avoid this type of declaaration that start with _
    scanf("%d", &_sidd);//cannot include any message in scanf
    printf("\n%d", _sidd);

    printf("\n");

    printf("Ranges of various floating-point types from standard headers:\n");

        printf("Minimum Signed Char %d\n", SCHAR_MIN);
        printf("Maximum Signed Char %d\n", SCHAR_MAX);

        printf("Minimum Signed Short %d\n", SHRT_MIN);
        printf("Maximum Signed Short %d\n", SHRT_MAX);

        printf("Minimum Signed Int %d\n", INT_MIN);
        printf("Maximum Signed Int %d\n", INT_MAX);

        printf("Minimum Signed Long %ld\n", LONG_MIN);
        printf("Maximum signed Long %ld\n", LONG_MAX);

        /* Unsigned Maximum Values */

        printf("Maximum Unsigned Char %d\n", UCHAR_MAX);
        printf("Maximum Unsigned Short %d\n", USHRT_MAX);
        printf("Maximum Unsigned Int %u\n", UINT_MAX);
        printf("Maximum Unsigned Long %lu\n", ULONG_MAX);


        printf("testing \n");
        printf("Maximum Signed Char %d\n",((unsigned char) ~0 ));
        printf("\n");
         /* ranges of various floating-point types through calculation */
         /* The logic used is
* ~0 will give bits in 1s.
* (unsigned <type>) will cast it unsigned.
* >> 1 right shifts 1 bit to remove the sign bit.
* (<type>) casting it the required type again*/
    printf("Ranges of various floating-point types through calculation:\n");

    printf("Minimum Signed Char %d\n",-(char)((unsigned char) ~0 >> 1) - 1);
    printf("Maximum Signed Char %d\n",(char) ((unsigned char) ~0 >> 1));

    printf("Minimum Signed Short %d\n",-(short)((unsigned short)~0 >>1) -1);
    printf("Maximum Signed Short %d\n",(short)((unsigned short)~0 >> 1));

    printf("Minimum Signed Int %d\n",-(int)((unsigned int)~0 >> 1) -1);
    printf("Maximum Signed Int %d\n",(int)((unsigned int)~0 >> 1));

    printf("Minimum Signed Long %ld\n",-(long)((unsigned long)~0 >>1) -1);
    printf("Maximum signed Long %ld\n",(long)((unsigned long)~0 >> 1));

    /* Unsigned Maximum Values */

    printf("Maximum Unsigned Char %d\n",(unsigned char)~0);
    printf("Maximum Unsigned Short %d\n",(unsigned short)~0);
    printf("Maximum Unsigned Int %u\n",(unsigned int)~0);
    printf("Maximum Unsigned Long %lu\n\n",(unsigned long)~0);


    return 0;
}
