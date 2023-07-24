//program to find the area of circle and area of rectangle//
/*  Name: Swaraj H
    Division: P
    Roll no: 1667
    Program name: area
*/
#include<stdio.h>
#include<math.h>
int main()
{
    float area1,area2,p=3.1412,r,w,l;
    printf("enter radius of circle=");
    scanf("%f",&r);
    printf("enter width of rectangle=");
    scanf("%f",&w);
    printf("enter the length of the triangle=");
    scanf("%f",&l);
    area1=p*r*r;
    area2=w*l;
    printf("area of the circle is=%f\n",area1);
    printf("area of the rectangle is=%f",area2);
    return 0;
}
