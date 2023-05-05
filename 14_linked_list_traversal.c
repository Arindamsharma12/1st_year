#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * Next;    
};

void linkedListTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Elements: %d\n", ptr->data);
        ptr = ptr->Next;
    }
}

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;
    
    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->Next = second;

    // Link second and third nodes
    second->data = 11;
    second->Next = third;
    
    // Link third and forth nodes
    third->data = 66;
    third->Next = fourth;

    // Terminate the list at third node
    fourth->data = 78;
    fourth->Next = NULL;

    linkedListTraversal(head);
    return 0;
}