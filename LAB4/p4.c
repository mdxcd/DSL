// 6. WAP to create a circular linked list and count the number of even and odd numbers present in the linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* create_circular_list();
void display(struct node *head);
void count_even_odd(struct node *head);
void free_circular_list(struct node *head);

int main() {
    struct node *head = NULL;

    printf("Enter elements for Circular Linked List:\n");
    head = create_circular_list();

    printf("\n");
    display(head);

    count_even_odd(head);

    free_circular_list(head);
    return 0;
}

struct node* create_circular_list() {
    struct node *head = NULL, *ptr = NULL, *newNode = NULL;
    char ch;

    do {
        newNode = (struct node*) malloc(sizeof(struct node));
        if (newNode == NULL) {
            return head;
        }

        printf("Enter Data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            ptr = newNode;
        } else {
            ptr->next = newNode;
            ptr = ptr->next;
        }

        printf("Do you have another data? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    if (ptr != NULL) {
        ptr->next = head;
    }

    return head;
}

void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *ptr = head;
    printf("Circular List elements: ");
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}

void count_even_odd(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    int even = 0, odd = 0;
    struct node *ptr = head;

    do {
        if (ptr->data % 2 == 0) {
            even++;
        } else {
            odd++;
        }
        ptr = ptr->next;
    } while (ptr != head);

    printf("Count of Even numbers: %d\n", even);
    printf("Count of Odd numbers : %d\n", odd);
}

void free_circular_list(struct node *head) {
    if (head == NULL) return;
    struct node *ptr = head, *next;
    
    // Break the circle to free standard list
    ptr = head;
    while (ptr->next != head) {
        ptr = ptr->next;
    }
    ptr->next = NULL;

    ptr = head;
    while (ptr != NULL) {
        next = ptr->next;
        free(ptr);
        ptr = next;
    }
}