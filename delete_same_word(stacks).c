#include <stdio.h>
#include <string.h>

void deleteConsecutiveWords(char* sequence) {
    char result[1000];
    char* token = strtok(sequence, " ");
    char* prevToken = NULL;

    while (token != NULL) {
        if (prevToken == NULL || strcmp(token, prevToken) != 0) {
            strcat(result, token);
            strcat(result, " ");
        }
        prevToken = token;
        token = strtok(NULL, " ");
    }

    printf("Remaining words: %s\n", result);
}

int main() {
    char sequence[1000];

    printf("Enter a sequence of words: ");
    fgets(sequence, sizeof(sequence), stdin);
    sequence[strcspn(sequence, "\n")] = '\0';  // Remove trailing newline character

    deleteConsecutiveWords(sequence);

    return 0;
}
