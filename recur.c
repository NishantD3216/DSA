#include<stdio.h>
void recur1(int n)
{

    if(n>0)
    {
        printf("%d",n);
        recur1(n-1);
    }
}
void recur2(int n)
{
    if(n>0)
    {
        for(int i=0;i<n;i++)
        {
            printf("%d",n);
        }
        recur2(n-1);
    }
}
void recur3(int n)
{
    if(n>0)
    {
        for(int i=1;i<n;i=i*2)
        {
            printf("%d",n);
        }
        recur3(n-1);
    }
}
void recur4(int n)
{
    if(n>0)
    {
        printf("%d",n);
        recur4(n-1);
        recur4(n-1);
    }
}
int main()
{
    int n;
    printf("enter n=");
    scanf("%d",&n);
    printf("first eg\n");
    recur1(n);
    printf("\nsecond eg\n");
    recur2(n);
    printf("\nthird ex\n");
    recur3(n);
    printf("\nfourth ex\n");
    recur4(n);
    return 0;
}

