#include<stdio.h>

int linearSearch(int arr[], int size, int element){
    for(int i = 0; i < size; i++){
        if(arr[i] == element){
            return i;
        }
        
    }
    return -1;
}

int binarySearch(int arr[], int size, int elememt){
    int low, mid, high;
    low = 0;
    high = size - 1;
    // Keep searching until low <= high.
    while (low <= high){
        mid = (low + high)/2;
        if(arr[mid] == elememt){
            return mid;
        }
        if(arr[mid]<elememt){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    // Search ends.
    return -1;
}


int main(){
    // Unsorted array for linear search.
    // int arr[] = {1, 3, 5, 56, 4, 3, 23, 5, 4, 543, 56, 34};
    // int size = sizeof(arr)/sizeof(int);

    // Sorted array for binary search.
    int arr[] = {1, 3, 5, 56, 64, 73, 123, 225, 444};
    int size = sizeof(arr)/sizeof(int);
    int element = 1;
    int searchIndex = binarySearch(arr, size, element);

    printf("The element %d was found at index %d \n", element, searchIndex);

    return 0;
}