// 2. WAP for insertion of a new node in double linked list at, 1. beginning, 2. at last and 3. at a position.

#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node* create_list();
void display(struct node *head);
struct node* insert_beginning(struct node *head, int val);
struct node* insert_end(struct node *head, int val);
struct node* insert_position(struct node *head, int val, int pos);
void free_list(struct node *head);

int main() {
    struct node *head = NULL;
    int choice, val, pos;

    printf("Create Initial Double Linked List:\n");
    head = create_list();

    while (1) {
        printf("\n--- Insertion Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 5) break;

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                head = insert_beginning(head, val);
                display(head);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                head = insert_end(head, val);
                display(head);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                printf("Enter position: ");
                scanf("%d", &pos);
                head = insert_position(head, val, pos);
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

struct node* insert_beginning(struct node *head, int val) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode;
}

struct node* insert_end(struct node *head, int val) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }

    struct node *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->prev = ptr;
    return head;
}

struct node* insert_position(struct node *head, int val, int pos) {
    if (pos <= 1 || head == NULL) {
        return insert_beginning(head, val);
    }

    struct node *ptr = head;
    int count = 1;
    while (ptr->next != NULL && count < pos - 1) {
        ptr = ptr->next;
        count++;
    }

    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = ptr->next;
    newNode->prev = ptr;

    if (ptr->next != NULL) {
        ptr->next->prev = newNode;
    }
    ptr->next = newNode;

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
