// 1. Write a menu driven program to implement queue operations such as enqueue, dequeue, peek, Display elements, isEmpty. IsFull using static array

#include <stdio.h>

int size = 5;
int queue[5];
int front = -1;
int rear = -1;

void enqueue(int value){
    if (rear == size-1){
        printf("OVERFLOW\n");
        return;
    } else if (front == -1 && rear == -1){
        front++;
        rear++;
    } else {
        rear++;
    }
    queue[rear] = value;
}

int dequeue(){
    int temp;
    if (front == -1 && rear == -1){
        printf("UNDERFLOW\n");
        return -1;
    } else if (front == rear){
        temp = queue[front];
        front = -1;
        rear = -1;
        return temp;
    } else {
        temp = queue[front];
        front++;
        return temp;
    }
}

void peek(){
    if (front == -1 && rear == -1){
        printf("Queue is Empty\n");
        return;
    } else {
        printf("First Element: %d\n", queue[front]);
    }
}

void display(){
    if (front == -1 && rear == -1){
        printf("Queue is Empty\n");
        return;
    } else {
        for (int i = front; i<=rear; i++){
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int isEmpty(){
    if (front == -1 && rear == -1) return 1;
    else return 0;
}

int isFull(){
    if (rear == size-1) return 1;
    else return 0;
}

int main(){
    int choice;
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. IsEmpty\n6. IsFull\n7. Exit\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                int value;
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                printf("Dequeued Element: %d\n", dequeue());
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
                if(isFull()) printf("Queue is Full\n");
                else printf("Queue is not Full\n");
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}