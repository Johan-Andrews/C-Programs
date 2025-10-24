#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
        char data[7];
        struct node *lchild, *rchild;
};

struct node*stack[50];
int top = -1;

void push(struct node*n)
{
        top++;
        stack[top] = n;
}

struct node*pop()
{
        top--;
        return stack[top+1];
}
struct node*get_node()
{
        struct node*n = (struct node*)malloc(sizeof(struct node));
        n->lchild = NULL;
        n->rchild = NULL;
        return n;
}

void create(struct node*root)
{ 
        char key[5];
        struct node*ptr = root;
        printf("enter value:");
        scanf("%s", key);
        
        if (ptr == NULL)
        {       struct node *new_node = get_node();
                ptr = new_node;
        }
        if (atoi(key) != 0 && (atoi(key)%1 == 0))
        {
                strcpy(ptr->data, key);
                return;
        }
        if (strcmp(key, "q" )!= 0)
        {
                strcpy(ptr->data, key);
                printf("enter value for left child of %s\n", ptr->data);
                create(ptr->lchild);

                printf("enter value for right child of %s\n", ptr->data);
                create(ptr->rchild);
        }
}

void inorder(struct node*root)
{
struct node*ptr = root;
printf("%s ", ptr->lchild->data);

while (ptr != NULL || top!= -1)
{
        while (ptr != NULL)
        {
                push(ptr);
                ptr = ptr->lchild;
        }
        struct node*nod = pop();
        printf("%s ", nod->data);
        ptr = nod->rchild;
        }
}

void main()
{
struct node*r = get_node();
create(r);

printf("Inorder taversal:\n");
inorder(r);
}