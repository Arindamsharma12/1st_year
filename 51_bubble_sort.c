#include<stdio.h>

void printArray(int* A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void bubble_sort_adaptive(int *A, int n){
    int temp;
    int isSorrted = 0; // For making it adaptive;
    for(int i = 0; i < n - 1; i++)  // FOR NUMBER OF PASSES
    { 
        printf("Working on pass number %d\n",i+1);
        isSorrted = 1;
        for(int j = 0; j < n - 1 - i; j++) // FOR NUMBER OF COMPARISONS IN EACH PASS
        {
            if(A[j] > A[j+1]){
                temp = A[j];
                    A[j] = A[j+1];
                    A[j+1] = temp;
                    isSorrted = 0;
            }
        }
        if(isSorrted){
            return;
        }
    }
}

void bubble_sort(int *A, int n){
    int temp;
   
    for(int i = 0; i < n - 1; i++)  // FOR NUMBER OF PASSES
    { 
        printf("Working on pass number %d\n",i+1);
            for(int j = 0; j < n - 1 - i; j++) // FOR NUMBER OF COMPARISONS IN EACH PASS
        {
            if(A[j] > A[j+1]){
                temp = A[j];
                    A[j] = A[j+1];
                    A[j+1] = temp;
                    
            }
        }
    }
}

int main(){
    int A[] = {12, 54, 65, 7, 23, 9};
    //int A[] = {1,2,3,4,5,6}; //--> Already Sorted Array

    int n = sizeof(A)/sizeof(int);
    printArray(A,n);// Array Before Sorting.
    bubble_sort(A,n);
    // bubble_sort_adaptive(A,n);
    printArray(A,n);// Array After Sorting.
    return 0;
}