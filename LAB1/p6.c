/*
WAP to declare one distance structure (with members kilometer and meter) and create the variables for addition of two distances using Pointers to structure.
10km500m--D1  - > ptr1
21km600m--D2  - > ptr2
Now use the third variable D3 and its pointer -> ptr3
*/

#include <stdio.h>

struct distance {
    int kilometer;
    int meter;
};

void add_distance(struct distance *ptr1, struct distance *ptr2, struct distance *ptr3);
void display_distance(struct distance *ptr);

int main() {
    struct distance D1, D2, D3;
    struct distance *ptr1 = &D1;
    struct distance *ptr2 = &D2;
    struct distance *ptr3 = &D3;

    printf("Enter first distance (kilometer and meter): ");
    scanf("%d %d", &ptr1->kilometer, &ptr1->meter);

    printf("Enter second distance (kilometer and meter): ");
    scanf("%d %d", &ptr2->kilometer, &ptr2->meter);

    add_distance(ptr1, ptr2, ptr3);

    printf("Sum of distances: ");
    display_distance(ptr3);

    return 0;
}

void add_distance(struct distance *ptr1, struct distance *ptr2, struct distance *ptr3) {
    ptr3->kilometer = ptr1->kilometer + ptr2->kilometer;
    ptr3->meter = ptr1->meter + ptr2->meter;

    if (ptr3->meter >= 1000) {
        ptr3->kilometer += ptr3->meter / 1000;
        ptr3->meter = ptr3->meter % 1000;
    }
}

void display_distance(struct distance *ptr) {
    printf("%d km %d m\n", ptr->kilometer, ptr->meter);
}
