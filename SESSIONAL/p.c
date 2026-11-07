#include<stdio.h>

int size = 10;
int queue[10];
int front = -1;
int rear = -1;

void enqueue(int value){
    if (front == size-1){
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
    if (front == -1 && rear ==-1){
        printf("UNDERFLOW\n");
        return -1;
    } else if (front == rear){
        int temp = queue[rear];
        front = -1;
        rear = -1;
        return temp;
    } else {
        int temp = queue[rear];
        front++;
        return temp;
    }
}

void peek(){
    if (front == -1 && rear ==-1){
        printf("Queue is Empty\n");
        return;
    } else {
        int temp = queue[front];
        printf("Peek Element: %d\n", temp);
    }
}

void display(){
    if (front == -1 && rear ==-1){
        printf("Queue is Empty\n");
        return;
    } else {
        for (int i = front; i <= rear; i++){
            printf("%d ", queue[i]);
        }
    }
}

int main(){
    int value, choice, temp;

    while(1){
        printf("Enter Operation No: ");
        printf("1. Enqueue ");
        printf("2. Dequeue ");
        printf("3. Peek ");
        printf("4. Display ");
        printf("5. Exit \n");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value); 
            break;
        case 2:
            temp = dequeue();
            printf("Dequeued Element: %d", temp);
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        }
    }

    return 0;
}