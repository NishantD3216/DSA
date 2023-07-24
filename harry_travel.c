#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct node
{
    char city[20];
    struct node *rightlink;
    struct node *leftlink;
}*NODE;
NODE insert_end(NODE head);
int check_palindrome(NODE head,int n);
void reverse_display(NODE head,int n);
int main()
{
    NODE head=NULL;
    int n;
    scanf("%d",&n);
    if(n>1)
    {
        for(int i=0;i<2*n;i++)
        {
           head=insert_end(head);
        }
        int status=check_palindrome(head,n);
        if(status==1)
        {
        reverse_display(head,n);
        printf("\nPalindrome.");
        }
        else
        {
            reverse_display(head,n);
            printf("\nNot Palindrome.");
        }
    }
    else
    {
        printf("Cities should be more than 2.");
    }
    return 0;
}
NODE insert_end(NODE head)
{
   NODE newnode=malloc(sizeof(struct node));
   scanf("%s",newnode->city);
    newnode->rightlink=NULL;
    if(head==NULL)
        head=newnode;
    else{
        NODE cur=head;
        while(cur->rightlink!=NULL)
            cur=cur->rightlink;
        cur->rightlink=newnode;
        newnode->leftlink=cur;
    }
    return head;
}
int check_palindrome(NODE head,int n)
{
    NODE front=head;
    NODE end=head;
    while(end->rightlink!=NULL)
    {
        end=end->rightlink;
    }
    int status=1;
    for(int i=0;i<n;i++)
    {
        if(strcmp(front->city,end->city)!=0)
        {
            status=0;
            break;
        }
        front=front->rightlink;
        end=end->leftlink;
    }
    return status;
}
void reverse_display(NODE head,int n)
{
    NODE cur=head;
    printf("\n");
    for(int i=0;i<n;i++)
        cur=cur->rightlink;
    for(int i=0;i<n;i++)
    {
        printf("%s\n",cur->city);
        cur=cur->rightlink;
    }
}
