#include<stdio.h>
#include<stdlib.h>

// *******Doublly Linked List******
struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

void linked_list_traversal(struct Node *head){
    struct Node * ptr = head;
    while(ptr != NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void forward_and_reverse_traversal(struct Node *head){
    struct Node * ptr = head;
    struct Node * ptr1;
    printf("***Up ---> Down***\n");
    do{        
        
        printf("Element: %d\n", ptr->data);
        if(ptr->next == NULL){
            ptr1 = ptr;
        }
        ptr = ptr->next;

    }while(ptr != NULL);
    
    
    printf("***Down ---> Up***\n");
    do{
        printf("Element: %d\n", ptr1->data);
        ptr1 = ptr1->prev;
    }while(ptr1 != NULL);
}

int main(){
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * second = (struct Node *)malloc(sizeof(struct Node));
    struct Node * third = (struct Node *)malloc(sizeof(struct Node));
    struct Node * fourth = (struct Node *)malloc(sizeof(struct Node));
    
    head->prev = NULL;
    head->data = 4;
    head->next = second;
    
    second->prev = head;
    second->data = 7;
    second->next = third;
    
    third->prev = second;
    third->data = 9;
    third->next = fourth;
    
    fourth->prev = third;
    fourth->data = 11;
    fourth->next = NULL;

    forward_and_reverse_traversal(head);
    return 0;
}