#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a city node
struct City {
    char name[50];
    float distance;
    struct City* left;
    struct City* right;
};

// Function to create a new city node
struct City* CreateCity(const char* name, float distance) {
    struct City* newCity = (struct City*)malloc(sizeof(struct City));
    strcpy(newCity->name, name);
    newCity->distance = distance;
    newCity->left = NULL;
    newCity->right = NULL;
    return newCity;
}

// Function to insert a city node into the tree
struct City* InsertCity(struct City* root, const char* name, float distance) {
    if (root == NULL) {
        return CreateCity(name, distance);
    } else if (distance < root->distance) {
        root->left = InsertCity(root->left, name, distance);
    } else {
        root->right = InsertCity(root->right, name, distance);
    }
    return root;
}

// Function to perform a preorder traversal and display city information
void PreorderTraversal(struct City* root) {
    if (root != NULL) {
        printf("City: %s, Distance: %.2f\n", root->name, root->distance);
        PreorderTraversal(root->left);
        PreorderTraversal(root->right);
    }
}

// Function to free the allocated memory for the city tree
void FreeCityTree(struct City* root) {
    if (root != NULL) {
        FreeCityTree(root->left);
        FreeCityTree(root->right);
        free(root);
    }
}

int main() {
    struct City* root = NULL;
    char name[50];
    float distance;

    printf("Enter city details (name distance), type 'done' to stop:\n");

    // Take user input to build the city tree
    while (1) {
        printf("> ");
        scanf("%s", name);

        if (strcmp(name, "done") == 0) {
            break;
        }

        scanf("%f", &distance);

        root = InsertCity(root, name, distance);
    }

    // Perform preorder traversal to display city information
    printf("\nPreorder traversal of cities:\n");
    PreorderTraversal(root);

    // Free the allocated memory for the city tree
    FreeCityTree(root);

    return 0;
}

