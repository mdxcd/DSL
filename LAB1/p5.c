// WAP to store n student’s information (i.e. student’s roll no, name, gender, marks) of an educational institute and display all the data, for n students using array of structure.

#include <stdio.h>
#include <stdlib.h>

struct student {
    int roll;
    char name[50];
    char gender[10];
    float marks;
};

void input_students(struct student *s, int n);
void display_students(struct student *s, int n);

int main() {
    int n;
    printf("Enter number of students : ");
    scanf("%d", &n);

    struct student *s = (struct student*) malloc(n * sizeof(struct student));

    input_students(s, n);
    display_students(s, n);

    free(s);
    return 0;
}

void input_students(struct student *s, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Enter Roll No: ");
        scanf("%d", &(s + i)->roll);
        printf("Enter Name: ");
        scanf("%s", (s + i)->name);
        printf("Enter Gender: ");
        scanf("%s", (s + i)->gender);
        printf("Enter Marks: ");
        scanf("%f", &(s + i)->marks);
    }
}

void display_students(struct student *s, int n) {
    printf("\nStudent Information\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll No : %d\n", (s + i)->roll);
        printf("Name    : %s\n", (s + i)->name);
        printf("Gender  : %s\n", (s + i)->gender);
        printf("Marks   : %.2f\n", (s + i)->marks);
    }
}
