#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 1000
struct numbers
{
    int data[MAX];
    int top;
};
void push(struct numbers *ptr,int elem);
int pop(struct numbers *ptr);
void crush(struct numbers * org,struct numbers *temp);
void stackrev(struct numbers *org,struct numbers *dest);
int isempty(struct numbers *ptr);
int peek(struct numbers *ptr);

int main() {
    int N,elem;
    scanf("%d",&N);
    struct numbers input,original,temp;
    input.top=-1;
    original.top=-1;
    temp.top=-1;
    for(int i=0;i<N;i++)
    {
        scanf("%d",&elem);
        push(&input,elem);

    }
    stackrev(&input,&original);

    crush(&original,&temp);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
void push(struct numbers *ptr,int elem)
{
    if(ptr->top<MAX-1)
    {
        ptr->top++;
        ptr->data[ptr->top]=elem;
    }
    else
    {
        printf("Stack Overflow\n");
        exit(1);
    }
}
int pop(struct numbers *ptr)
{
    ptr->top--;
    return ptr->data[(ptr->top)+1];
}
void stackrev(struct numbers *org,struct numbers *dest)
{
    while(org->top>-1)
    {
        push(dest,pop(org));
    }
}
void crush(struct numbers * org,struct numbers *temp)
{
    push(temp,pop(org));
    while(org->top>-1)
    {
        if(peek(org)==peek(temp))
        {
            pop(org);
            pop(temp);
        }
        else
        {
            push(temp,pop(org));
        }
    }
    if(isempty(temp))
    {
        printf("Proceed to next level");
    }
    else
    {
        while(temp->top>-1)
        {
            printf("%d\n",pop(temp));
        }
    }
}
int peek(struct numbers *ptr)
{
    return(ptr->data[ptr->top]);
}
int isempty(struct numbers *ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
