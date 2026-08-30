/*
WAP using dynamic array to perform the following:
- Find max and min in the array
- Find the position of a key in the array
- Find the even and odd elements in the array
*/

#include <stdio.h>
#include <stdlib.h>

void maxmin(int *ptr, int len);
void pos(int *ptr, int len);
void evenodd(int *ptr, int len);

int main(){
   int len;
   printf("Enter array size : ");
   scanf("%d", &len);

   int *ptr = (int*) malloc(len * sizeof(int));

   printf("Enter elements of array : ");
   for (int i=0; i<len; i++){
      scanf("%d", ptr+i);
   }
   
   while(1){
      int op;
      printf("\nOperation Menu: \n");
      printf("1. Find Min & Max\n");
      printf("2. Position of key\n");
      printf("3. Even & odd Elements\n");
      printf("Enter your choice : ");
      scanf("%d", &op);
      
      switch(op) {
      case 1: maxmin(ptr, len); break;
      case 2: pos(ptr, len); break;
      case 3: evenodd(ptr, len); break;
      default: printf("Invalid Operation\n"); break;
      }
   }
   free(ptr);
   return 0;
}

void maxmin(int* ptr, int len){
   int max = *ptr;
   for (int i=0; i<len; i++){
      if (max < *(ptr+i)){
         max = *(ptr+i);
      }
   }

   int min = *ptr;
   for (int i=0; i<len; i++){
      if (min > *(ptr+i)){
         min = *(ptr+i);
      }
   }

   printf("Max Element: %d\n", max);
   printf("Min Element: %d\n", min);
}

void pos(int* ptr, int len){
   int key;
   printf("Enter the key : ");
   scanf("%d", &key);
   for (int i=0; i<len; i++){
      if (key == *(ptr+i)){
         printf("Position : %d\n", i);
      }
   }
}

void evenodd(int* ptr, int len){
   printf("Even Numbers: ");
   for (int i=0; i<len; i++){
      if (*(ptr+i)%2 == 0){
         printf("%d ", *(ptr+i));
      }
   }
   printf("\n");
   printf("Odd Numbers: ");
   for (int i=0; i<len; i++){
      if (*(ptr+i)%2 != 0){
         printf("%d ", *(ptr+i));
      } 
   }
   printf("\n");
}