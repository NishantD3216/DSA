#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 100

struct queue
{
    int data[SIZE];
    int rear,front;
};

void enqueue(struct queue *qptr,int age)
{
    qptr->rear++;
    qptr->data[qptr->rear]=age;
}

void calculate(struct queue *qptr,int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        if(qptr->data[i]>qptr->data[i+1])
        {
            temp=qptr->data[i];
            qptr->data[i]=qptr->data[i+1];
            qptr->data[i+1]=temp;
        }
    }

}
int dequeue(struct queue *qptr,int hage,int n)
{
    qptr->front++;
    hage=qptr->data[n-1];
    return hage;
}
void display(struct queue *qptr,int n)
{
    int i;
    printf("Remaining devotees: ");
    for(i=0;i<n-1;i++)
    {
        printf("%d ",qptr->data[i]);
    }
}

int main()
{
    struct queue q,*qptr;
    qptr=&q;
    qptr->front=-1;
    qptr->rear=-1;
    int n,i;
    int age,hage;
    scanf("%d",&n);
    if(n>0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&age);
            enqueue(qptr,age);
        }

    }
    calculate(qptr,n);
    hage=dequeue(qptr,hage,n);
    printf("Allowed for worship:%d",hage);
    display(qptr,n);
    return 0;
}

