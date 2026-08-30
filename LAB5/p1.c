// 1. Write a menu driven program to perform the following operations of a stack using array by using suitable user defined functions for each case.
// a) Check if the stack is empty
// b) Display the contents of stack
// c) Push 
// d) Pop

#include <stdio.h>

int size = 5;
int stack[5];
int TOP = -1;

void DISPLAY(){
    if (TOP == -1) printf("Stack is Empty\n");
    else {
        printf("Stack Elements:\n");
        for(int i=TOP; i>=0; i--){
            printf("%d", stack[i]);
            printf("\n");
        }
    }
    return;
}

void PUSH(int value){
    TOP++;
    if (TOP < size){
        stack[TOP] = value;
        DISPLAY();
        return;
    } else {
        printf("OVERFLOW\n");
        TOP--;
        return;
    }
}

void POP(){
    if (TOP == -1){
        printf("UNDERFLOW\n");
        return;
    } else {
        TOP--;
        DISPLAY();
        return;
    }
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
            if (TOP == -1) printf("Stack is Empty\n");
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