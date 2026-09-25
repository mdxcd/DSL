// 2. WAP to construct a binary tree using linked list and write the functions for InOrder, PreOrder & PostOrder traversel

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left_child;
    struct node *right_child;
};

struct node *create(){
    int value;
    struct node *new;
    new = (struct node *) malloc(sizeof(struct node));
    scanf("%d", &value);

    if(value == -1)
        return NULL;
    
    new->data = value;
    printf("Left child of %d: ", value);
    new->left_child = create();
    printf("Right child of %d: ", value);
    new->right_child = create();

    return new;
}

void InOrder(struct node *ptr){
    if(ptr == NULL){
        return;
    }
    InOrder(ptr->left_child);
    printf("%d ", ptr->data);
    InOrder(ptr->right_child);
}

void PreOrder(struct node *ptr){
    if(ptr == NULL){
        return;
    }
    printf("%d ", ptr->data);
    PreOrder(ptr->left_child);
    PreOrder(ptr->right_child);
}

void PostOrder(struct node *ptr){
    if(ptr == NULL){
        return;
    }
    PostOrder(ptr->left_child);
    PostOrder(ptr->right_child);
    printf("%d ", ptr->data);
}

int main(){
    struct node *root;
    printf("For No Node -> Enter -1\n");
    printf("Enter Root Node: ");
    root = create();
    printf("InOrder Traversal: ");
    InOrder(root);
    printf("\n");
    printf("PreOrder Traversal: ");
    PreOrder(root);
    printf("\n");
    printf("PostOrder Traversal: ");
    PostOrder(root);
    printf("\n");
    return 0;
}