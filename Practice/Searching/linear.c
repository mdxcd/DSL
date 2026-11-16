// Linear Search

#include <stdio.h>

int linear_search(int n, int arr[], int key){
    for (int i=0; i<n; i++){
        if (arr[i] == key){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int index = linear_search(8, arr, 7);\

    if (index != -1)
        printf("Key found at index %d\n", index);
    else
        printf("Key is not present\n");

    return 0;
}