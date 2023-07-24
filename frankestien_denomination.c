#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define size 100
void count(struct stack *sptr,int n);
struct stack
{
    int data[size];
    int top;
};
int main()
{
    int n;
    struct stack s,*sptr=&s;
    sptr->top=-1;

    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&sptr->data[i]);
    }
    if(n<=0)
    {
        printf("Invalid number of coins\n");
    }
    else
    {
        count(sptr,n);
    }
    return 0;
}
void count(struct stack *sptr,int n)
{
    int count1=0,count2=0,count5=0,count10=0,countz=0;
    for(int i=0;i<n;i++)
    {
        if(sptr->data[i] == 1)
        {
            count1++;
        }
        else if(sptr->data[i] == 2)
        {
            count2++;
        }
        else if(sptr->data[i] == 5)
        {
            count5++;
        }
        else if(sptr->data[i] == 10)
        {
            count10++;
        }
        else
        {
            countz++;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("Coins of 1 re = %d\nCoins of 2 rs = %d\nCoins of 5 rs = %d\nCoins of 10 rs = %d\nCoins of invalid denominations = %d\n",count1,count2,count5,count10);
    }
}
