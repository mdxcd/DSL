// 4. Write a menu driven program to implement priority queue operations such as enqueue, dequeue, peek, Display elements, isEmpty using linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int priority;
    int data;
    struct node *next;
};

struct node *front = NULL;

void enqueue(int p, int value){
    struct node *new = (struct node *) malloc(sizeof(struct node));
    new->priority = p;
    new->data = value;
    new->next = NULL;

    if (front == NULL || p < front->priority){
        new->next = front;
        front = new;
    } else {
        struct node *ptr = front;
        while (ptr->next != NULL && ptr->next->priority <= p){
            ptr = ptr->next;
        }
        new->next = ptr->next;
        ptr->next = new;
    }
}

void dequeue(){
    if (front == NULL){
        printf("UNDERFLOW\n");
        return;
    }
    struct node *temp = front;
    printf("Dequeued Element: %d\n", temp->data);
    front = front->next;
    free(temp);
}

void peek(){
    if (front == NULL){
        printf("Queue is Empty\n");
        return;
    }
    printf("First Element: %d\n", front->data);
}

void display(){
    if (front == NULL){
        printf("Queue is Empty\n");
        return;
    }
    struct node *ptr = front;
    while (ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int isEmpty(){
    if (front == NULL) return 1;
    else return 0;
}

int main(){
    int choice;
    int value, priority;
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. IsEmpty\n6. Exit\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter value's priority: ");
                scanf("%d", &priority);
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(priority, value);
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
