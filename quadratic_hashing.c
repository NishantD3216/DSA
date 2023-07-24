#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define HASH_TABLE_SIZE 100

struct Book {
    char title[100];
    int availableCopies;
};

struct HashTable {
    struct Book* data[HASH_TABLE_SIZE];
};

unsigned int hashFunction(const char* title) {
    unsigned int hash = 0;
    for (int i = 0; i < strlen(title); i++) {
        hash = (hash * 31) + title[i];
    }
    return hash % HASH_TABLE_SIZE;
}

struct Book* createBook(const char* title, int availableCopies) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    strcpy(newBook->title, title);
    newBook->availableCopies = availableCopies;
    return newBook;
}

void insertBook(struct HashTable* hashTable, const char* title, int availableCopies) {
    unsigned int index = hashFunction(title);
    int probe = 0;

    while (hashTable->data[index] != NULL) {
        index = (index + probe * probe) % HASH_TABLE_SIZE;
        probe++;
    }

    hashTable->data[index] = createBook(title, availableCopies);
}

int findAvailableCopies(struct HashTable* hashTable, const char* title) {
    unsigned int index = hashFunction(title);
    int probe = 0;

    while (hashTable->data[index] != NULL) {
        if (strcmp(hashTable->data[index]->title, title) == 0) {
            return hashTable->data[index]->availableCopies;
        }
        index = (index + probe * probe) % HASH_TABLE_SIZE;
        probe++;
    }

    return -1; // Book not found
}

int main() {
    struct HashTable* hashTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        hashTable->data[i] = NULL;
    }

    printf("Enter book details (title and available copies), type '-1' to stop:\n");
    char title[100];
    int availableCopies;
    while (1) {
        printf("Book Title: ");
        scanf("%s", title);
        if (strcmp(title, "-1") == 0) {
            break;
        }
        printf("Available Copies: ");
        scanf("%d", &availableCopies);

        insertBook(hashTable, title, availableCopies);
    }

    printf("\nEnter the book title to find the number of available copies:\n");
    printf("Book Title: ");
    scanf("%s", title);

    int foundCopies = findAvailableCopies(hashTable, title);
    if (foundCopies != -1) {
        printf("Number of Available Copies: %d\n", foundCopies);
    } else {
        printf("Book not found in the library's inventory.\n");
    }

    // Free the allocated memory
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        if (hashTable->data[i] != NULL) {
            free(hashTable->data[i]);
        }
    }
    free(hashTable);

    return 0;
}
