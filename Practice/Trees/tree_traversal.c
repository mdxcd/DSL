// Non-Recursive (Iterative) Binary Tree Traversals: InOrder, PreOrder, PostOrder

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* create_node(int val) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void preOrder(struct node *root) {
    if (root == NULL) return;

    struct node *stack[100];
    int top = -1;

    stack[++top] = root;

    printf("PreOrder Traversal: ");
    while (top != -1) {
        struct node *curr = stack[top--];
        printf("%d ", curr->data);

        if (curr->right != NULL)
            stack[++top] = curr->right;
        if (curr->left != NULL)
            stack[++top] = curr->left;
    }
    printf("\n");
}

void inOrder(struct node *root) {
    struct node *stack[100];
    int top = -1;
    struct node *curr = root;

    printf("InOrder Traversal:  ");
    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }

        curr = stack[top--];
        printf("%d ", curr->data);

        curr = curr->right;
    }
    printf("\n");
}

void postOrder(struct node *root) {
    if (root == NULL) return;

    struct node *s1[100];
    struct node *s2[100];
    int top1 = -1, top2 = -1;

    s1[++top1] = root;

    while (top1 != -1) {
        struct node *curr = s1[top1--];
        s2[++top2] = curr;

        if (curr->left != NULL)
            s1[++top1] = curr->left;
        if (curr->right != NULL)
            s1[++top1] = curr->right;
    }

    printf("PostOrder Traversal: ");
    while (top2 != -1) {
        printf("%d ", s2[top2--]->data);
    }
    printf("\n");
}

int main() {
    struct node *root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);
    root->right->left = create_node(6);
    root->right->right = create_node(7);

    preOrder(root);
    inOrder(root);
    postOrder(root);

    return 0;
}
