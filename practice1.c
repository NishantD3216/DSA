#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int a[20];
    int top;
};

int main()
{
    struct stack m,n,*sptr1,*sptr2;
    sptr1=&m;
    sptr2=&n;
    int element1,element2,l;
    sptr1->top=-1;
    sptr2->top=-1;
    printf("Enter the element in first array\n");
    for(int i=0;i<5;i++)
    {
        scanf("%d",&element1);
        push1(sptr1,element1);
    }
    printf("Enter the element in second array\n");
    for(int i=0;i<5;i++)
    {
        scanf("%d",&element2);
        push2(sptr2,element2);
    }
    l=pop(sptr1,sptr2,element1,element2);
    element2=l;
    push2(sptr2,element2);
    display(sptr1,sptr2,element1,element2);
    return 0;
}

void push1(struct stack *sptr1,int element1)
{
        sptr1->top++;
        sptr1->a[sptr1->top]=element1;
}
void push2(struct stack *sptr2,int element2)
{
    sptr2->top++;
    sptr2->a[sptr2->top]=element2;
}
int pop(struct stack *sptr1,struct stack *sptr2,int element1,int element2)
{
    int x=sptr1->a[sptr1->top];
    sptr1->top--;
    return x;
}
void display(struct stack *sptr1,struct stack *sptr2,int element1,int element2)
{
    for(int i=sptr1->top;i!=-1;i--)
        {
            printf("%d ",sptr1->a[i]);
        }
        printf("\n");
    for(int i=sptr2->top;i!=-1;i--)
        {
            printf("%d ",sptr2->a[i]);
        }
}

