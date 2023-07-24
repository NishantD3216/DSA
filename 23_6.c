#include<stdio.h>
#include<stdlib.h>

struct employee
{
    char name[20],designation[20];
    float salary;
    int exp;
    struct employee*link;
};
typedef struct employee*NODE;

NODE create_node();
NODE insert_employee(NODE tail);
void salary(NODE tail);
void display(NODE tail);
NODE highest(NODE tail);

int main()
{
    NODE tail=NULL,high;
    int ch,n,i;
    while(1)
    {
        printf("\n1.Insert_nemployee\t2.Insert_2employee\t3.Display\t4.Highest\t5.Salary\t6.Exit\n");
    printf("Enter your choice:\n");
    scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the number of employees:\n");
                    scanf("%d",&n);
                    for(i=0;i<n;i++)
                    {
                        tail=insert_employee(tail);
                    }
                    break;
            case 2:for(i=0;i<2;i++)
                    {
                        tail=insert_employee(tail);
                    }
                    break;
            case 3:display(tail);
                    break;
            case 4:high=highest(tail);
                    printf("Employee with highest salary\n");
                    printf("Name\tDesignation\tSalary\tExperience\n");
                    printf("%s\t%s\t%0.2f\t%d\n",high->name,high->designation,high->salary,high->exp);
                    break;
            case 5:salary(tail);
                    break;
            case 6:exit(0);
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
    newnode=(NODE)malloc(sizeof(struct employee));
    if(newnode==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("Enter name,designation,salary and experience\n");
    scanf("%s %s %f %d",newnode->name,newnode->designation,&newnode->salary,&newnode->exp);
    newnode->link=newnode;
    return newnode;
}

NODE insert_employee(NODE tail)
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

void display(NODE tail)
{
    NODE cur;
    if(tail==NULL)
    {
        printf("CSLL is empty\n");
    }
    else
    {
        printf("The employees list is:\n");
        printf("Name\tDesignation\tSalary\tExperience\n");
        cur=tail->link;
        do
        {
            printf("%s\t%s\t%0.2f\t%d\n",cur->name,cur->designation,cur->salary,cur->exp);
            cur=cur->link;
        }while(cur!=tail->link);
    }
}

NODE highest(NODE tail)
{
    NODE cur,high;
    float highs=0;
    if(tail==NULL)
    {
        printf("CSLL is empty\n");
    }
    else
    {
        cur=tail->link;
        do
       {
        if(cur->salary>highs)
        {
            highs=cur->salary;
            high=cur;
        }
        cur=cur->link;
       }while(cur!=tail->link);
    }
    return high;
}

void salary(NODE tail)
{
    NODE cur,high;
    float highs=0;
    if(tail==NULL)
    {
        printf("CSLL is empty\n");
    }
    else
    {
        cur=tail->link;
        do
       {
        if(cur->salary>50000)
        {
            cur->salary=cur->salary+(cur->salary*0.2);
        }
        cur=cur->link;
       }while(cur!=tail->link);
    }
}
