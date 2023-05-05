#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linked_list_traversal(struct Node * head){
    struct Node * ptr = head;
    do{
        printf("Elemet: %d \n", ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
}

//Insertion in Circular Linked List.
struct Node* insertion_at_first(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;


    while(p->next != head){
        p = p->next; 
    }
    //p points to last node of this linked list.
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node* )malloc(sizeof(struct Node));
    second = (struct Node* )malloc(sizeof(struct Node));
    third = (struct Node* )malloc(sizeof(struct Node));
    fourth = (struct Node* )malloc(sizeof(struct Node));
    
    head->data = 4;
    head->next = second;
    
    second->data = 3;
    second->next = third;
    
    third->data = 6;
    third->next = fourth;
    
    fourth->data = 1;
    fourth->next = head;

    printf("***Before Insertion***\n");
    linked_list_traversal(head);

    head = insertion_at_first(head, 80);

    printf("***After Insertion***\n");
    linked_list_traversal(head);

    return 0;
}