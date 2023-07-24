#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* link;
};
typedef struct Node *NODE;

void insertNode(NODE *head, int num)
{
    NODE newNode = malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->link = NULL;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        newNode->link = *head;
        *head = newNode;
    }
}

void display(NODE head)
{
    NODE temp = head;
    while (temp != NULL)
    {
        printf("%d  adress= (%d)  \n", temp->data,&temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void separateLists(NODE head, NODE *posList, NODE *negList)
{
    NODE temp = head;
    while (temp != NULL)
    {
        if(temp->data >= 0)
        {
            insertNode(posList, temp->data);
        }
        else
        {
            insertNode(negList, temp->data);
        }
        temp = temp->link;
    }
}

void freeList(NODE head)
{
    NODE temp;
    while (head != NULL)
    {
        temp = head;
        head = head->link;
        free(temp);
    }
}

int main()
{
    FILE* file = fopen("numbers.txt", "r");
    if (file == NULL)
    {
        printf("Failed to open the file.\n");
        return 1;
    }
    NODE head = NULL;
    NODE posList = NULL;
    NODE negList = NULL;

    int num;
    while (fscanf(file, "%d", &num) != EOF)
    {
        insertNode(&head, num);
    }
    fclose(file);

    separateLists(head, &posList, &negList);

    printf("Positive numbers displayed: \n");
    display(posList);

    printf("Negative numbers displayed: \n");
    display(negList);

    freeList(head);
    freeList(posList);
    freeList(negList);

    return 0;
}
