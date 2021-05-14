#include<stdio.h>
//https://www.eskimo.com/~scs/cclass/krnotes/sx8e.html
int main(){
    char amessage[] ="hello earth";
    char *pmessage ="hello earth";
    char *pmessage_1;
    pmessage = "now is the time";
    pmessage = "Now is the time";
    //pmessage[0] = 'N;//illegal
    printf("amessage[0] = %c\n", amessage[0]);
    printf("*amessage = %c\n", *amessage);//amessage[0]
    printf("pmessage[0] = %c\n", pmessage[0]);
    printf("*pmessage = %c\n", *pmessage);//pmessage[0]
    amessage[0] = 'H';
    //amessage[0] = "H";//wont work
    printf("amessage[0] = %c\n", amessage[0]);
    printf("*amessage = %c\n", *amessage);//amessage[0]
    //pmessage[0] = 'H';//may or may not work
    printf("pmessage[0] = %c\n", pmessage[0]);
    printf("*pmessage = %c\n", *pmessage);//amessage[0]
    /*	pmessage[0] = 'N'; (which, as you may recall, is equivalent to *pmessage = 'N'),
    it would not necessarily work; we're not allowed to modify that string.
    (One reason is that the compiler might have placed the ``little block of characters'' in read-only memory.
     Another reason is that if we had written
	char *pmessage = "now is the time";
	char *qmessage = "now is the time";
    the compiler might have used the same little block of memory to initialize both pointers,
    and we wouldn't want a change to one to alter the other.)*/

    int *arr_p_i;
    *arr_p_i = 5;
    *arr_p_i = 10;
    //char *arr_p_c;
    //*arr_p_c = 'a';
    //*arr_p_c = 'A';
    printf("arr_p_i = %d\n",arr_p_i);//&arr_p_i[0]
    printf("*arr_p_i = %d\n",*arr_p_i);//arr_p_i[0]
    //printf("arr_p_c = %c\n",arr_p_c);//&arr_p_c
    //printf("*arr_p_c = %c\n",*arr_p_c);//arr_p_c
    return 0;
}
