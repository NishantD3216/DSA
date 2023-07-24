#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*link;
};
typedef struct node*NODE;

NODE create_node();
NODE insert_end(NODE head);
void display_list(NODE head);
NODE insert_front(NODE head);
NODE delete_end(NODE head);
NODE delete_front(NODE head);
int count_nodes(NODE head);
void search_node(NODE head);

int main()
{
    NODE head=NULL;
    int ch,c;
    while(1)
    {
        printf("\nSingly Linked List Menu\n");
        printf("1:Insert_end\t2:Insert_front\t3:Display_list\t4:Delete_end\t5:Delete_front\t6:Count_nodes\t7:Search_node\t8:Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:head=insert_end(head);
                    break;
            case 2:head=insert_front(head);
                    break;
            case 3:display_list(head);
                    break;
            case 4:head=delete_end(head);
                    break;
            case 5:head=delete_front(head);
                    break;
            case 6:c=count_nodes(head);
                    break;
            case 7:search_node(head);
                    break;
            case 8:exit(0);
                    break;
            default:printf("Invalid choice\n");
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
    printf("Enter data:\n");
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

NODE insert_front(NODE head)
{
    NODE newnode;
    newnode=create_node();
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->link=head;
        head=newnode;
    }
    return head;
}

void display_list(NODE head)
{
    NODE cur=head;
    if(head==NULL)
    {
        printf("Singly Linked List is empty\n");
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

NODE delete_end(NODE head)
{
    NODE prev,cur;
    if(head==NULL)
    {
        printf("Singly Linked List is empty\n");
    }
    else if(head->link==NULL)
    {
        printf("Deleted %d\n",head->data);
        free(head);
        head=NULL;
    }
    else
    {
        prev=NULL;
        cur=head;
        while(cur->link!=NULL)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=NULL;
        printf("Deleted %d\n",cur->data);
        free(cur);
    }
    return head;
}

NODE delete_front(NODE head)
{
    NODE cur;
    if(head==NULL)
    {
        printf("Singly Linked List is empty\n");
    }
    else if(head->link==NULL)
    {
        printf("Deleted %d\n",head->data);
        free(head);
        head=NULL;
    }
    else
    {
        cur=head;
        head=head->link;
        printf("Deleted %d\n",cur->data);
        cur->link=NULL;
        free(cur);
    }
    return head;
}

int count_nodes(NODE head)
{
    int count=0;
    NODE cur;
    if(head==NULL)
    {
        return count;
    }
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            count++;
            cur=cur->link;
        }
    }
    printf("Number of nodes is %d\n",count);
    return count;
}

void search_node(NODE head)
{
    int status=0,key;
    NODE cur;
    printf("Enter the number to search:\n");
    scanf("%d",&key);
    if(head==NULL)
    {
        printf("Singly Linked List is empty\n");
    }
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            if(cur->data==key)
            {
                status=1;
                break;
            }
            cur=cur->link;
        }
        if(status==1)
        {
            printf("Search successful, %d found\n",key);
        }
        else
        {
            printf("Search unsuccessful, %d not found\n",key);
        }
    }
}
