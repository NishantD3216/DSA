#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FileSystemNode {
    char name[50];
    struct FileSystemNode* left;
    struct FileSystemNode* right;
};

struct FileSystemNode* createNode(const char* name) {
    struct FileSystemNode* newNode = (struct FileSystemNode*)malloc(sizeof(struct FileSystemNode));
    strcpy(newNode->name, name);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct FileSystemNode* insertNode(struct FileSystemNode* root, const char* name) {
    if (root == NULL) {
        return createNode(name);
    } else if (strcmp(name, root->name) < 0) {
        root->left = insertNode(root->left, name);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insertNode(root->right, name);
    }
    return root;
}

void ListFilesInOrder(struct FileSystemNode* root, char*** fileList, int* count) {
    if (root != NULL) {
        ListFilesInOrder(root->left, fileList, count);
        (*fileList)[*count] = strdup(root->name);
        (*count)++;
        ListFilesInOrder(root->right, fileList, count);
    }
}

void freeFileSystem(struct FileSystemNode* root) {
    if (root != NULL) {
        freeFileSystem(root->left);
        freeFileSystem(root->right);
        free(root);
    }
}

int main() {
    struct FileSystemNode* root = NULL;
    char input[50];
    int maxItems = 100;
    char** fileList = (char**)malloc(maxItems * sizeof(char*));
    int count = 0;

    printf("Enter the names of folders (type 'done' to stop):\n");
    while (1) {
        printf("> ");
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }

        root = insertNode(root, input);
    }
    ListFilesInOrder(root, &fileList, &count);

    // Display the sorted list
    printf("\nSorted list of files and folders:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", fileList[i]);
        free(fileList[i]); // Free memory for each item
    }
    free(fileList);
    freeFileSystem(root);

    return 0;
}
