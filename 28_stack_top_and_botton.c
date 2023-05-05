#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *p){
    if(p->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Stack *p){
    if(p->top == p->size -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int value, struct Stack *ptr){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", value);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct Stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct Stack * ptr, int i){
    int arrIndex = ptr->top - i + 1;
    if(arrIndex < 0 ){
        printf("Not valid position for stack!\n");
        return -1;
    }
    else{
        return ptr->arr[arrIndex];
    }
}

int stackTop(struct Stack *ptr){
    return ptr->arr[ptr->top];
}

int stackBottom(struct Stack *ptr){
    return ptr->arr[0];
}

int main(){
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = 50;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");

    push(7, sp);
    push(9, sp);
    push(11, sp);
    push(15, sp);

    // Printing values from the stack.
    for(int j = 1; j <= sp->top + 1; j++){
        printf("The value at position %d is %d\n", j, peek(sp, j));
    }
    printf("The topmost value of this stack is %d\n", stackTop(sp));
    printf("The bottom most value of this stack is %d\n", stackBottom(sp));
    return 0;
}