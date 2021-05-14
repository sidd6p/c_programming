//https://www.tutorialspoint.com/unix_sockets/network_byte_orders.htm
//https://man7.org/linux/man-pages/man3/bzero.3.html
//https://www.systutorials.com/docs/linux/man/3-inet_addr/
//https://www.tutorialspoint.com/unix_sockets/socket_structures.htm
//https://docs.microsoft.com/en-us/windows/win32/api/ws2def/ns-ws2def-sockaddr_in
//https://www.mkssoftware.com/docs/man3/listen.3.asp#:~:text=The%20listen%20%28%29%20function%20marks%20a%20connection-mode%20socket,to%20the%20value%20specified%20by%20the%20backlog%20argument.
//https://www.geeksforgeeks.org/accept-system-call/
//https://www.tutorialspoint.com/unix_sockets/socket_server_example.htm
//https://www.geeksforgeeks.org/socket-programming-cc/
//https://www.binarytides.com/socket-programming-c-linux-tutorial/#:~:text=TCP%2FIP%20socket%20programming%20in%20C%201%20Create%20a,will%20simply%20send%20data.%20...%20More%20items...%20
//https://www.delftstack.com/howto/c/bzero-in-c/#use-explicit-bzero-function-to-zero-out-the-memory-region-in-c
#include<stdio.h>
#include <arpa/inet.h>
#include<string.h>
//#include <Winsock2.h>
int main(){
    
    char s[] = "Hello earth ok good siddhartha ok i am siddhartha ok lets see it odf fg dg dh d g sdg dsfgsdfgsdg fd gdf g";
    char s1[] = "Hello see";
    bzero(s + 2, 1);
    memset(s1, 'a', 2); // --> aallo see
    printf("%s\n", s); // --> He
    printf("%s", s1);


    char str1[50] = "abcdef";
    char str2[50] = "abcd";
    char str3[] =  "ghi";
    int i, j, k;
	i = strncmp(str1, str2, 4);		
    printf("\n The Comparison of str1 and str2 Strings = %d", i); // --> 0
 	j = strncmp(str1, str2, 6);		
    printf("\n The Comparison of str1 and str2 Strings = %d", j); // --> positive
    k = strncmp(str1, str3, 3);		
    printf("\n The Comparison of str1 and str3 = %d", k); /// --> negative
    /*0, if both the strings str1 and str2 are equal
    >0, if the ASCII value of first unmatched character of str1 is greater than str2
    <0, if the ASCII value of first unmatched character of str1 is less than str2*/
    
    printf("\n%d htons", htons(1));//256
    printf("\n%d htonl", htonl(1)); // 16777216
    printf("\n%d inet_addr", inet_addr("0.0.0.1"));
    /*htons host to network short
    ntohs network to host short
    htonl host to network long
    ntohl network to host long
    long is 32 bits. short is 16 bits.*/
    //The htons function takes a 16-bit number in host byte order and returns a 16-bit number in network byte order used in TCP/IP networks (the AF_INET or AF_INET6 address family).
    //The htons function can be used to convert an IP port number in host byte order to the IP port number in network byte order.
    printf("OK\n");
    return 0;
}