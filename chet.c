#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *rl;
    struct node *ll;
};
typedef struct node *NODE;

int dust=0;
NODE create_node();
NODE insert_end(NODE head);
void display_list(NODE head);
int count_nodes(NODE head);
NODE room_cleaned(NODE head);

NODE create_node()
{
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }

    scanf("%d",&newnode->data);
    newnode->rl=NULL;
    newnode->ll=NULL;
    return newnode;
}

NODE insert_end(NODE head)
{
    NODE newnode,cur;
    newnode=create_node();
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        cur=head;
        while(cur->rl!=NULL)
        {
            cur=cur->rl;
        }
        cur->rl=newnode;
        newnode->ll=cur;
    }
    return head;
}

void display_list(NODE head)
{
    NODE cur;
    if(head==NULL)
    {
        printf("\nThere are no rooms\n");
    }
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            printf("%d->",cur->data);
            cur=cur->rl;
        }
    }
}

int count_nodes(NODE head)
{
    NODE cur;
    int count=0;
    if(head==NULL)
        return count;
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            count++;
            cur=cur->rl;
        }
    }
    printf("\nno of nodes=%d",count);
    return count;
}

NODE room_cleaned(NODE head)
{
    NODE cur,prev,next;
    int pos,count;
    count=count_nodes(head);
    prev=NULL;
    next=NULL;
    cur=head;

    printf("\nEnter the room number \n");
    scanf("%d",&pos);

    if(head==NULL)
        printf("\nThere are no rooms to clean\n");
    else if(pos==1)
    {
        if((head->rl==NULL)&&(head->ll==NULL))
            return head;
        else
        {
            next=head->rl;
            dust=dust+next->data;
            next->data=0;
        }
    }
    else if(pos==count)
    {
        if(head->rl==NULL&&head->ll==NULL)
            return head;
        else
        {
            while(cur->rl!=NULL)
                cur=cur->rl;
            prev=cur->ll;
            dust=dust+prev->data;
            prev->data=0;
        }
    }
    else if(pos>1&&pos<count)
    {
        for(int i=1;i<pos;i++)
            cur=cur->rl;
        prev=cur->ll;
        next=cur->rl;
        dust=dust+next->data+prev->data;
        prev->data=0;
        next->data=0;
    }
    else
        printf("%d room not found\n");
    display_list(head);
    printf("\ndust collect=%d",dust);
    return head;
}

int main()
{
    NODE head=NULL;
    int ch,n,count;

    while(1)
    {
        printf("\nThe list menu is\n");
        printf("\n1:insert end \t2:room cleaned \t3:display \t4:count nodes \t5:exit\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter the no of room\n");
                    scanf("%d",&n);
                printf("Enter the dust level\n");
                for(int i=0;i<n;i++)
                {
                    head=insert_end(head);
                }
            break;
            case 2:head=room_cleaned(head);
            break;
            case 3:display_list(head);
            break;
            case 4:count=count_nodes(head);
            break;
            case 5:exit(0);
            break;
            default:printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}
