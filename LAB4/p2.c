// 4. WAP for concatenation of two double linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node* create_list();
void display(struct node *head);
struct node* concatenate(struct node *head1, struct node *head2);
void free_list(struct node *head);

int main() {
    struct node *head1 = NULL, *head2 = NULL, *head3 = NULL;

    printf("Enter elements for First Double Linked List:\n");
    head1 = create_list();

    printf("\nEnter elements for Second Double Linked List:\n");
    head2 = create_list();

    printf("\nFirst ");
    display(head1);

    printf("Second ");
    display(head2);

    head3 = concatenate(head1, head2);

    printf("\nConcatenated ");
    display(head3);

    free_list(head3);
    return 0;
}

struct node* create_list() {
    struct node *head = NULL, *ptr = NULL, *newNode = NULL;
    char ch;

    do {
        newNode = (struct node*) malloc(sizeof(struct node));
        if (newNode == NULL) {
            return head;
        }

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

struct node* concatenate(struct node *head1, struct node *head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct node *ptr = head1;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = head2;
    head2->prev = ptr;
    return head1;
}

void free_list(struct node *head) {
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
