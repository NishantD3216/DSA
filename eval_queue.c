#include<stdio.h>
#include<stdlib.h>
#define SIZE 100


struct queue
{
    int m;
    int name[SIZE];
    int front,rear;
};

void enqueue(struct queue *qptr,int N)
{
    qptr->rear++;
    qptr->name[qptr->rear]=N;
}


void cal(struct queue *qptr,int x,int m)
{
    if(x>m)
    {
        display(qptr);
    }
    else if(x==m)
    {
        printf("Gate queue empty\n");
    }
    else if(x<(qptr->m))
    {
        display2(qptr,x,m);
    }
}
void display(struct queue *qptr)
{
    printf("Ticket numbers of people allowed\n");
    for(int i=qptr->front+1;i<=qptr->rear;i++)
    {
        printf("%d\n",qptr->name[i]);
    }
}
void display2(struct queue *qptr,int x,int m)
{
    int i;
    printf("Remaining people ticket numbers\n");
    for(i=m-x;i<m;i++)
    {
        printf("%d\n",qptr->name[i]);
    }
}
int main()
{
    int x,m;
    int N;
    struct queue q,*qptr;
    qptr=&q;
    qptr->front=-1;
    qptr->rear=-1;
    printf("Enter the number of people at the gate\n");
    scanf("%d",&m);
    printf("Enter their ticket numbers\n");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&N);
        enqueue(qptr,N);
    }
    printf("Enter the number of people allowed to pass the gate\n");
    scanf("%d",&x);
    cal(qptr,x,m);

    return 0;
}

