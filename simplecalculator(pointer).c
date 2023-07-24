#include<stdio.h>
#include<stdlib.h>
void cal(int *ptr1,int *ptr2,float *r,char opr);
int main()
{
    int num1,num2;
    int *ptr1,*ptr2;
    float res;
    float *r;
    ptr1=&num1;
    ptr2=&num2;
    r=&res;
    char opr;
    printf("Enter operation=\n");
    scanf("%c",&opr);
    printf("Enter the first number=\n");
    scanf("%d",&num1);
    printf("Enter the second number=\n");
    scanf("%d",&num2);
    cal(ptr1,ptr2,r,opr);
    printf("result=%f\n",*r);
    return 0;
}
void cal(int *ptr1,int *ptr2,float *r,char opr)
{

    switch(opr)
    {
        case '+':
            *r=*ptr1+*ptr2;
            break;
        case '-':
            *r=*ptr1-*ptr2;
            break;
        case '*':
            *r=(*ptr1)*(*ptr2);
            break;
        case '/':
            if(*ptr2==0)
            {
                printf("infinity\n");
                exit(0);
            }
            else
            {
                *r=(*ptr1)/(*ptr2);
            }
            break;
        default:printf("invalid input");
            break;
    }

}
