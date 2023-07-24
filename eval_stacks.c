#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
struct stack
{
    int a[SIZE];
    int top;
};
int main()
{
    int N,element;
    struct stack s,*sptr;
    sptr=&s;
    sptr->top=-1;
    scanf("%d",&N);

    for(int i=0;i<N;i++)
    {
        scanf("%d",&element);
        push(sptr,element);
    }
    opr(sptr,element,N);
    display(sptr,element,N);

    return 0;
}
void push(struct stack *sptr,int element)
{
    sptr->top++;
    sptr->a[sptr->top]=element;
}
int pop(struct stack *sptr,int element)
{
    element=sptr->a[sptr->top];
    sptr->top--;
    return element;
}
void opr(struct stack *sptr,int element,int N)
{
    int b[SIZE]={0};
    for(int i=0;i<N;i++)
    {
        b[i]=sptr->a[i];
    }
    for(int i=0;i<N;i++)
    {
        if(sptr->a[i]==b[i+1])
        {
            element=pop(sptr,element);
        }
    }

}
void display(struct stack *sptr,int element,int N)
{
    for(int i=sptr->top;i!=-1;i--)
        {
            printf("%d\n",sptr->a[i]);
        }
}

