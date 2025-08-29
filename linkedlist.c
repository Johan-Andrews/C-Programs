#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

void insert_at_front(struct Node* h){
    struct Node* new_node;
    int el;
    new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL)
        printf("insufficient memory");
    else 
    {
        printf("enter element:");
        scanf("%d", el);
        new_node->data = el;
        new_node->link = h.link;
        h.link = new_node;
    }
}

void insert_at_end(struct Node* h) {
    struct Node* newNode;
    int el;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
        printf("Insufficient Memory\n");
    
    else {
        printf("Enter the element: \n");
        scanf("%d", &el);
        newNode.data = el;
        newNode.link = NULL;
        struct Node* ptr = h;
        while (ptr.link != NULL) {
            ptr = ptr.link;
        }
        ptr.link = newNode;
    }
}

void insert_at(int pos, struct Node* h) {
    struct Node* newNode;
    int ele, i;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Insufficient Memory\n");
    } else {
        printf("Enter the element: \n");
        scanf("%d", &ele);
        newNode->data = ele;
        struct Node* ptr = h;
        for (i = 0; i < pos && ptr != NULL; i++) {
            ptr = ptr->link;
        }
        if (ptr == NULL) {
            printf("Position out of range!\n");
            free(newNode);
        } else {
            newNode->link = ptr->link;
            ptr->link = newNode;
        }
    }
}

void deleteFront(struct Node* h) {
    if (h->link == NULL) {
        printf("List is empty!\n");
    } 
    else {
        struct Node* temp = h->link;
        h->link = temp->link;
        free(temp);
    }
}

void deleteEnd(struct Node* h) {
    if (h->link == NULL) {
        printf("List is empty!\n");
    } 
    else {
        struct Node* ptr = h;
        while (ptr->link != NULL && ptr->link->link != NULL) {
            ptr = ptr->link;
        }
        free(ptr->link);
        ptr->link = NULL;
    }
}

void delete_at(int pos, struct Node* h) {
    if (pos <= 0 || h->link == NULL) {
        printf("Invalid position!\n");
    } 
    else {
        struct Node* ptr = h;
        for (int i = 0; i < pos - 1 && ptr->link != NULL; i++) {
            ptr = ptr->link;
        }
        if (ptr->link == NULL) {
            printf("out of range!\n");
        } 
        else {
            struct Node* temp = ptr->link;
            ptr->link = temp->link;
            free(temp);
        }
    }
}

void display(struct Node* h) {
    struct Node* ptr;
    ptr = h;
    printf("Elements are: \n");
    while (ptr->link != NULL) {
        ptr = ptr->link;
        printf("%d -> ", ptr->data);
    }
    printf("null\n");
}

int main() {
    struct Node* head;
    int i, ch=0f, pos;
    head = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL) {
        printf("Insufficient Memory\n");
    } 
    else {
        head->link = NULL;
    }

    for (i = 0; i < 5; i++) {
        insertFirst(head);
    }
    display(head);

    while (ch!=7) {
        printf("\n1.Insert at End\n2.Insert at Position\n3.Delete Front\n4.Delete End\n5.Delete at Position\n6.Display\n7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert_at_end(head);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                insert_at(pos, head);
                break;
            case 3:
                deleteFront(head);
                break;
            case 4:
                deleteEnd(head);
                break;
            case 5:
                printf("Enter position: ");
                scanf("%d", &pos);
                delete_at(pos, head);
                break;
            case 6:
                display(head);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}