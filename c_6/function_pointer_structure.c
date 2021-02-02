#include<stdio.h>
#define XMAX 10
#define YMAX 20

int main(){
    struct point
    {
        int x;
        int y;
    }pt1, pt2, pt3, pt4;
    pt1.x = pt1.y = pt2.x = pt2.y = 15;

    struct rect
    {
        struct point pt1;
        struct point pt2;
    };

    struct point makepoint(int x, int y){//this is a function that return struct point
        struct point temp;
        temp.x = x;
        temp.y = y;
        return temp;
    };

    struct point addpoint(struct rect add){//we can pass struct as argument also
        add.pt1.x = add.pt1.x + add.pt2.x;
        add.pt1.y = add.pt1.y + add.pt2.y;
        return add.pt1;

    }

    int ptinrect(struct point p, struct rect r){
        return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y; 
    }
    
    struct rect screen;
    struct rect *pp;
    pp = &screen;
    struct rect screen_to_assign;
    struct point middle;
    struct point add;


    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(XMAX, YMAX);

    printf("%d %d %d %d\n", screen.pt1.x, screen.pt2.y, screen.pt2.x, screen.pt2.y);

    pt3 = pt2;//we can assign value to struct like this also
    printf("pt3 = pt1 = pt3\t %d %d %d %d %d %d\n",pt1.x, pt1.y, pt2.x, pt2.y, pt3.x, pt3.y);
 
    screen_to_assign = screen;//we can also assign in this way also
    printf("screen_to_assign \t%d %d %d %d\n", screen_to_assign.pt1.x, screen_to_assign.pt1.y, screen_to_assign.pt2.x, screen_to_assign.pt2.y);
    
    pt4.y = 15;
    pt4.x = pt4.x;
    printf("pt3 = pt1 = pt3 = pt4\t %d %d %d %d %d %d\n",pt1.x, pt1.y, pt2.x, pt2.y, pt3.x, pt3.y, pt4.x, pt4.y);


    middle = makepoint((screen.pt1.x + screen.pt2.x) / 2, (screen.pt1.y + screen.pt2.y) / 2); 
    printf("middle point is = %d %d\n", middle.x, middle.y);

    add = addpoint(screen);
    printf("Add is = %d %d\n", add.x, add.y);

    printf("Points is in rectangle or not %d", ptinrect(pt1, screen));

    printf("points are %d %d %d %d", pp->pt1.x, pp->pt1.y, pp->pt2.x, pp->pt2.y);//use of -> operator
    //pp->pt1.x is equivalent to (*pp).pt1.x

    return 0;
}