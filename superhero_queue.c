#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 1000

struct queue
{
    int data[SIZE];
    int front,rear;
};

void enqueue(struct queue *qptr,int num)
{
    qptr->rear++;
    qptr->data[qptr->rear]=num;
}
int dequeue(struct queue *qptr,int num2)
{
    qptr->front++;
    num2=qptr->data[qptr->front];
    return num2;
}
int main()
{
    struct queue q,*qptr;
    qptr=&q;
    qptr->front=-1;
    qptr->rear=-1;
    int n,i,num,num2,sumk,sums,a;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        enqueue(qptr,num);
    }
    sums=0;
    sumk=0;
    for(int j=0;j<n;j++)
    {
        num2=dequeue(qptr,num2);
        if(num2%3==0)
        {
            sumk=sumk+num2;
        }
        else if((num2*num2)%2==0)
        {
            sums=sums+num2;
        }
        else
        {
            a++;
        }
    }
    if(sums>sumk)
    {
        printf("Shaktiman");
    }
    else
    {
        printf("krrish");
    }

    return 0;
}

