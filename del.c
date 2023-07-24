#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct node
{
    char city[30];
    struct node *rl;
    struct node *ll;
};
struct node * create_node();
struct node * insert_end(struct node * head);
void check(struct node * head,int n);
void display(struct node * head, int n);
struct node *cur;
struct node *prev;
int main()
{
    struct node * head=NULL;
    int n,i;
    scanf("%d",&n);
    if(n>=2)
    {
        for(i=0;i<n*2;i++)
        {
                head=insert_end(head);
        }
         display(head,n);
         check(head,n);
    }
    else
    {
        printf("Cities should be more than 2."); exit(0);
    }
    return 0;
}
struct node * create_node()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("NO memory allocated");
    }
    scanf("%s",newnode->city);
    newnode->rl=NULL;
    newnode->ll=NULL;
    return newnode;
}
struct node * insert_end(struct node * head)
{
    struct node * newnode;
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
        newnode->ll=cur;
        cur->rl=newnode;
    }
    return head;
}
void check(struct node * head,int n)
{
    int i,status=1;
    cur=head;
    for(i=0;i<n;i++) { cur=cur->rl;
    }
    prev=cur->ll;
    while(cur!=NULL)
    {
        if(strcmp(cur->city,prev->city)!=0)
        {
            status=0;
            break;
        }
        prev=prev->ll;
        cur=cur->rl;
    }
    if(status==1)
    {
        printf("\nPalindrome.\n");
    }
    else
    {
        printf("\nNot Palindrome.\n");
    }
}
void display(struct node * head, int n)
{
    int i;
    cur=head;
    for(i=0;i<n;i++) { cur=cur->rl;
    }
    while(cur!=NULL)
    {
        printf("%s\n",cur->city);
        cur=cur->rl;
    }
}
