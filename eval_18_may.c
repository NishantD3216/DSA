#include<stdio.h>
#include<math.h>
int main()
{
    int arr1[20],arr3[20],arr2[40],arr4[40];
    int i,j,k=0,count=0,test,digit;
    printf("Enter 20 elements in an array\n");
    for(i=0;i<20;i++)
    {
        scanf("%d",&arr1[i]);
    }
    for(i=0;i<20;i++)
    {
        arr3[i]=arr1[i];
    }
    for(j=0;j<20;j++)
    {
        while(arr1[j]!=0)
        {
            digit=arr1[j]%10;
            arr2[k]=digit;
            k++;
            arr1[j]=arr1[j]/10;
        }
    }
    for(i=0;i<20;i++)
    {
        arr4[i]=arr2[i];
    }
    for(i=0;i<20;i++)
    {
        for(j=0;j<20;i++)
        {
            if(arr2[i]==arr4[j])
            {
                count++;
            }
        }
        printf("repeatation of %d is %d\n",arr2[j],count);
    }
    return 0;
}
