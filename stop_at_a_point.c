#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void sum(int n,int arr[10]);
int main()
{
    int n,i;
    int arr[10];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    sum(n,arr);
    return 0;
}
void sum(int n,int arr[10])
{
    int i,s=0,count=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
           s=s+arr[i];
           count++;
           if(s>999)
            break;
        }
    }
    if(n>0)
    {
       printf("Sum is %d.\n",s);
       printf("Numbers added %d.\n",count);
    }
    else if(n<=0)
    {
        printf("Invalid input.\n");
    }
}
