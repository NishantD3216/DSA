#include<stdio.h>
#include<string.h>

int main()
{
    char alpha[20];
    int i,j,t;
    printf("Enter:");
    scanf("%s",alpha);
    for(int i=0;alpha[i]!='\0';i++)
{
        for(int j=0;alpha[j]!='\0';j++)
    {
            if(alpha[i]<alpha[j])
        {
           t=alpha[i];
           alpha[i]=alpha[j];
           alpha[j]=t;
        }
    }

}
printf("%s",alpha);
}
