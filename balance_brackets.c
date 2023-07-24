#include<stdio.h>
#include<stdlib.h>
#define size 20

struct stack
{
    char data[size];
    int top;
};

void push(struct stack *sptr,char ch)
{
    if(sptr->top==size-1)
    {
        printf("STACK OVERFLOW\n");
    }
    else
    {
        sptr->top++;
        sptr->data[sptr->top]=ch;
    }
}

char pop(struct stack *sptr)
{
    char ch;
    if(sptr->top==-1)
    {
        printf("STACK UNDERFLOW\n");
    }
    else
    {
        ch=sptr->data[sptr->top];
        sptr->top--;
        return ch;
    }
}

int balanced(char expression[size])
{
    struct stack s,*sptr;
    sptr=&s;
    sptr->top=-1;
    char ch;
    int i=0;
    while(expression[i]!='\0')
    {
        if(expression[i]=='('||expression[i]=='{'||expression[i]=='[')
            push(sptr,expression[i]);
        else if(expression[i]==')')
        {
            if(sptr->top==-1)
                return 0;
            ch=pop(sptr);
            if(ch!='(')
                return 0;
        }
          else if(expression[i]==']')
          {
              if(sptr->top==-1)
                return 0;
              ch=pop(sptr);
              if(ch!='[')
                return 0;
          }
          else if(expression[i]=='}')
          {
              if(sptr->top==-1)
                return 0;
              ch=pop(sptr);
              if(ch!='{')
                return 0;
          }
          i++;
    }
    if(sptr->top==-1)
        return 1;
    else
        return 0;
}

int main()
{
    int status;
    char expression[size];
    printf("enter an expression\n");
    scanf("%s",expression);
    status=balanced(expression);
    if(status==1)
        printf("balanced expression\n");
    else
        printf("Not a balanced expression\n");
    return 0;
}
