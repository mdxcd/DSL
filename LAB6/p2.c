// 2. Write a menu driven program to implement queue operations such as enqueue, dequeue, peek, Display elements, isEmpty using linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value){
    struct node *new;
    new = (struct node *) malloc(sizeof(struct node));
    new->data = value;
    new->next = NULL;

    if (front == NULL && rear == NULL){
        front = new;
        rear = new;
    } else {
        rear->next = new;
        rear = new;
    }
}

void dequeue(){
    struct node *temp;
    if (front == NULL && rear == NULL){
        printf("UNDERFLOW\n");
        return;
    } else if (front == rear){
        temp = front;
        printf("Dequeued Element: %d\n", temp->data);
        front = NULL;
        rear = NULL;
        free(temp);
    } else {
        temp = front;
        printf("Dequeued Element: %d\n", temp->data);
        front = front->next;
        free(temp);
    }
}

void peek(){
    if (front == NULL && rear == NULL){
        printf("Queue is Empty\n");
        return;
    } else {
        printf("First Element: %d\n", front->data);
    }
}

void display(){
    if (front == NULL && rear == NULL){
        printf("Queue is Empty\n");
        return;
    } else {
        struct node *ptr = front;
        while( ptr != NULL){
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
}

int isEmpty(){
    if (front == NULL && rear == NULL) return 1;
    else return 0;
}

int main(){
    int choice, value;
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. IsEmpty\n6. Exit\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                if(isEmpty()) printf("Queue is Empty\n");
                else printf("Queue is not Empty\n");
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}