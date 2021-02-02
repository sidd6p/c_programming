//https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
//The & (bitwise AND) in C or C++ takes two numbers as operands and does AND on every bit of two numbers. The result of AND is 1 only if both bits are 1.
//The | (bitwise OR/ bitwise inclusive OR) in C or C++ takes two numbers as operands and does OR on every bit of two numbers. The result of OR is 1 if any of the two bits is 1.
//The ^ (bitwise XOR/ bitwise exclusive OR) in C or C++ takes two numbers as operands and does XOR on every bit of two numbers. The result of XOR is 1 if the two bits are different.
//The << (left shift) in C or C++ takes two numbers, left shifts the bits of the first operand, the second operand decides the number of places to shift.
//The >> (right shift) in C or C++ takes two numbers, right shifts the bits of the first operand, the second operand decides the number of places to shift.
//The ~ (bitwise NOT) in C or C++ takes one number and inverts all bits of it
//C Program to demonstrate use of bitwise operators 
//The left shift and right shift operators should not be used for negative numbers.
//Also, if the number is shifted more than the size of integer, the behaviour is undefined.
//but bitwise operators return an integer value. 
//The left-shift and right-shift operators are equivalent to multiplication and division by 2 respectively
//The value of expression (x & 1) would be non-zero only if x is odd, otherwise the value would be zero.
//The result of ~ operator on a small number can be a big number if the result is stored in an unsigned variable. And the result may be a negative number if the result is stored in a signed variable (assuming that the negative numbers are stored in 2’s complement form where the leftmost bit is the sign bit)

#include <stdio.h> 
#define SET_ON 1
int main() 
{ 
    // a = 5(00000101), b = 9(00001001) 
    unsigned char a = 5, b = 9; 
  
    // The result is 00000001 
    printf("a = %d, b = %d\n", a, b); 
    printf("a&b = %d\n", a & b); 
  
    // The result is 00001101 
    printf("a|b = %d\n", a | b); 
  
    // The result is 00001100 
    printf("a^b = %d\n", a ^ b); 
  
    // The result is 11111010 
    printf("~a = %d\n", a = ~a); 
  
    // The result is 00010010 
    printf("b<<1 = %d\n", b << 1); 
  
    // The result is 00000100 
    printf("b>>1 = %d\n", b >> 1); 

    //turn on bits
    printf("a = a | SET_ON = %d\n", a | SET_ON);
  
    return 0; 
} 