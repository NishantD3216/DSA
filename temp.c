#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void max(int s[100],int n);
int main()
{

    int s[100],m,n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    if(n==0)
    {
        printf("No sound recorded\n");
    }
    if(n>1)
    {
        max(s[100],n);
    }
    return 0;
}
void max(int s[100],int n)
{
    int i,temp,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(s[j]>s[j+1])
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    printf("%d",s[n-1]);
    return 0;
}
