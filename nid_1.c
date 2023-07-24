#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

struct queue
{
    int roll_no[SIZE];
    int front,rear;
};



void enqueue(struct queue *qptr,int num)
{
    qptr->rear++;
    qptr->roll_no[qptr->rear]=num;
}

void display(struct queue *qptr)
{
    int i;
    printf("\n");
    for(i=qptr->front+1;i<=qptr->rear;i++)
    {
        printf("%d\n",qptr->roll_no[i]);
    }
}

void dequeue(struct queue *qptr,int num)
{
    qptr->front++;
    num=qptr->roll_no[qptr->front];
}
int main()
{
    int i,n,num;
    struct queue q ,*qptr;
    qptr=&q;
    qptr->front=-1;
    qptr->rear=-1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        enqueue(qptr,num);
    }
    display(qptr);
    for(i=0;i<2;i++)
    {
        dequeue(qptr,num);
    }
    display(qptr);
    return 0;
}
