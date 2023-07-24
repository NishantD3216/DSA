#include<stdio.h>
#include<stdlib.h>
#define size 10
struct queue
{
    int data[size];
    int front;
    int rear;
};
int isempty(struct queue *qptr)
{
    if(qptr->rear==-1&&qptr->front==-1)
        return 1;
    else
        return 0;
}
int isfull(struct queue *qptr)
{
    if((qptr->rear+1)%size==qptr->front)
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
        printf("queue overflow\n");
    else
    {
        qptr->rear=(qptr->rear+1)%size;
        qptr->data[qptr->rear]=num;
    }
}
int dequeue(struct queue *qptr)
{int num=-1;
    if(isempty(qptr))
       return num;

    else if(qptr->front==qptr->rear)
       {
           num=qptr->data[qptr->front];
           qptr->front=qptr->rear=-1;
      }

    else
    {

        num= qptr->data[qptr->front];
        qptr->front=(qptr->front+1)%size;
    }
    return num;
}
void display(struct queue *qptr)
{
    int i;
    i=qptr->front;
    if(isempty(qptr))
        printf("queue is empty\n");
    else
    {
        while(i!= qptr->rear)
        {
            printf("%d\n",qptr->data[i]);
                i=(i+1)%size;
        }
        printf("%d",qptr->data[i]);
    }
}


int main()
{
    FILE *fp1;
    struct queue s,*qptr;
    qptr=&s;
    qptr->rear=-1;
    qptr->front=-1;
    int ch,num,x;
    fp1=fopen("data.txt","r");
    if(fp1==NULL)
    {
        printf("File does not exist\n");
        exit(0);
    }
    while(1)
    {
        printf("\n1 :dequeue 2 :dispaly 3 : enqueue 4 :exit\n");
        printf("enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
               case 1:x=dequeue(qptr);
               printf("%d",x);
               break;
               case 2 :
                   printf("Elements are \n");
                   display(qptr);
               break;
               case 3 :fscanf(fp1,"%d",&num);
                       enqueue(qptr,num);
               break;
               case 4:exit(0);
        }
    }
    fclose(fp1);
    return 0;
}
