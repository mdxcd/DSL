#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* create_list();
void display(struct node *head);
void display_alternate(struct node *head);
void maxmin(struct node *head);
struct node* insert_node(struct node *head);
struct node* delete_node(struct node *head);
struct node* reverse_list(struct node *head);
void find_middle(struct node *head);
void free_list(struct node *head);

int main() {
    struct node *head = NULL;
    int choice;

    while (1) {
        printf("\n1. Create Linked List\n");
        printf("2. Display List\n");
        printf("3. Display Alternate Nodes\n");
        printf("4. Find Largest and Smallest Elements\n");
        printf("5. Insert a Node\n");
        printf("6. Delete a Node\n");
        printf("7. Reverse Linked List\n");
        printf("8. Find Middle Element\n");
        printf("9. Exit\n");
        printf("Enter your choice (1-9): ");
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
                display(head);
                break;
            case 3:
                display_alternate(head);
                break;
            case 4:
                maxmin(head);
                break;
            case 5:
                head = insert_node(head);
                break;
            case 6:
                head = delete_node(head);
                break;
            case 7:
                head = reverse_list(head);
                display(head);
                break;
            case 8:
                find_middle(head);
                break;
            case 9:
                free_list(head);
                exit(0);
            default:
                printf("Invalid choice! Please select 1 to 9.\n");
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
        new->next = NULL;

        if (head == NULL) {
            head = new;
            ptr = new;
        } else {
            ptr->next = new;
            ptr = ptr->next;
        }

        printf("Do you have another data? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y');

    return head;
}

void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
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

void display_alternate(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *ptr = head;
    printf("Alternate nodes: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        if (ptr->next != NULL) {
            ptr = ptr->next->next;
        } else {
            break;
        }
    }
    printf("\n");
}

void maxmin(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *ptr = head->next;
    int max = head->data;
    int min = head->data;

    while (ptr != NULL) {
        if (ptr->data > max) max = ptr->data;
        if (ptr->data < min) min = ptr->data;
        ptr = ptr->next;
    }

    printf("Largest Element : %d\n", max);
    printf("Smallest Element: %d\n", min);
}

struct node* insert_node(struct node *head) {
    int value, choice, pos;
    printf("Enter data of new node: ");
    scanf("%d", &value);

    struct node *new = (struct node*) malloc(sizeof(struct node));
    new->data = value;
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

            if (ptr->next == NULL){
                printf("Position out of bounds.\n");
                break;
            }

            new->next = ptr->next;
            ptr->next = new;
            break;
        }

        case 3: {
            struct node *ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = new;
            break;
        }

        default: free(new); return head;
    }
    display(head);
    return head;
}

struct node* delete_node(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
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
            free(temp);
            break;
        }

        case 2: {
            printf("Enter Position: ");
            scanf("%d", &pos);

            struct node *ptr = head;
            int count = 1;
            while (ptr->next != NULL && count < pos - 1) {
                ptr = ptr->next;
                count++;
            }

            if (ptr->next == NULL) {
                printf("Position out of bounds.\n");
                break;
            }

            struct node *temp = ptr->next;
            ptr->next = temp->next;
            free(temp);
            break;
        }

        case 3: {
            if (head->next == NULL) {
                free(head);
                head = NULL; 
                break;
            }
            struct node *ptr = head;
            while (ptr->next->next != NULL) {
                ptr = ptr->next;
            }
            free(ptr->next);
            ptr->next = NULL;
            break;
        }

        default: return head;
    }

    display(head);
    return head;
}

struct node* reverse_list(struct node *head) {
    struct node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void find_middle(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *slow = head;
    struct node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Middle Element: %d\n", slow->data);
}

void free_list(struct node *head) {
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}