#include<stdio.h>
#include<stdlib.h>
#define size 100
 struct queue
{
    int data[size];
    int front,rear;
};
void enqueue(struct queue *qptr,int num)
{
    if(isfull(qptr))
        printf("QUEUE OVERFLOW\n");
    else
    {
       qptr->rear++;
       qptr->data[qptr->rear]=num;
    }
}

int dequeue(struct queue *qptr)
{
    int a;
    if(isempty(qptr))
        printf("QUEUE UNDERFLOW\n");
    else
    {
        qptr->front++;
        a=qptr->data[qptr->front];
    }
    return a;
}
void display(struct queue *qptr)
{
    if(isempty(qptr))
        printf("Gate Queue Empty\n");
    else
    {
        printf("ELEMENTS IN QUEUE\n");
        for(int i=qptr->front+1;i<=qptr->rear;i++)
            printf("%d\t",qptr->data[i]);
    }
}
int isfull(struct queue *qptr)
{
    if(qptr->rear==size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty(struct queue *qptr)
{
    if(qptr->front==qptr->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void protocol(struct queue *qptr,int m,int x)
{
    int a;
    if(x>m)
    {
        display(qptr);
    }
    else if(x==m)
    {
        for(int i=0;i<m;i++)
        {
            a=dequeue(qptr);
        }
        display(qptr);
    }
    else
    {
        for(int i=0;i<x;i++)
        {
            a=dequeue(qptr);
        }
        display(qptr);
    }
}
int main()
{
    struct queue q,*qptr=&q;
    qptr->rear=-1;
    qptr->front=-1;
    int m,x,n;
    printf("ENTER M AND X VALUES\n");
    scanf("%d%d",&m,&x);
    for(int i=0;i<m;i++)
    {
        printf("ENTER THE TICKET NUMBER\n");
        scanf("%d",&n);
        enqueue(qptr,n);
    }
    protocol(qptr,m,x);
    return 0;
}
