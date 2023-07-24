#include<stdio.h>
#include<stdlib.h>
#define size 5

struct queue
{
    int data[size];
    int front,rear;
};

int isfull(struct queue *qptr)
{
    if((qptr->rear+1)%size==qptr->front)
        return 1;
    else
        return 0;
}

int isempty(struct queue *qptr)
{
    if(qptr->front==-1&&qptr->rear==-1)
        return 1;
    else
        return 0;
}

void enqueue(struct queue *qptr,int num)
{
    if(qptr->front==-1&&qptr->rear==-1)
    {
        qptr->front=qptr->rear=0;
        qptr->data[qptr->rear]=num;
    }
    else if(isfull(qptr))
        printf("Queue Overflow\n");
    else
    {
        qptr->rear=(qptr->rear+1)%size;
        qptr->data[qptr->rear]=num;
    }
}

int dequeue(struct queue *qptr)
{
    int num=-1;
    if(isempty(qptr))
        return num;
    else if(qptr->rear==qptr->front)
    {
        num=qptr->data[qptr->front];
        qptr->front=qptr->rear=-1;
    }
    else
    {
        num=qptr->data[qptr->front];
        qptr->front=(qptr->front+1)%size;
    }
    return num;
}

void display(struct queue *qptr)
{
    int i;
    if(isempty(qptr))
        printf("Empty\n");
    else
    {
        for(i=qptr->front;i!=qptr->rear;i=(i+1)%size)
            printf("%d ",qptr->data[i]);
        printf("%d ",qptr->data[qptr->rear]);
    }
}

int main()
{
    struct queue *qptr,q;
    qptr=&q;
    qptr->front=-1;
    qptr->rear=-1;
    int num,ch;
    while(1)
    {
        printf("\nQueue menu is\n");
        printf("1:Enqueue\t 2:Dequeue\t 3:display\t 4:exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the data\n");
            scanf("%d",&num);
            enqueue(qptr,num);
            break;
            case 2:num=dequeue(qptr);
            if(num==-1)
                printf("Queue Underflow\n");
            else
                printf("Removed data :%d",num);
            break;
            case 3:display(qptr);
            break;
            case 4:exit(0);
            break;
            default:printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}
