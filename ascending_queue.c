#include<stdio.h>
#include<stdlib.h>
#define size 10

struct queue
{
    int data[size];
    int front;
    int rear;
};

int isfull(struct queue *qptr)
{
    if(qptr->rear==size-1)
        return 1;
    else
        return 0;
}

int isempty(struct queue *qptr)
{
    if(qptr->front==qptr->rear)
        return 1;
    else
        return 0;
}

void enqueue(struct queue *qptr,int num)
{
    int i;
    if(isfull(qptr))
        printf("Queue overflow\n");
    else
    {
        i=qptr->rear;
        qptr->rear++;
        while(i>=0 && qptr->data[i]<=num)
        {
            qptr->data[i+1]=qptr->data[i];
            i--;
        }
        qptr->data[i+1]=num;
    }
}

int dequeue(struct queue *qptr)
{
    int num;
    if(isempty(qptr))
        printf("Queue underflow\n");
    else
    {
        qptr->front++;
        num=qptr->data[qptr->front];
    }
    return num;
}

int getfront(struct queue *qptr)
{
    int num;
    if(isempty(qptr))
        printf("Queue underflow\n");
    else
    {
        num=qptr->data[qptr->front+1];
    }
    return num;
}

int getrear(struct queue *qptr)
{
    int num;
    if(isempty(qptr))
        printf("Queue underflow\n");
    else
    {
        num=qptr->data[qptr->rear];
    }
    return num;
}

void display(struct queue *qptr, FILE *fp1)
{
    if(fp1==NULL)
    {
        printf("File does not exist\n");
        exit(0);
    }
    if(isempty(qptr))
        printf("Queue empty\n");
    else
    {
        printf("\nDescending priority Queue elements are ");
        for(int i=qptr->front+1;i<=qptr->rear;i++)
        {
            printf("%d ",qptr->data[i]);
            fprintf(fp1,"%d ",qptr->data[i]);
        }

    }
}

int main()
{
    FILE *fp1;
    struct queue *qptr,q;
    qptr=&q;
    qptr->front=-1;
    qptr->rear=-1;
    int ch,num;
    fp1=fopen("output_2.txt","w");
    fp1=fopen("output_2.txt","w");

    while(1)
    {
        printf("\nQueue menu list\n");
        printf("1: Enqueue 2: Dequeue 3: Getfront 4: Getrear 5: Display 6: Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the element to enqueue\n");
                   scanf("%d",&num);
                   enqueue(qptr,num);
                   break;
            case 2: num=dequeue(qptr);
            break;
            case 3: num=getfront(qptr);
            printf("Getfront = %d\n",num);
            break;
            case 4: num=getrear(qptr);
            printf("Getrear = %d\n",num);
            break;
            case 5: display(qptr,fp1);
            break;
            default: exit(0);
            break;
        }
    }
    return 0;
    fclose(fp1);
}
