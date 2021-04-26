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
#include<stdio.h>
#include <arpa/inet.h>
#include<string.h>
//#include <Winsock2.h>
int main(){
    char s[] = "Hello earth";
    printf("%d\n", htons(-1));//256
    printf("%d\n", htonl(1));
    printf("%d\n", inet_addr("0.0.0.0"));
    printf("%s\n",s);
    bzero(s, sizeof(s));
    printf("%s\n",s);
    printf("OK\n");
    return 0;
}