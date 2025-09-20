#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL; 

void insertAtBeginning(int el) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = el;

    if (last == NULL) {
        node->next = node;
        last = node;
    } else {
        node->next = last->next;
        last->next = node;
    }

    printf("Inserted %d at beginning.\n", el);
}

void insertAtEnd(int el) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = el;

    if (last == NULL) {
        node->next = node;
        last = node;
    } else {
        node->next = last->next;
        last->next = node;
        last = node;
    }

    printf("Inserted %d at end.\n", el);
}

void deleteFromBeginning() {
    if (last == NULL) {
        printf("List Underflow! Nothing to delete from beginning.\n");
        return;
    }

    struct Node* temp = last->next;

    if (last == temp) { 
        printf("Deleted %d from beginning.\n", temp->data);
        free(temp);
        last = NULL;
    } else {
        printf("Deleted %d from beginning.\n", temp->data);
        last->next = temp->next;
        free(temp);
    }
}

void deleteFromEnd() {
    if (last == NULL) {
        printf("List Underflow! Nothing to delete from end.\n");
        return;
    }

    struct Node* temp = last->next;

    if (last == temp) {
        printf("Deleted %d from end.\n", last->data);
        free(last);
        last = NULL;
    } else {
        while (temp->next != last) {
            temp = temp->next;
        }
        printf("Deleted %d from end.\n", last->data);
        temp->next = last->next;
        free(last);
        last = temp;
    }
}

void displayList() {
    if (last == NULL) {
        printf("List contents:\n");
        return;
    }

    struct Node* temp = last->next;
    printf("List contents: ");
    do {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != last->next) printf(" ");
    } while (temp != last->next);
    printf("\n");
}

int main() {
    int n, op, val;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &op);
        switch (op) {
            case 1:
                scanf("%d", &val);
                insertAtBeginning(val);
                displayList();
                break;
            case 2:
                scanf("%d", &val);
                insertAtEnd(val);
                displayList();
                break;
            case 3:
                deleteFromBeginning();
                displayList();
                break;
            case 4:
                deleteFromEnd();
                displayList();
                break;
            case 5:
                displayList();
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
