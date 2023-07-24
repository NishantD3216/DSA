#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void max(int s[100],int n);
int main()
{

    int s[100];
    int n,i;
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
    int i;
    for (int i = 0; i < n; ++i)
    {
        if (s[0] < s[i])
        {
            s[0] = s[i];
        }
    }
    printf("%d",s[0]);
}
