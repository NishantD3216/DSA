#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*link;
};
typedef struct node *NODE;

NODE create_node();
NODE insert_end(NODE tail);
NODE insert_front(NODE tail);
NODE delete_front(NODE tail);
NODE delete_end(NODE tail);
int count_nodes(NODE tail);
void search_node(NODE tail);
void highest_node(NODE tail);
void lowest_node(NODE tail);
void display_csll(NODE tail);

int main()
{
    NODE tail=NULL;
    int ch,count;
    while(1)
    {
        printf("\nCSLL menu.\n 1: Insert end 2: Insert front 3:Delete front 4: Delete end 5:count nodes 6:Search node 7:highest node 8:lowest node 9:Display 10: Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: tail=insert_end(tail);
            break;
            case 2: tail=insert_front(tail);
            break;
            case 3: tail=delete_front(tail);
            break;
            case 4: tail=delete_end(tail);
            break;
            case 5: count=count_nodes(tail);
            break;
            case 6: search_node(tail);
            break;
            case 7: highest_node(tail);
            break;
            case 8: lowest_node(tail);
            break;
            case 9: display_csll(tail);
            break;
            case 10: exit(0);
            break;
            default: printf("Invalid choice\n");
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
    newnode->link=newnode;
    return newnode;
}

NODE insert_end(NODE tail)
{
    NODE newnode;
    newnode=create_node();
    if(tail==NULL)
    {
        tail=newnode;
    }
    else
    {
        newnode->link=tail->link;
        tail->link=newnode;
        tail=newnode;
    }
    return tail;
}

NODE insert_front(NODE tail)
{
    NODE newnode;
    newnode=create_node();
    if(tail==NULL)
    {
        tail=newnode;
    }
    else
    {
        newnode->link=tail->link;
        tail->link=newnode;
    }
    return tail;
}

NODE delete_front(NODE tail)
{
    NODE cur;
    if(tail==NULL)
    {
        printf("CSLL is empty\n");
    }
    else if(tail->link==tail)
    {
        printf("Deleted %d\n",tail->data);
        free(tail);
        tail=NULL;
    }
    else
    {
        cur=tail->link;
        tail->link=cur->link;
        printf("Deleted %d\n",cur->data);
        free(cur);
    }
    return tail;
}

NODE delete_end(NODE tail)
{
    NODE prev,cur;
    if(tail==NULL)
    {
        printf("CSLL is empty\n");
    }
    else if(tail->link==tail)
    {
        printf("Deleted %d\n",tail->data);
        free(tail);
        tail=NULL;
    }
    else
    {
        prev=NULL;
        cur=tail->link;
        while(cur!=tail)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=tail->link;
        tail=prev;
        printf("Deleted %d\n",cur->data);
        free(cur);
    }
    return tail;
}

int count_nodes(NODE tail)
{
    int count=0;
    NODE cur;
    if(tail==NULL)
    {
        return count;
    }
    else if(tail->link==tail)
    {
        count =1;
    }
    else
    {
        cur=tail->link;
        while(cur!=tail)
        {
            cur=cur->link;
            count++;
        }
        count=count+1;
    }
    printf("Number of nodes is %d\n",count);
}

void search_node(NODE tail)
{
    int key,status=0;
    NODE cur;
    printf("Enter the key\n");
    scanf("%d",&key);
    if(tail==NULL)
    {
        printf("CSLL is empty\n");
    }
    else if(tail->link==tail)
    {
        if(tail->data==key)
        {
            printf("Search successful %d is found\n",key);
        }
        else
        {
            printf("Search unsuccessful %d not found\n",key);
        }
    }
    else
    {
        cur=tail->link;
        while(cur!=tail)
        {
            if(cur->data==key)
            {
                status=1;
                break;
            }
            else
            {
                status =0;
                break;
            }
            cur=cur->link;
        }
        if(tail->data==key)
        {
            status=1;
        }
        if(status==1)
        {
            printf("Search successful %d is found\n",key);
        }
        else
        {
            printf("Search unsuccessful %d is not found\n",key);
        }
    }
}

void highest_node(NODE tail)
{
    NODE cur;
    int highest=0;
    if(tail==NULL)
    {
        printf("CSLL is empty\n");
    }
    else
    {
        cur=tail->link;
       while(cur!=tail)
       {
        if(highest<cur->data)
        {
            highest=cur->data;
        }
        cur=cur->link;
       }
       if(cur->data>highest)
       {
           highest=cur->data;
       }
    }
    printf("Highest %d",highest);
}

void lowest_node(NODE tail)
{
    NODE cur;
    int lowest=999;
    if(tail==NULL)
    {
        printf("CSLL is empty\n");
    }
    else
    {
        cur=tail->link;
       while(cur!=tail)
       {
        if(lowest>cur->data)
        {
            lowest=cur->data;
        }
        cur=cur->link;
       }
       if(cur->data<lowest)
       {
           lowest=cur->data;
       }
    }
    printf("Lowest %d",lowest);
}

void display_csll(NODE tail)
{
    NODE cur;
    if(tail==NULL)
    {
        printf("CSLL is empty\n");
    }
    else
    {
        cur=tail->link;
        while(cur!=tail)
        {
            printf("%d->",cur->data);
            cur=cur->link;
        }
        printf("%d->",cur->data);
    }
}
