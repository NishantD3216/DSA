// Program to compute distance traveled by Audi car //
/*  Name: Swaraj H
    Division: P
    Roll no: 1667
    Program name: Audi car
*/
#include<stdio.h>
int main()
{
    int mileage=14;
    float petrol_price,worth_of_petrol,distance,fuel;
    worth_of_petrol=1066.64;
    printf("Enter the price of petrol\n");
    scanf("%f",& petrol_price);
    fuel=worth_of_petrol/petrol_price;
    distance=fuel*mileage;
    printf("Distance traveled by Audi=%f\n",distance);
    if(distance>=92)
        {
        printf("YES, car will reach Belgaum");
        }
    if(distance<=92)
        {
        printf("NO, car will not reach Belgaum");
        }
    return 0;

}
