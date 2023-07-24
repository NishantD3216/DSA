#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int arr1[5][5],arr2[5][5];
    int i,j,r,c,count=0,pro;
    printf("Enter the number of rows and columns in a matrix\n");
    scanf("%d%d",&r,&c);
    if(r!=c)
    {
        printf("The given matrix is not a square matrix, hence the symmetry cannot be determined\n ");
        exit(1);
    }
    printf("enter matrix elements \n");
    for (i=0; i<r;i++)
    {
        for(j=0; j<c;j++)
        {
            scanf("%d",& arr1 [i] [j]);
        }
    }
    for (i=0; i<r;i++)
    {
        for(j=0; j<c;j++)
        {
            arr2[i][j]=arr1[i][j];
        }
    }
    for (i=0; i<r;i++)
    {
        for(j=0; j<c;j++)
        {
            if(arr1[j][i]==arr2[i][j])
            {
                count++;
            }
        }
    }
    pro=r*c;
    if(pro==count)
    {
        printf("the given matrix is symmetric(i.e aij equal to aji)\n");
    }
    else
    {
        printf("The given matrix is non symmetric (i.e aij not equal to aji)\n ");
    }

    return 0;
}
