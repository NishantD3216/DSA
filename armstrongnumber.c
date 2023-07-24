#include<stdio.h>
#include<math.h>
int main()
{
    int n,sum=0,count=0,digit=0,x,r;
    printf("Enter n=");
    scanf("%d",&n);
    x=n;
    r=x;
    while(n!=0)
    {
        digit=n%10;
        count++;
        n=n/10;
    }
    while(x!=0)
    {
        digit=x%10;
        sum=sum+pow(digit,count);
        x=x/10;
    }
    printf("sum=%d\n",sum);
    if(sum==r)
    {
        printf("It is an armstrong number");
    }
    else
    {
        printf("Not an armstrong number");
    }
    return 0;
}
