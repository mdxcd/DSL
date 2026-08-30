// 2. Write a menu driven program to perform the following operations of a stack using single linked list by using suitable user defined functions for each case.
// a) Check if the stack is empty
// b) Display the contents of stack
// c) Push
// d) Pop

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *TOP = NULL;

void DISPLAY(){
    if (TOP == NULL) printf("Stack is Empty\n");
    else {
        struct node *ptr = TOP;
        printf("Stack Elements:\n");
        while(ptr != NULL){
            printf("%d", ptr->data);
            printf("\n");
            ptr = ptr->next;
        }
        printf("\n");
    }
    return;
}

void PUSH(int value){
    struct node *new;
    new = (struct node*) malloc(sizeof(struct node));
    new->data = value;
    new->next = TOP;
    TOP = new;
    DISPLAY();
    return;
}

void POP(){
    if (TOP == NULL){
        printf("UNDERFLOW\n");
        return;
    }
    struct node *temp;
    temp = TOP;
    TOP = temp->next;
    free(temp);
    DISPLAY();
    return;
}

int main(){
    int choice, value;
    printf("1. Check if the stack is empty\n");
    printf("2. Display the contents of stack\n");
    printf("3. PUSH Element\n");
    printf("4. POP Element\n");
    printf("5. Exit\n");

    while(1){
        printf("Enter Operation Choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: 
            if (TOP == NULL) printf("Stack is Empty\n");
            else printf("Stack is Not Empty\n");
            break;

        case 2:
            DISPLAY();
            break;

        case 3:
            printf("Enter new element: ");
            scanf("%d", &value);
            PUSH(value);
            break;
        case 4:
            POP();
            break;
        case 5:
            return 0;
        }
    }
}