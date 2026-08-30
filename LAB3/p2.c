// WAP to Concatenate two Linked Lists.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* create_list();
void display(struct node *head);
struct node* concat(struct node *head1, struct node *head2);
void free_list(struct node *head);

int main() {
    struct node *head1 = NULL, *head2 = NULL, *head3 = NULL;

    printf("Enter elements for First LL:\n");
    head1 = create_list();

    printf("\nEnter elements for Second LL:\n");
    head2 = create_list();

    printf("\nFirst ");
    display(head1);

    printf("Second ");
    display(head2);

    head3 = concat(head1, head2);

    printf("\nConcatenated ");
    display(head3);

    free_list(head3);
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

struct node* concat(struct node *head1, struct node *head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct node *ptr = head1;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = head2;
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