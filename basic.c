#include<stdio.h>
#include<stdlib.h>
#define size 20
struct stack
{
    int data[size];
    int top;
};
void push(struct stack *sptr,int element)
{
    if(sptr->top==size-1)
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
        return -1;
    }
    else
    {
       int element=sptr->data[sptr->top];
        sptr->top--;
        return element;
    }
}
int peek(struct stack *sptr)
{
    if(sptr->top==0)
    {
        return 0;
    }
    else
    {
      int element=sptr->data[sptr->top];
        return element;
    }
}
void display(struct stack *sptr)
{
    if(sptr->top==0)
    {
        printf("STACK EMPTY\n");
    }
    else
    {
        for(int i=sptr->top;i!=0;i--)
        {
            printf("%d ",sptr->data[i]);
        }
    }
}
int main()
{
    FILE *fp1;
    struct stack s,*sptr=&s;
    sptr->top=0;
    int ch,element;
    fp1=fopen("data2.txt","r");
    if(fp1==NULL)
    {
        printf("File does not exist\n");
        exit(0);
    }

    while(1)
    {
        printf("\nSTACK MENU\n");
        printf("1.PUSH 2.POP 3.PEEK 4.DISPLAY\n");
        printf("ENTER YOUR CHOICE\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:fscanf(fp1,"%d",&element);
                   push(sptr,element);
                   break;
            case 2:element=pop(sptr);
                   if(element==0)
                   {
                       printf("STACK UNDERFLOW\n");
                   }
                   else
                   {
                       printf("POPPED ELEMENT IS %d\n",element);
                   }
                   break;
            case 3:element=peek(sptr);
                   if(element==0)
                   {
                       printf("STACK EMPTY\n");
                   }
                   else
                   {
                        printf("TOP DATA IS %d\n",element);
                   }
                   break;
            case 4:display(sptr);
                   break;
            case 5:exit(0);
                   break;
            default:printf("INVALID CHOICE \n");
                    break;
        }
    }
    fclose(fp1);
    return 0;
}
