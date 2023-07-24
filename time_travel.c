#include<stdio.h>
int leap(int year);
int main()
{
    int year,date;
    printf("Enter the year to time travel\n");
    scanf("%d",&year);
    date=leap(year);
    printf("DATE=%d%d",date,year);
    return 0;
}
int leap(int year)
{
    int date;
    if((year%400==0) ||( (year/4==0) && (year%100!=0)))
    {
        date=1209;
        return date;
    }
    else
    {
        date=1309;
        return date;
    }
}
