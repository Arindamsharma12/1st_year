#include<iostream>
using namespace std;

void display(int arr[], int size){
    // Traversal
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

int indInsertion(int arr[], int size, int capacity, int element, int index){
    // Code for insertion
    if(size > capacity){
        return -1;
    }
    for(int i = (size -1); i >= index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main(){
     int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, capacity = 100, index = 4, element = 45;
    display(arr, size);
    int insert = indInsertion(arr, size, capacity, element, index);

    if(insert == 1){
        cout<<"Insertion is successfull!"<<endl;
        size += 1;
        display(arr, size);
    }
    return 0;
}