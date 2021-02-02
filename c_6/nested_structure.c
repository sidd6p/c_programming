#include<stdio.h>
int main(){
    struct point
    {
        int x;
        int y;
    } pt1, pt2;
    pt1.x = 12;
    pt1.y = 22;

    struct rect
    {
        struct point pt1;
        struct point pt2;
        struct point pt3;
    } screen;

    screen.pt1.x = 10;
    screen.pt1.y = 20;
    screen.pt2.x = 11;
    screen.pt2.y = 21;
    printf("%d %d %d %d\n", screen.pt1.x, screen.pt2.y, screen.pt2.x, screen.pt2.y);
    printf("%d %d %d %d", pt1.x, pt1.y, pt2.x, pt2.y);
    return 0;
}