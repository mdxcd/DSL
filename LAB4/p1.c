// 1. WAP to create a Double Linked List and display the double linked list in forward and backward direction.
// 2. WAP for insertion of a new node in double liked list at, 1. beginning, 2. at last and 3. at a position.
// 3. WAP for deletion of a node from double linked list from 1. first, 2. from last and 3. from any position.

#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node* create_list();
void display_forward(struct node *head);
void display_backward(struct node *head);
struct node* insert_node(struct node *head);
struct node* delete_node(struct node *head);
void free_list(struct node *head);

int main() {
    struct node *head = NULL;
    int choice;

    while (1) {
        printf("\n1. Create Double Linked List\n");
        printf("2. Display List (Forward & Backward)\n");
        printf("3. Insert a Node\n");
        printf("4. Delete a Node\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (head != NULL) {
                    free_list(head);
                    head = NULL;
                }
                head = create_list();
                break;
            case 2:
                display_forward(head);
                display_backward(head);
                break;
            case 3:
                head = insert_node(head);
                break;
            case 4:
                head = delete_node(head);
                break;
            case 5:
                free_list(head);
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

struct node* create_list() {
    struct node *head = NULL;
    struct node *ptr, *new;
    char ch;

    do {
        new = (struct node*) malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d", &new->data);
        new->prev = NULL;
        new->next = NULL;

        if (head == NULL) {
            head = new;
            ptr = new;
        } else {
            ptr->next = new;
            new->prev = ptr;
            ptr = ptr->next;
        }

        printf("Do you have another data? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y');

    return head;
}

void display_forward(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *ptr = head;
    printf("Forward Direction: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void display_backward(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    printf("Backward Direction: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}

struct node* insert_node(struct node *head) {
    int value, choice, pos;
    printf("Enter data of new node: ");
    scanf("%d", &value);

    struct node *new = (struct node*) malloc(sizeof(struct node));
    new->data = value;
    new->prev = NULL;
    new->next = NULL;

    if (head == NULL) {
        return new;
    }

    printf("1. At Beginning\n2. At Specific Position\n3. At End\n");
    printf("Enter insertion type: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            new->next = head;
            head->prev = new;
            head = new;
            break;

        case 2: {
            printf("Enter Position (>= 1): ");
            scanf("%d", &pos);

            struct node *ptr = head;
            int count = 1;
            while (ptr->next != NULL && count < pos - 1) {
                ptr = ptr->next;
                count++;
            }

            new->next = ptr->next;
            new->prev = ptr;
            if (ptr->next != NULL) {
                ptr->next->prev = new;
            }
            ptr->next = new;
            break;
        }

        case 3: {
            struct node *ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = new;
            new->prev = ptr;
            break;
        }

        default: free(new); return head;
    }

    printf("\nAfter Insertion:\n");
    display_forward(head);
    return head;
}

struct node* delete_node(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    int choice, pos;
    printf("1. From Beginning\n2. From Specific Position\n3. From End\n");
    printf("Enter deletion type: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            struct node *temp = head;
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            free(temp);   
            break;
        }

        case 2: {
            printf("Enter Position: ");
            scanf("%d", &pos);

            struct node *ptr = head;
            int count = 1;
            while (ptr != NULL && count < pos) {
                ptr = ptr->next;
                count++;
            }

            if (ptr == NULL) {
                printf("Position out of bounds.\n");
                return head;
            }

            if (ptr->prev != NULL) {
                ptr->prev->next = ptr->next;
            }
            if (ptr->next != NULL) {
                ptr->next->prev = ptr->prev;
            }
            free(ptr);
            break;
        }

        case 3: {
            struct node *ptr = head;
            if (ptr->next == NULL) {
                free(ptr);
                head = NULL;
                break;
            }
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->prev->next = NULL;
            free(ptr);
            break;
        }

        default: return head;
    }

    printf("\nAfter Deletion:\n");
    display_forward(head);
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