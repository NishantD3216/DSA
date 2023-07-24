#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node *NODE;

NODE create_node();
NODE insert_end(NODE head);
void display_list(NODE head);

int main()
{
    int ch;
    NODE head=NULL;
    while(1)
    {
        printf("Singly linked list menu\n");
        printf("1: Insert_end 2:Display 3: Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:head=insert_end(head);
            break;
            case 2:display_list(head);
            break;
            case 3:exit(0);
            break;
            default: printf("INVALID CHOICE\n");
            break;

        }
    }
    return 0;
}
NODE create_node()
{
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("Enter data\n");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    return newnode;
}
NODE insert_end(NODE head)
{
    NODE cur,newnode;
    newnode=create_node();
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        cur=head;
        while(cur->link!=NULL)
        {
            cur=cur->link;
        }
        cur->link=newnode;
    }
    return head;

}
void display_list(NODE head)
{
    NODE cur=head;
    if(head==NULL)
    {
        printf("Singly linked list is empty\n");
    }
    else
    {
        while(cur!=NULL)
        {
            printf("%d->",cur->data);
            cur=cur->link;
        }
    }
}
