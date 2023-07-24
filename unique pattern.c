#include<stdio.h>
int main()
{
    int i,j,p,r,k;

    for(p=1,i=1,r=1,k=1;i<=4;i++,r++)
    {
        printf("\n");
        if(r==3)
        r=1;
        for(j=1;j<=4;j++,k++)
        {
            if(k==3)
                k=1;
            p=r*k;
            printf("%d ",p);

        }

    }
    return 0;
}


