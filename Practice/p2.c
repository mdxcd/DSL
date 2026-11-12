// Binary Search

#include <stdio.h>

int binary_search(int n, int arr[], int key){
    int l=0, r=n-1;

    while(l<=r){
        int mid = (l+r)/2;
        if (arr[mid] == key){
            return mid;
        } else if (arr[mid] < key){
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int index = binary_search(8, arr, 7);\

    if (index != -1)
        printf("Key found at index %d\n", index);
    else
        printf("Key is not present\n");

    return 0;
}