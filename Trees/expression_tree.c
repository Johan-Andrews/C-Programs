// Expression Tree Implementation and traversal using BST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data[7];
    struct node *lchild, *rchild;
};

struct node* get_node(char *val) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    strcpy(n->data, val);
    n->lchild = NULL;
    n->rchild = NULL;
    return n;
}

struct node* create() {
    char key[10];
    printf("Enter node value (operator or operand, q to quit): ");
    scanf("%s", key);
    if (strcmp(key, "q") == 0)
        return NULL;
    struct node* n = get_node(key);
    if (strchr("+-*/", key[0]) && strlen(key) == 1) {
        printf("Enter left child of %s\n", key);
        n->lchild = create();
        printf("Enter right child of %s\n", key);
        n->rchild = create();
    }
    return n;
}

void inorder(struct node* root) {
    if (root != NULL) {
        if (root->lchild || root->rchild) printf("(");
        inorder(root->lchild);
        printf("%s", root->data);
        inorder(root->rchild);
        if (root->lchild || root->rchild) printf(")");
    }
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%s", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%s", root->data);
    }
}

int main() {
    struct node* root = NULL;
    printf("Create the expression tree\n");
    root = create();
    printf("\nInfix Expression: ");
    inorder(root);
    printf("\nPrefix Expression: ");
    preorder(root);
    printf("\nPostfix Expression: ");
    postorder(root);
    printf("\n");
    return 0;
}



