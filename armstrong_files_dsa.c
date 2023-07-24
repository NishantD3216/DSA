#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define size 20

struct stack
{
    int data[size];
    int top;
};


void push(struct stack *sptr, int element)
{
    if(sptr->top==size)
    {
        printf("STACK OVERFLOW\n");
    }
    else
    {
        sptr->top++;
        sptr->data[sptr->top]=element;
    }
}

int pop(struct stack *sptr)
{
    if(sptr->top==0)
    {
        return 0;
    }
    else
    {
        int element=sptr->data[sptr->top];
        sptr->top--;
        return element;
    }
}
void display(struct stack *sptr)
{
    if(sptr->top==0)
    {
        printf("Stack empty\n");
    }
    else
    {
        for(int i=sptr->top;i!=0;i--)
        {
            printf("%d\t",sptr->data[i]);
        }
    }
}
void popandcheck(struct stack *sptr)
{
    int element,x,r,count=0,digit,sum=0;
    element=sptr->data[sptr->top];
    sptr->top--;
    x=element;
    r=x;
    while(element!=0)
    {
        digit=element%10;
        count++;
        element=element/10;
    }
    while(x!=0)
    {
        digit=x%10;
        sum=sum+pow(digit,count);
        x=x/10;
    }
    if(sum==r)
    {
        printf("the popped element %d is an armstrong number\n",r);
    }
    else
    {
        printf("the popped element %d is not an armstrong number\n",r);
    }
}
int main()
{
    struct stack s, *sptr=&s;
    sptr->top=0;
    int element, ch;

    while(1)
    {
        printf("\nEnter your choice\n");
        printf("1.push 2.pop 3.display 4.pop and check 5. exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:scanf("%d",&element);
        push(sptr,element);
        break;
        case 2: element=pop(sptr);
        if(element==0)
        {
            printf("Stack underflow\n");
        }
        else
        {
            printf("Popped element is %d\n", element);
        }
        break;
        case 3: display(sptr);
        break;
        case 4:popandcheck(sptr);
        break;
        case 5: exit(0);
        }
    }
    return 0;
}
