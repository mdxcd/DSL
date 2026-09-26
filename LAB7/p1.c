// 1. WAP to construct a binary tree using array and traverse the binary tree

#include <stdio.h>
#include <stdlib.h>
int *tree = NULL;
int size;

void set_root(int val){
    tree[0] = val;
}

void set_left_child(int val, int parent){
    tree[(2*parent)+1] = val;
}

void set_right_child(int val, int parent){
    tree[(2*parent)+2] = val;
}

void display(){
    printf("Tree Nodes: ");
    for (int i=0; i<size; i++){
        printf("%d ", tree[i]);
    }
    printf("\n");
}

int main(){
    printf("Enter Tree Size: ");
    scanf("%d", &size);

    tree = (int *) malloc(size*sizeof(int));

    for (int i=0; i<size; i++){
        tree[i] = -1;
    }

    set_root(10);
    set_left_child(20,0);
    set_right_child(30,0);
    set_left_child(40,1);
    set_right_child(50,1);
    set_left_child(60,2);
    set_right_child(70,2);

    display();
    return 0;
}