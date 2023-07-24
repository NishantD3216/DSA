#include <stdio.h>
#define ROW 10
#define COL 10

void read_2darray(int matrix [ROW][COL],int r,int c);
void display_2darray(int matrix [ROW][COL],int r, int c);
void sum(int matrix [ROW][COL],int r, int c);

int main()
{
    int r,c;
    int matrix [ROW] [COL];
    printf ("Enter rows and columns for a 2D array\n");
    scanf("%d%d",&r,&c);
    read_2darray(matrix,r,c);
    display_2darray(matrix,r,c);
    sum(matrix,r,c);
    return 0;
}
void read_2darray(int matrix [ROW][COL],int r,int c)
{
    int i,j;
    printf("enter matrix elements \n");
    for (i=0; i<r;i++)
    {
        for(j=0; j<c;j++)
        {
            scanf("%d",& matrix [i] [j]);
        }
    }

}
void display_2darray(int matrix [ROW][COL],int r,int c)
{
    int i,j;
    printf("The matrix elements are\n");
    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
        {
            printf ("|%d| ", matrix [i] [j]);
        }
        printf("\n");
    }
}
void sum(int matrix [ROW][COL],int r, int c)
{
    int i,j,sum=0;
    for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
        {
            sum=sum+matrix[j][i];
        }
    }
    printf("\nSUM=%d\n",sum);
}
