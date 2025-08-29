
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* get_node()
{
    struct Node* n;
    n = (struct Node*)malloc(sizeof(struct Node));
    if (n==NULL)
        printf("no space left on system");
    else
    {   n->next = NULL;
        return n;
    }
}

void push(int el, struct Node *header)
{
    struct Node *node,*ptr;
    ptr = header->next;
    node = get_node();
    node->data = el;
    node->next = NULL;

    if (ptr == NULL)        
    {   header->next = node;
    }
    else {
        while (ptr->next != NULL)     ptr = ptr->next;
        ptr->next = node;    
    }
    printf("%d added to Queue\n", el);
}

void display(struct Node *h){
    struct Node *ptr;
    ptr = h->next;
    if (ptr==NULL)      printf("Queue Underflow, nothing to display\n");
    else
    {
        while (ptr != NULL)
        {   printf("%d --> ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }   
}

void dequeue(struct Node* head)
{
    struct Node* ptr = head->next;
    if (ptr == NULL) {
        printf("Queue Underflow, nothing to delete\n");
    }
    else {
        printf("%d popped from the queue\n", ptr->data);
        head->next = ptr->next;
    }
}

void main()
{   int ch, el, n;
    struct Node* head = get_node();
    printf("\tMenu\n1.Insert element into queue\n2.Delete element\n3.Display Queue\n");

    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {   scanf("%d", &ch);
        if (ch == 1)
        {
            scanf("%d", &el);
            push(el, head);
        }
        else if (ch == 2)   dequeue(head);
        else if (ch == 3)   display(head);
        else                printf("invalid choice");
    }
}