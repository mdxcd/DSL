// 5. WAP for merging two sorted linked list into one sorted single linked list.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* create_list();
void display(struct node *head);
struct node* merge_sorted(struct node *head1, struct node *head2);
void free_list(struct node *head);

int main() {
    struct node *head1 = NULL, *head2 = NULL, *merged = NULL;

    printf("Enter elements for First Sorted Linked List:\n");
    head1 = create_list();

    printf("\nEnter elements for Second Sorted Linked List:\n");
    head2 = create_list();

    printf("\nFirst ");
    display(head1);

    printf("Second ");
    display(head2);

    merged = merge_sorted(head1, head2);

    printf("\nMerged Sorted ");
    display(merged);

    free_list(merged);
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

struct node* merge_sorted(struct node *head1, struct node *head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct node *result = NULL, *tail = NULL;

    if (head1->data <= head2->data) {
        result = head1;
        head1 = head1->next;
    } else {
        result = head2;
        head2 = head2->next;
    }
    tail = result;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    if (head1 != NULL) {
        tail->next = head1;
    } else {
        tail->next = head2;
    }

    return result;
}

void free_list(struct node *head) {
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}