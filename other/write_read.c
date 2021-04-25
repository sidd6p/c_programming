#include<stdio.h>
#include<unistd.h>
int main(){
    int size_1;
    size_t size_2, size_3, size_4, size_5, size_6, size_7;
    size_t size_8, size_9, size_10, size_11, size_12, size_13;
    char buff[20];
    int count_1;


    write(1, "WRITE() SYSTEM CALL.....\n", 50);

    size_1 = write(1, "Hello", 5); //Hello
    printf("\t%d\n", size_1);//size_1 will be 5

    size_2 = write(1, "how.....", 5); //how..
    printf("\t%d\n", size_2); //size_2 will be 5

    size_3 = write(1, "are", 50); //are#%#$#@#$^$$^....
    printf("\t%d\n", size_3); //size_3 will be 50

    size_4 = write(4, "you", 5); //write() will  return error.
    printf("\t%d\n", size_4); //size_4 will be -1

    size_5 = write(1, "?", 50); //?$%^%^$^##@$%$^#$....
    printf("\t%d\n", size_5); //size_5 will be 50

    //size_6 = write(0, "Bye", 5); // undefined nature
    //printf("%d", size_6); // garbage value

    size_7 = write(1, "This will get print", 5); // count will be of last write() call by default it is 0
    printf("%d", size_7);

    write(1, "\nREAD() SYSTEM CALL", 20);

    size_8 = read(0, buff, 10);
    printf("%d", size_8);

    printf("ok\n");

    size_9 = read(0, buff, count_1);
    printf("%d", size_9);
    size_10 = write(1, buff, size_9);

    return 0;
}
