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

// CASE 1: Deleting First Element

struct Node* deleteFirst(struct Node *head){
    struct Node * ptr = head;
            head = head->Next;
            free(ptr);
            return head;
}

// CASE 2: Deleting the element at a given index from the linked list

struct Node * deleteAtIndex(struct Node * head, int index){
    struct Node * p = head;
    struct Node * q = head->Next;
    for(int i = 0; i < index - 1; i++){
        p = p->Next;
        q = q->Next;
    }

    p->Next = q->Next;
    free(q);
    return head;
}
// CASE 3: Deleting The last Element

struct Node* deleteTheLastNode(struct Node * head){
    struct Node * p = head;
    struct Node * q = head->Next;
    while(q->Next != NULL){
        p = p->Next;
        q = q->Next;
    }
    p->Next = NULL;
    free(q);
    return head;
}

// CASE 4: Deleting A Node with given node Element

struct Node * deleteTheValue(struct Node * head, int value){
    struct Node * p = head;
    struct Node * q = head->Next;
    while(q->data != value && q->Next != NULL){
        p = p->Next;
        q = q->Next;
    }
    if(q->data == value){
        p->Next = q->Next;
        free(q);
    }
    return head;
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
    head->data = 4;
    head->Next = second;

    // Link second and third nodes
    second->data = 8;
    second->Next = third;
    
    // Link third and forth nodes
    third->data = 3;
    third->Next = fourth;

    // Terminate the list at third node
    fourth->data = 1;
    fourth->Next = NULL;

    printf("Linked list before traversal:\n");
    linkedListTraversal(head);

    head = deleteTheValue(head, 8);
    printf("Linked list after traversal:\n");
    linkedListTraversal(head);
    
    return 0;
}