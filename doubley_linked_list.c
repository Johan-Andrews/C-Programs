#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* get_node()
{
    struct Node* n;
    n = (struct Node*)malloc(sizeof(struct Node));
    n->next = NULL;
    if (n==NULL)
        printf("no space left on system");
    else
        return n;
}

void insert_at_front(int el, struct Node *header)
{
    struct Node *node,*ptr;
    ptr = header->next;
    node = get_node();

    node->data = el;
    node->next = ptr;
    header->next = node;
}

void display(struct Node *h){
    struct Node *ptr;
    ptr = h->next;
    if ( ptr == NULL) printf("list is empty\n");
    else
        {printf("Linked list is:\n");
        
        while (ptr != NULL)
        {   printf("%d --> ", ptr->data);
            ptr = ptr->next;
        }
    printf("\n");
}
}

void delete_after(int key, struct Node*h)
{
    struct Node *ptr;
    ptr = h->next;
    if ( ptr == NULL) printf("list empty");
    else if (ptr->data == key && ptr->next == NULL)
     printf("onl one element");
    else
        while (ptr->data != key) ptr = ptr->next;
        ptr->next = ptr->next->next;
}

void main(){
    struct Node *head;
    head = get_node();
    if (head==NULL)
        printf("no space!!");
    else{
        insert_at_front(21, head);
        insert_at_front(50, head);
        display(head);
        delete_after(50, head);
        delete_after(50, head);
        //display(head);
        insert_at_front(234, head);
        display(head);
    }
}