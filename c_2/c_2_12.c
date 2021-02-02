//http://www.learntosolveit.com/cprogramming/Ex_2.9_bitcount2s.define
#include<stdio.h>
unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
int bitcounts(unsigned x);
int imporovedBitcounts(unsigned x);
unsigned deleteRightMost(unsigned x);

int main(){
    printf("Starting\n");
    printf("%d\n", getbits(10, 4, 3));
    //printf("%d\n", setbits(10, 4, 3, 5));
    printf("%d\n", bitcounts(4));
    printf("%d\n", deleteRightMost(4));
    printf("%d\n", imporovedBitcounts(4));
        return 0;

}

unsigned getbits(unsigned x, int p, int n){
    return((x >> (p - n + 1)) & (~(~0 << n)));
}

/*unsigned setbits(unsigned x, int p, int n, unsigned y){
    return();
}*/

/*unsigned invert(unsigned x, int p, int n){
    return((x >> (p + n - 1)) & (~(~0 << n)))
}*/

int bitcounts(unsigned x){
    int counting;
    counting = 0;
    for(counting = 0; x != 0; x >>= 1){
    if(x & 01){
        counting++;
    }
    }
    return counting;
}

unsigned deleteRightMost(unsigned x){
    return(x &= (x - 1));
}

int imporovedBitcounts(unsigned x){
    int counting;
    counting = 0;
    for(counting = 0; x != 0; x &= x - 1){
        counting++;
    }
    return counting;
}
