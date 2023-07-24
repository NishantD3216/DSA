#include<stdio.h>
int smallest(int a,int b);
int largest(int a,int b);
int main()
{
    int a,b,l,s;
    printf("Enter two nos\n");
    scanf("%d%d",&a,&b);
    s=smallest(a,b);
    l=largest(a,b);
    printf("Smallest=%d\n",s);
    printf("Largest=%d\n",l);
    return 0;
}
int smallest(int a,int b)
{
    int s;
    s=(a<b)?a:b;
    return s;
}
int largest(int a,int b)
{
    int l;
    l=(a>b)?a:b;
    return l;
}
