// WAP to find out the second smallest and second largest element stored in a dynamic array.

#include <stdio.h>
#include <stdlib.h>

void sec_min_max(int* ptr, int len);

int main() {
    int len;
    printf("Enter array size: ");
    scanf("%d", &len);

    int *ptr = (int*) malloc(len * sizeof(int));

    printf("Enter elements of array: ");
    for (int i = 0; i < len; i++) {
        scanf("%d", ptr + i);
    }

    sec_min_max(ptr, len);
    free(ptr);
    return 0;
}

void sec_min_max(int* ptr, int len) {

    int first_min, sec_min, first_max, sec_max;
    int has_sec_min = 0, has_sec_max = 0;

    first_min = *ptr;
    first_max = *ptr;

    for (int i = 1; i < len; i++) {
        int val = *(ptr + i);

        if (val < first_min) {
            sec_min = first_min;
            has_sec_min = 1;
            first_min = val;
        } else if (val > first_min) {
            if (!has_sec_min || val < sec_min) {
                sec_min = val;
                has_sec_min = 1;
            }
        }

        if (val > first_max) {
            sec_max = first_max;
            has_sec_max = 1;
            first_max = val;
        } else if (val < first_max) {
            if (!has_sec_max || val > sec_max) {
                sec_max = val;
                has_sec_max = 1;
            }
        }
    }

    if (has_sec_min) {
        printf("Second smallest element: %d\n", sec_min);
    } else {
        printf("No distinct second smallest element found.\n");
    }

    if (has_sec_max) {
        printf("Second largest element: %d\n", sec_max);
    } else {
        printf("No distinct second largest element found.\n");
    }
}