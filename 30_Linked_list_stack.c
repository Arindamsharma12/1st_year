#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

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

int pop(struct Node **top){
    if(isEmpty(*top)){
        printf("Stack Underflow\n");
    }
    else{
        struct Node * n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}
int main(){
    struct Node * top = NULL; 
    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 8);
    linkedListTraversal(top);

    printf("%d is popped\n", pop(&top));
    printf("%d is popped\n", pop(&top));
    linkedListTraversal(top);
    return 0;
}