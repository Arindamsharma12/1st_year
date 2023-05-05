#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void printArray(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int Maximum(int *a, int n){
    int max = INT_MIN;
    for(int i = 0;i < n; i++){
        if(max < a[i]){
            max = a[i];
        }
    }
    return max;
}

void countSort(int *A, int n){
    int i, j;
    //Find the maximum element in A
    int max = Maximum(A,n);

    //Create the count array
    int *count = (int *)malloc((max+1)*sizeof(int));

    //Initialize the array elements to 0
    for(int i = 0; i < max+1; i++){
        count[i] = 0;
    }

    // Increament the corresponding index in the count array
    for(int i = 0; i < n; i++){
        count[A[i]] = count[A[i]] + 1;
    }
    i = 0; // counter for the count array.
    j = 0; // counter for the given array.
    while(i < max+1){
        if(count[i] > 0){
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else{
            i++;
        }
    }
}

int main(){
    int A[] = {6,14,9,3,2,1,7,3,4};
    int n = sizeof(A)/sizeof(int);
    printArray(A,n);
    countSort(A,n);
    printArray(A,n);   
    return 0;
}