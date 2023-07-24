#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a transaction
struct Transaction {
    int transactionID;
    char description[200];
    float amount;
    struct Transaction* left;
    struct Transaction* right;
};

// Function to create a new transaction node
struct Transaction* CreateTransaction(int transactionID, const char* description, float amount) {
    struct Transaction* newTransaction = (struct Transaction*)malloc(sizeof(struct Transaction));
    newTransaction->transactionID = transactionID;
    strcpy(newTransaction->description, description);
    newTransaction->amount = amount;
    newTransaction->left = NULL;
    newTransaction->right = NULL;
    return newTransaction;
}

// Function to insert a transaction node into the tree
struct Transaction* InsertTransaction(struct Transaction* root, int transactionID, const char* description, float amount) {
    if (root == NULL) {
        return CreateTransaction(transactionID, description, amount);
    } else if (transactionID > root->transactionID) {
        root->left = InsertTransaction(root->left, transactionID, description, amount);
    } else {
        root->right = InsertTransaction(root->right, transactionID, description, amount);
    }
    return root;
}

// Function to perform a postorder traversal and display transaction information
void PostorderTraversal(struct Transaction* root) {
    if (root != NULL) {
        PostorderTraversal(root->left);
        PostorderTraversal(root->right);
        printf("Transaction ID: %d, Description: %s, Amount: %.2f\n", root->transactionID, root->description, root->amount);
    }
}

// Function to free the allocated memory for the transaction tree
void FreeTransactionTree(struct Transaction* root) {
    if (root != NULL) {
        FreeTransactionTree(root->left);
        FreeTransactionTree(root->right);
        free(root);
    }
}

int main() {
    struct Transaction* root = NULL;
    int transactionID;
    char description[200];
    float amount;

    printf("Enter transaction details (ID description amount), type 'done' to stop:\n");

    // Take user input to build the transaction tree
    while (1) {
        printf("> ");
        scanf("%d", &transactionID);

        if (transactionID == -1) {
            break;
        }

        scanf("%s", description);
        scanf("%f", &amount);

        root = InsertTransaction(root, transactionID, description, amount);
    }

    // Perform postorder traversal to display transaction information
    printf("\nPostorder traversal of transactions:\n");
    PostorderTraversal(root);

    // Free the allocated memory for the transaction tree
    FreeTransactionTree(root);

    return 0;
}

