#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_COMPUTERS 100

struct Computer {
    int id;
    char name[100];
    struct Connection* next;
};

struct Connection {
    struct Computer* connectedTo;
    struct Connection* next;
};

struct Computer* CreateComputer(const char* name, int id) {
    struct Computer* newComputer = (struct Computer*)malloc(sizeof(struct Computer));
    strcpy(newComputer->name, name);
    newComputer->id = id;
    newComputer->next = NULL;
    return newComputer;
}

struct Connection* CreateConnection(struct Computer* connectedTo) {
    struct Connection* newConnection = (struct Connection*)malloc(sizeof(struct Connection));
    newConnection->connectedTo = connectedTo;
    newConnection->next = NULL;
    return newConnection;
}

void AddConnection(struct Computer* computer1, struct Computer* computer2) {
    struct Connection* connection1 = CreateConnection(computer2);
    struct Connection* connection2 = CreateConnection(computer1);
    connection1->next = computer1->next;
    computer1->next = connection1;
    connection2->next = computer2->next;
    computer2->next = connection2;
}

void BFS(struct Computer* start) {
    bool visited[MAX_COMPUTERS] = { false };
    struct Computer* queue[MAX_COMPUTERS];
    int front = 0, rear = 0;

    visited[start->id] = true;
    queue[rear++] = start;

    printf("Level of Influence of %s:\n", start->name);
    int level = 0;
    int currentLevelNodes = 1;
    int nextLevelNodes = 0;

    while (front < rear) {
        struct Computer* current = queue[front++];
        printf("%s ", current->name);

        struct Connection* connection = current->next;
        while (connection != NULL) {
            if (!visited[connection->connectedTo->id]) {
                visited[connection->connectedTo->id] = true;
                queue[rear++] = connection->connectedTo;
                nextLevelNodes++;
            }
            connection = connection->next;
        }

        currentLevelNodes--;
        if (currentLevelNodes == 0) {
            printf("\n");
            level++;
            currentLevelNodes = nextLevelNodes;
            nextLevelNodes = 0;
        }
    }
}

int main() {
    struct Computer* computers[MAX_COMPUTERS];
    int numComputers = 0;

    printf("Enter computer details (name and identifier), type 'done' to stop:\n");
    char name[100];
    int id;
    while (1) {
        printf("Name: ");
        scanf("%s", name);
        if (strcmp(name, "done") == 0) {
            break;
        }
        printf("Identifier: ");
        scanf("%d", &id);

        computers[numComputers] = CreateComputer(name, id);
        numComputers++;
    }

    printf("\nEnter connections (computer_id1 computer_id2), type '-1' to stop:\n");
    int computerId1, computerId2;
    while (1) {
        printf("Computer ID 1: ");
        scanf("%d", &computerId1);
        if (computerId1 == -1) {
            break;
        }
        printf("Computer ID 2: ");
        scanf("%d", &computerId2);

        if (computerId1 < numComputers && computerId2 < numComputers) {
            AddConnection(computers[computerId1], computers[computerId2]);
        } else {
            printf("Invalid computer identifiers.\n");
        }
    }

    printf("\nEnter the computer identifier to find its level of influence:\n");
    printf("Computer ID: ");
    scanf("%d", &computerId1);

    if (computerId1 < numComputers) {
        BFS(computers[computerId1]);
    } else {
        printf("Invalid computer identifier.\n");
    }

    return 0;
}
