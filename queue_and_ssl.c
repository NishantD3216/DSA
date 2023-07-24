#include<stdio.h>
#include<stdlib.h>

struct node
{
    char name[10],srn[10];
    char grade;
    int sem;
    struct node *link;
};
typedef struct node *NODE;

NODE create_node()
{
    NODE newnode=(NODE)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory not allocatd\n");
        exit(0);
    }
    printf("Enter the student details\n");
    printf("Name\tSRN\tgrade\tsem\n");
    scanf("%s %s %c %d",newnode->name,newnode->srn,&newnode->grade,&newnode->sem);
    newnode->link=NULL;
    return newnode;
}

NODE enqueue(NODE head)
{
    NODE cur,newnode;
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

NODE dequeue(NODE head)
{
    NODE cur;
    if(head==NULL)
        printf("Queue Underflow\n");
    else if(head->link==NULL)
    {
        printf("Removed student details are\n");
        printf("Name\tSRN\tgrade\tsem\n");
        printf("%s\t%s\t%c\t%d\n",head->name,head->srn,head->grade,head->sem);
        free(head);
        head=NULL;
    }
    else
    {
        cur=head;
        head=head->link;
        printf("Removed student details are\n");
        printf("Name\tSRN\tgrade\tsem\n");
        printf("%s\t%s\t%c\t%d\n",cur->name,cur->srn,cur->grade,cur->sem);
        cur->link=NULL;
        free(cur);
    }
    return head;
}

void display_list(NODE head)
{
    NODE cur;
    if(head==NULL)
        printf("Student list is empty\n");
    else
    {
        cur=head;
        printf("\nStudent list is\n");
        printf("Name\tSRN\tgrade\tsem\n");
        while(cur!=NULL)
        {
            printf("%s\t%s\t%c\t%d\n",cur->name,cur->srn,cur->grade,cur->sem);
            cur=cur->link;
        }
    }
}

void getfront(NODE head)
{
    if(head==NULL)
        printf("Student list is empty\n");
    else
    {
        printf("\nfront student details are\n");
        printf("Name\tSRN\tgrade\tsem\n");
        printf("%s\t%s\t%c\t%d\n",head->name,head->srn,head->grade,head->sem);
    }
}

int main()
{
    NODE head=NULL;
    int n,m;

    printf("Enter the no of students\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        head=enqueue(head);

    display_list(head);

    getfront(head);

    printf("Enter the no to remove students\n");
    scanf("%d",&m);
    for(int k=0;k<m;k++)
        head=dequeue(head);

    return 0;
}
