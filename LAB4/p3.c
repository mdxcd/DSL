// 3. WAP for deletion of a node from double linked list from 1. first, 2. from last and 3. from any position.

#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node* create_list();
void display(struct node *head);
struct node* delete_beginning(struct node *head);
struct node* delete_end(struct node *head);
struct node* delete_position(struct node *head, int pos);
void free_list(struct node *head);

int main() {
    struct node *head = NULL;
    int choice, pos;

    printf("Create Initial Double Linked List:\n");
    head = create_list();

    while (1) {
        printf("\n--- Deletion Menu ---\n");
        printf("1. Delete from Beginning\n");
        printf("2. Delete from End\n");
        printf("3. Delete from Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 5) break;

        switch (choice) {
            case 1:
                head = delete_beginning(head);
                display(head);
                break;
            case 2:
                head = delete_end(head);
                display(head);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                head = delete_position(head, pos);
                display(head);
                break;
            case 4:
                display(head);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    free_list(head);
    return 0;
}

struct node* create_list() {
    struct node *head = NULL, *ptr = NULL, *newNode = NULL;
    char ch;

    do {
        newNode = (struct node*) malloc(sizeof(struct node));
        if (newNode == NULL) return head;

        printf("Enter Data: ");
        scanf("%d", &newNode->data);
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            ptr = newNode;
        } else {
            ptr->next = newNode;
            newNode->prev = ptr;
            ptr = ptr->next;
        }

        printf("Do you have another data? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    return head;
}

void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *ptr = head;
    printf("List elements: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node* delete_beginning(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    struct node *temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

struct node* delete_end(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct node *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr);
    return head;
}

struct node* delete_position(struct node *head, int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (pos <= 1) {
        return delete_beginning(head);
    }

    struct node *ptr = head;
    int count = 1;
    while (ptr != NULL && count < pos) {
        ptr = ptr->next;
        count++;
    }

    if (ptr == NULL) {
        printf("Position out of bounds\n");
        return head;
    }

    if (ptr->prev != NULL) {
        ptr->prev->next = ptr->next;
    }
    if (ptr->next != NULL) {
        ptr->next->prev = ptr->prev;
    }
    free(ptr);
    return head;
}

void free_list(struct node *head) {
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}