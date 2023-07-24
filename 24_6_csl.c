#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char subject[20];
    int duration;
    struct node *link;
};
typedef struct node *NODE;
NODE create_node();
NODE insert_end(NODE tail);
NODE insert_front(NODE tail);
NODE search_delete(NODE tail);
void display(NODE tail);
int main()
{
    NODE tail=NULL;
    int ch,n;
    while(1)
    {
        printf("CIRCULAR SINGLY LINKED LIST MENU \n");
        printf("1.INSERT n times 2.INSERT FRONT 3.SEARCH AND DELETE 4.DISPLAY 5.EXIT \n");
        printf("ENTER YOUR CHOICE \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:tail=insert_end(tail);
                   break;
            case 2:tail=insert_front(tail);
                   break;
            case 3:tail=search_delete(tail);
                   break;
            case 4:display(tail);
                   break;
            case 5:exit(0);
                   break;
            default:printf("INVALID CHOICE \n");
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
         printf("MEMORY NOT ALLOCATED \n");
         exit(0);
     }
     printf("ENTER THE subject and duration \n");
     scanf("%s%d",newnode->subject,&newnode->duration);
     newnode->link=newnode;
     return newnode;
 }
 NODE insert_end(NODE tail)
 {
     NODE cur,newnode;
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
    NODE cur,newnode;
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
NODE search_delete(NODE tail)
{
    NODE cur,prev,opert;
    char name[20];
    int status=0;
    printf("ENTER THE SUBJECT TO BE REMOVED \n");
    scanf("%s",name);
    prev=NULL;
    cur=tail->link;
    do
    {
        if(strcmp(cur->subject,name)==0)
        {
            status=1;
            opert=cur;
            break;
        }
        prev=cur;
        cur=cur->link;
    }while(cur!=tail->link);

    if(status==1)
    {
        printf("DELETED SUBJECT AND DURATION IS %s and %d \n",opert->subject,opert->duration);
        prev->link=cur->link;
        free(opert);
        opert=NULL;
    }
    return tail;
}
void display(NODE tail)
 {
     NODE cur;
     if(tail==NULL)
     {
         printf("EMPTY \n");
         exit(0);
     }

     else
     {
         cur=tail->link;
           printf("SUBJECT \t DURATION\n");
         while(cur!=tail)
         {
          printf("%s\t%d \n",cur->subject,cur->duration);
               cur=cur->link;
         }
         printf("%s\t%d \n",cur->subject,cur->duration);
     }

 }
