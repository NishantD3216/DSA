#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct node{
  char name[20];
  char code;
    struct node *link;
};
typedef struct node *NODE;
NODE insert_end(NODE head);
void display(NODE head,int i);
NODE separate_w(NODE head);
NODE delete_w(NODE head);
int main() {
    int n;
    NODE head1=NULL,head2=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++) { head1=insert_end(head1); } head2=separate_w(head1); head1=delete_w(head1); display(head1,1); printf("\n"); display(head2,2); return 0; } NODE insert_end(NODE head) { NODE cur=head; NODE newnode=malloc(sizeof(struct node)); scanf("%s %c",newnode->name,&newnode->code);
    //printf("%s %c\n",newnode->name,newnode->code);
    if(cur==NULL)
    {
        head=newnode;
    }
    else{
        while(cur->link!=NULL)
        {
            cur=cur->link;
        }
        cur->link=newnode;
    }
    newnode->link=NULL;
    return head;
}
void display(NODE head,int i)
{
    NODE cur=head;
    if(cur==NULL)
    {
      printf("Line %d Empty.",i);
    }
    else{
    while(cur!=NULL)
    {
        printf("%s ",cur->name);
        cur=cur->link;
    }
    }
}
NODE separate_w(NODE head1)
{
    NODE cur=head1,cur2;
    NODE head2=NULL;
    while(cur!=NULL)
    {
        if(cur->code=='W')
        {
            NODE newnode=malloc(sizeof(struct node));
            strcpy(newnode->name,cur->name);
            newnode->code=cur->code;
            if(head2==NULL)
            {
                head2=newnode;
            }
            else{
                cur2=head2;
                while(cur2->link!=NULL)
                {
                    cur2=cur2->link;
                }
                cur2->link=newnode;
            }
            newnode->link=NULL;
        }
        cur=cur->link;
    }
    return head2;
}
NODE delete_w(NODE head)
{
    NODE cur=head,prev=NULL;
    while(cur!=NULL)
    {
        if(cur->code=='W')
        {
            if(cur==head)
            {
                head=cur->link;
                free(cur);
                cur=head;
            }
            else{
                prev->link=cur->link;
                free(cur);
                cur=prev->link;
            }
        }
        else{
            prev=cur;
            cur=cur->link;
        }
    }
    return head;
}
