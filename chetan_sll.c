#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
typedef struct node *NODE;

NODE create_node()
{
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("memory not allocated\n");
        exit(0);
    }
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    return newnode;
}

NODE insert_end(NODE head)
{
    NODE newnode,cur;
    newnode=create_node();
    if(head==NULL)
        head=newnode;
    else
    {
        cur=head;
        while(cur->link!=NULL)
            cur=cur->link;
        cur->link=newnode;
    }
    return head;
}

NODE delete_front(NODE head)
{
    NODE cur;
    if(head==NULL)
        printf("list is empty\n");
    else if(head->link==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        cur=head;
        head=head->link;
        cur->link=NULL;
        free(cur);
    }
    return head;
}

void display(NODE head)
{
    NODE cur;
    if(head==NULL)
        printf("list is empty\n");
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            printf("%d ",cur->data);
            cur=cur->link;
        }
    }
}

int main()
{
    NODE head1,head2;
    head1=NULL;
    head2=NULL;
    int m,n,x,y;

    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++)
    {
        head1=insert_end(head1);
    }
    for(int k=0;k<n;k++)
    {
        head2=insert_end(head2);
    }

    scanf("%d%d",&x,&y);

    if(m>x&&n>y)
    {
        for(int j=0;j<x;j++)
        head1=delete_front(head1);

    for(int l=0;l<y;l++)
        head2=delete_front(head2);

        display(head1);
        printf("\n");
        display(head2);
    }
    else if(m==x&&n>y)
    {
        for(int j=0;j<x;j++)
        head1=delete_front(head1);

    for(int l=0;l<y;l++)
        head2=delete_front(head2);

        printf("Gate 1 empty.\n");
        display(head2);
    }
    else if(m>x&&n==y)
    {
        for(int j=0;j<x;j++)
        head1=delete_front(head1);

    for(int l=0;l<y;l++)
        head2=delete_front(head2);

        display(head1);
        printf("\n");
        printf("Gate 2 empty.\n");
    }
    else if(m<n&&n<y)
    {
        for(int j=0;j<x;j++)
        head1=delete_front(head1);

    for(int l=0;l<y;l++)
        head2=delete_front(head2);

        printf("Gate 1 empty.\n");
        printf("Gate 2 empty.");
    }
    else if(m>x&&n<y)
    {
        for(int j=0;j<x;j++)
        head1=delete_front(head1);

        display(head1);
        printf("\n");
        display(head2);

    }
    else if(m<x&&n>y)
    {
        display(head1);
        printf("\n");

        for(int l=0;l<y;l++)
        head2=delete_front(head2);
        display(head2);
    }
    return 0;
}
