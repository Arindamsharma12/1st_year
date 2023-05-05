#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node;

struct Node * top = NULL; 

int isEmpty(struct Node * top){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void linkedListTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Elements: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isFull(struct Node * top){
    struct Node * n = (struct Node *)malloc(sizeof(struct Node));
    if(n == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

struct Node* push(struct Node * top, int value){
    if(isFull(top)){
        printf("Stack Overflow!\n");
    }
    else{
        struct Node * n = (struct Node *)malloc(sizeof(struct Node));
        n->data = value;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct Node *tp){
    if(isEmpty(tp)){
        printf("Stack Underflow\n");
    }
    else{
        struct Node * n = tp;
        top = (tp)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(int i){
    Node * ptr = top;
    for(int j = 0; (j < (i -1) && ptr != NULL); j++){
        ptr = ptr->next;
    }
    if(ptr != NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
}

int main(){
    top = push(top, 28);
    top = push(top, 18);
    top = push(top, 15);
    top = push(top, 7);
    // linkedListTraversal(top);
    for(int i = 1; i <= 4; i++){
        printf("Value at position %d is: %d\n",i, peek(i));
    }
    return 0;
}