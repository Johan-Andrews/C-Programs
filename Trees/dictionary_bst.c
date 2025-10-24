//Word Dictionary implementation using Binary Search Tree (BST)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char word[50];
    char meaning[100];
    struct Node *left, *right;
};

struct Node* createNode(char *word, char *meaning) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->word, word);
    strcpy(newNode->meaning, meaning);
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, char *word, char *meaning) {
    if (root == NULL)
        return createNode(word, meaning);

    int cmp = strcmp(word, root->word);
    if (cmp < 0)
        root->left = insert(root->left, word, meaning);
    else if (cmp > 0)
        root->right = insert(root->right, word, meaning);
    else
        printf("Word '%s' already exists in dictionary.\n", word);

    return root;
}
struct Node* search(struct Node* root, char *word) {
    if (root == NULL || strcmp(root->word, word) == 0)
        return root;

    if (strcmp(word, root->word) < 0)
        return search(root->left, word);
    else
        return search(root->right, word);
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s : %s\n", root->word, root->meaning);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice;
    char word[50], meaning[100];
    struct Node* result;

    while (1) {
        printf("\n--- Dictionary using BST ---\n");
        printf("1. Insert Word\n");
        printf("2. Search Word\n");
        printf("3. Display Dictionary (Inorder)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("Enter word: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = 0;                 printf("Enter meaning: ");
                fgets(meaning, sizeof(meaning), stdin);
            meaning[strcspn(meaning, "\n")] = 0;  
                root = insert(root, word, meaning);
                break;

            case 2:
                printf("Enter word to search: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = 0;
                result = search(root, word);
                if (result)
                    printf("Meaning of '%s': %s\n", result->word, result->meaning);
                else
                    printf("Word not found in dictionary.\n");
                break;

            case 3:
                printf("\nDictionary contents (sorted):\n");
                inorder(root);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}



