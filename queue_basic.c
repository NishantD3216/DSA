#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
struct queue
{
    int data[SIZE];
    int front,rear;
};
int isfull(struct queue *qptr)
{
    if(qptr->rear==SIZE)
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
void enqueue(struct queue *qptr,int num)
{
    if(isfull(qptr))
    {
        printf("Queue overflow\n");
    }
    else
    {
        qptr->rear++;
        qptr->data[qptr->rear]=num;
    }
}
int dequeue(struct queue *qptr,int num)
{
    if(isempty(qptr))
    {
        printf("Queue underflow\n");
    }
    else
    {
        qptr->front++;
        num=qptr->data[qptr->front];
    }
    return num;
}
void display(struct queue *qptr)
{
    int i;
    if(isempty(qptr))
    {
        printf("Queue empty\n");
    }
    else
    {
        printf("Queue data\n");
        for(i=qptr->front+1;i<=qptr->rear;i++)
        {
            printf("%d\n",qptr->data[i]);
        }
    }
}

int main()
{
    struct queue *qptr,q;
    qptr=&q;
    qptr->front=-1;
    qptr->rear=-1;
    int ch,num;
    while(1)
    {
        printf("Queue menu\n");
        printf("1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        printf("Enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the data\n");
            scanf("%d",&num);
            enqueue(qptr,num);
            break;
            case 2:num=dequeue(qptr,num);
            printf("removed data is %d\n",num);
            break;
            case 3: display(qptr);
            break;
            case 4: exit(0);
            default:printf("Invalid choice\n");
            break;

        }
    }
    return 0;
}
