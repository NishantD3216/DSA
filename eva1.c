#include<stdio.h>
#include<stdlib.h>
void reada(int a[10][10],int N,int X);
void readb(int b[10][10],int O,int P);
void display(int a[10][10],int b[10][10],int O,int P,int N,int X);
void mul(int a[10][10],int b[10][10],int O,int P,int N,int X);
int main()
{
    int a[10][10], b[10][10];
    int N,X,O,P;
    printf("Enter the number of rows and columns in 'A' matrix\n");
    scanf("%d%d",&N,&X);
    printf("Enter the number of rows and columns in 'B' matrix\n");
    scanf("%d%d",&O,&P);
    reada(a,N,X);
    readb(b,O,P);
    display(a,b,O,P,N,X);
    mul(a,b,O,P,N,X);
    return 0;

}
void reada(int a[10][10],int N,int X)
{
    int i,j;
    printf("Enter elements in A\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<X;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

}
void readb(int b[10][10],int O,int P)
{
    int i,j;
    printf("Enter elements in B\n");
    for(i=0;i<O;i++)
    {
        for(j=0;j<P;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }


}
void display(int a[10][10],int b[10][10],int O,int P,int N,int X)
{
    int i,j;
    printf("array a=\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<X;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("array b=\n");
    for(i=0;i<O;i++)
    {
        for(j=0;j<P;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
}
void mul(int a[10][10],int b[10][10],int O,int P,int N,int X)
{
    int mul[10][10];
    int i,j,k;
    printf("multiply of the matrix=\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<X;j++)
        {
            mul[i][j]=0;
            for(k=0;k<X;k++)
                {
                    mul[i][j]+=a[i][k]*b[k][j];
                }
        }
    }
//for printing result
    for(i=0;i<N;i++)
    {
        for(j=0;j<X;j++)
        {
            printf("%d\t",mul[i][j]);
        }
        printf("\n");
    }
}
