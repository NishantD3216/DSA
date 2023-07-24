#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
struct queue
{
    int roll_no[SIZE];
    int front, rear;
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
int dequeue(struct queue *qptr,int num2)
{
    qptr->front++;
    num2=qptr->roll_no[qptr->front];
    return num2;
}
int main()
{
    int n,i,num,x,num2;
    struct queue q,*qptr;
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
    x=dequeue(qptr,num2);
    printf("removed element=%d\n",x);
    display(qptr);
    return 0;
}
