// WAP to find the largest number and counts the occurrence of the largest number in a dynamic array of n integers using a single loop.

#include <stdio.h>
#include <stdlib.h>

void count_find_max(int* ptr, int len);

int main(){
   int len;
   printf("Enter array size : ");
   scanf("%d", &len);

   int *ptr = (int*) malloc(len * sizeof(int));

   printf("Enter elements of array : ");
   for (int i=0; i<len; i++){
      scanf("%d", ptr+i);
   }

   count_find_max(ptr, len);
   free(ptr);
   return 0;
}


void count_find_max(int* ptr, int len){
    int max = *ptr;
    for (int i=0; i<len; i++){
        if (max < *(ptr+i)){
            max = *(ptr+i);
        }
    }

    int count = 0;
    for (int i=0; i<len; i++){
        if (max == *(ptr+i)){
            count++;
        }
    }

    printf("Largest Element: %d\n", max);
    printf("No. of Occurances: %d\n", count);
}