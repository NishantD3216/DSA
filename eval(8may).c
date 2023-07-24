#include<stdio.h>
#include<stdlib.h>

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
    printf("Enter the data\n");
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

void display(NODE head)
{
    NODE cur;
    if(head==NULL)
        printf("The list is empty\n");
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            printf("%d->",cur->data);
            cur=cur->link;
        }
    }
}

void sorting(NODE head)
{
    NODE t,s;
    int temp;
    t=head;
    while(t!=NULL)
    {
        s=t->link;
        while(s!=NULL)
        {
            if(t->data>s->data)
            {
                temp=t->data;
                t->data=s->data;
                s->data=temp;
            }
            s=s->link;
        }
        t=t->link;
    }
    display(head);
}

int main()
{
    NODE head=NULL;
    int ch;
    while(1)
    {
        printf("\n1:insert end 2:display 3:sorting 4:exit\n") ;
        printf("enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:head=insert_end(head);
            break;
            case 2:display(head);
            break;
            case 3:sorting(head);
            break;
            case 4:exit(0);
            break;
            default:printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}
