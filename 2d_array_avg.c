#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void read(int matrix[10][10],int N,int X);
void display(int matrix[10][10],int N,int X);
void avg1(int matrix[10][10],int N,int X);
void avg2(int matrix[10][10],int N,int X);
int main()
{
   int N,X;
   int matrix[10][10];
   scanf("%d%d",&N,&X);
    if(N>0&&X>0)
    {
        read(matrix,N,X);
        display(matrix,N,X);
        avg1(matrix,N,X);
        avg2(matrix,N,X);
    }
    else
    {
        printf("Invalid input\n");
    }

    return 0;
}
void read(int matrix[10][10],int N,int X)
{
    int i,j;
    for (i=0; i<N;i++)
    {
        for(j=0; j<X;j++)
        {
            scanf("%d",& matrix [i] [j]);
        }
    }
}
void display(int matrix[10][10],int N,int X)
{
    int i,j;
    for (i=0;i<N;i++)
    {
        for (j=0;j<X;j++)
        {
            printf ("%d ", matrix [i] [j]);
        }
        printf("\n");
    }
}
void avg1(int matrix[10][10],int N,int X)
{
    int i,j,max=0;;
    int colsum[10]={0};
    float avg[10]={0};
    for(i=0;i<X;i++)
    {
        for(j=0;j<N;j++)
        {
            colsum[i]=colsum[i]+matrix[j][i];
        }
    }
    printf("Internal Evaluation average: ");
    for(i=0;i<X;i++)
    {
        avg[i]=(float)colsum[i]/N;
        printf("%0.4f ",avg[i]);
    }
}
void avg2(int matrix[10][10],int N,int X)
{
    int i,j,max=0;
    int rowsum[10]={0};
    float avg[10]={0};
    for(i=0;i<N;i++)
    {
        for(j=0;j<X;j++)
        {
            rowsum[i]=rowsum[i]+matrix[i][j];
        }
    }
    printf("\nStudents average: ");
    for(i=0;i<N;i++)
    {
        avg[i]=(float)rowsum[i]/X;
        printf("%0.4f ",avg[i]);
    }
}
