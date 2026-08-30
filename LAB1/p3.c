/*
Given an unsorted dynamic array of size n, WAP to find and display
the number of elements between two elements a and b (both inclusive).
E.g. Input : arr = [1, 2, 2, 7, 5, 4], a=2 and b=5, Output : 4 and the
numbers are: 2, 2, 5, 4.
*/

#include <stdio.h>
#include <stdlib.h>

void print_btw_nums(int* ptr, int len);

int main(){
   int len;
   printf("Enter array size : ");
   scanf("%d", &len);

   int *ptr = (int*) malloc(len * sizeof(int));

   printf("Enter elements of array : ");
   for (int i=0; i<len; i++){
      scanf("%d", ptr+i);
   }

   print_btw_nums(ptr, len);
   free(ptr);
   return 0;
}


void print_btw_nums(int* ptr, int len){
    int a, b, initial, final;
    printf("a = ");
    scanf(" %d", &a);
    printf("b = ");
    scanf(" %d", &b);

    for (int i=0; i<len; i++){
        if (a == *(ptr+i)){
            initial = i;
        }
    }

    for (int i=initial; i<len; i++){
        if (b == *(ptr+i)){
            final = i;
        }
    }
    int count=0;
    for (int i=initial; i<=final; i++){
        count ++;
        printf("%d, ", *(ptr+i));
    }
    printf("\nCount: %d\n", count);
}