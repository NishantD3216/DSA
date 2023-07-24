#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *rlink;
    struct node *llink;
};
struct node* create_node()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("MEMORY NOT ALLOCATED\n");
        exit(0);
    }
    printf("ENTER THE DATA\n");
    scanf("%d",&newnode->data);
    newnode->rlink=NULL;
    newnode->llink=NULL;
    return newnode;
}
struct node* insert_end(struct node *head)
{
    struct node *newnode,*cur;
    newnode=create_node();
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        cur=head;
        while(cur->rlink!=NULL)
        {
            cur=cur->rlink;
        }
        cur->rlink=newnode;
        newnode->llink=cur;
    }
    return head;
}
struct node* insert_front(struct node *head)
{
    struct node *newnode;
    newnode=create_node();
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->rlink=head;
        head->llink=newnode;
        head=newnode;
    }
    return head;
}
void display(struct node *head)
{
    struct node *cur;
    if(head==NULL)
    {
        printf("DLL IS EMPTY\n");
        exit(0);
    }
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            printf("%d ",cur->data);
            cur=cur->rlink;
        }
    }
}
void r_display(struct node *head)
{
    struct node *cur=head;
    while(cur->rlink!=NULL)
    {
        cur=cur->rlink;
    }
    while(cur!=NULL)
    {
        printf("%d ",cur->data);
        cur=cur->llink;
    }
}
struct node* delete_end(struct node *head)
{
 struct node *cur,*prev;
 if(head==NULL)
 {
     printf("empty\n");
 }
 else if(head->rlink==NULL)
 {
    printf("%d",head->data);
    free(head);
    head=NULL;
 }
 else
 {
     prev=NULL;
     cur=head;
     while(cur->rlink!=NULL)
     {
         prev=cur;
         cur=cur->rlink;
     }
     prev->rlink=NULL;
     cur->llink=NULL;
     free(cur);
 }
 return head;
}
struct node* delete_front(struct node *head)
{
    struct node *cur;
    if(head==NULL)
    {
        printf("empty\n");
        exit(0);
    }
    else if(head->rlink==NULL)
    {
        printf("%d",head->data);
        free(head);
        head=NULL;
    }
    else
    {
        cur=head;
         head=head->rlink;
        cur->rlink=NULL;
        head->llink=NULL;
        free(cur);

    }
 return head;
}
struct node* insert_spc(struct node *head)
{
    struct node *prev,*cur;
    int pos;
    struct node *newnode=create_node();
    int count=count_chars(head);
    printf("ENTER THE POSITION \n");
    scanf("%d",&pos);
    if(pos==1 && head==NULL)
    {
        head=newnode;
    }
    else if (pos==1)
    {
        newnode->rlink=head;
        head->llink=newnode;
        head=newnode;
    }
    else if(pos==count+1)
    {
        cur=head;
        while(cur->rlink!=NULL)
        {
            cur=cur->rlink;
        }
        cur->rlink=newnode;
        newnode->llink=cur;
    }
    else if(pos>1 && pos<=count)
    {
        prev=NULL;
        cur=head;
        for(int i=0;i<pos-1;i++)
        {
            prev=cur;
            cur=cur->rlink;
        }
        prev->rlink=newnode;
        newnode->llink=prev;
        newnode->rlink=cur;
        cur->llink=newnode;
    }
    return head;

}
struct node* delete_spc(struct node *head)
{
    struct node *prev,*cur;
    int pos;
    int count=count_chars(head);
    printf("ENTER THE POSITION \n");
    scanf("%d",&pos);
    if(head==NULL)
    {
        printf("DOUBLY LINKED LIST IS EMPTY \n");
        exit(0);
    }
    else if (pos==1 && head->rlink==NULL)
    {
        printf("DELETED DATA IS %d \n",head->data);
        free(head);
         head=NULL;
    }
    else if(pos==1)
    {
        cur=head;
        head=head->rlink;
        cur->rlink=NULL;
        printf("DELETED DATA IS %d \n",cur->data);
        free(cur);
    }
    else if(pos==count)
    {
        prev=NULL;
        cur=head;
        while(cur->rlink!=NULL)
        {
            prev=cur;
            cur=cur->rlink;
        }
        prev->rlink=NULL;
        printf("DELETED DATA IS %d\n",cur->data);
        free(cur);
    }
    else if(pos>1 && pos<count)
    {
        prev=NULL;
        cur=head;
        for(int i=0;i<pos-1;i++)
        {
            prev=cur;
            cur=cur->rlink;

        }
        prev->rlink=cur->rlink;

        cur->rlink->llink=prev;
        printf("DELETED DATA IS %d \n",cur->data);
        free(cur);
    }
    return head;

}
int count_chars(struct node *head)
{
    struct node *cur;
    int count=0;
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
            cur=cur->rlink;
        }
    }
    return count;
}
void search(struct node *head)
{
    struct node *cur;
    int cee;
    printf("ENTER THE DATA TO BE SEARCHED\n");
    scanf("%d",&cee);
    if(head==NULL)
    {
        printf("EMPTY");
        exit(0);
    }
    else
    {
        int status=0;
        cur=head;
        while(cur!=NULL)
        {
            if(cur->data==cee)
            {
                status=1;
                break;
            }
            cur=cur->rlink;
        }
        if(status==1)
        {
            printf("SEARCH SUCESSFULL\n");
        }
        else
        {
            printf("SEARCH UNSUCESSFULL\n");
        }
    }
}
int main()
{
    struct node *head=NULL;
    while(1)
    {
        int ch;
        printf("enter your choice\n ");
        scanf("%d",&ch);
        int c;
        switch(ch)
        {
            case 1:head=insert_end(head);
                    break;
            case 2:head=insert_front(head);
                   break;
            case 3:head=insert_spc(head);
                   break;
            case 4:head=delete_end(head);
                   break;
            case 5:head=delete_front(head);
                   break;
            case 6:head=delete_spc(head);
                   break;
            case 7:display(head);
                   break;
            case 8:r_display(head);
                    break;
            case 9: c=count_chars(head);
                     printf("%d",c);
                    break;
            case 10:search(head);
                    break;
            case 11:exit(0);
                    break;
            default:printf("INVALID INPUT\n");
                   break;
        }
}
return 0;
}
