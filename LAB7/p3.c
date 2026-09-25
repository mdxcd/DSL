// 3. WAP to count the number of leaf nodes present in a binary tree by linked list

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

int count_leaf(struct node *ptr, int count){
    if(ptr->left_child == NULL && ptr->right_child == NULL)
        return count++;
    count = count_leaf(ptr->left_child, count);
    count += count_leaf(ptr->right_child, count);
}

int main(){
    struct node *root;
    int count = 0;
    printf("For No Node -> Enter -1\n");
    printf("Enter Root Node: ");
    root = create();
    count = count_leaf(root, count);
    printf("Total Leaf Nodes = %d\n", count);
    return 0;
}