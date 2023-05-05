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

int main(){
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");

    printf("Before pushing, Full: %d\n", isFull(sp));
    printf("Before pushing, Empty: %d\n", isEmpty(sp));
    push(56, sp);
    push(29, sp);
    push(21, sp);
    push(32, sp);
    push(46, sp);
    push(74, sp);
    push(91, sp);
    push(22, sp);
    push(86, sp);
    push(77, sp); // ---> Pushed 10 Values
   // push(69, sp); // Stack Overflow since the size of the stack is 10
    
    printf("After pushing, Full: %d\n", isFull(sp));
    printf("After pushing, Empty: %d\n", isEmpty(sp));

    printf("Popped %d from the stack\n", pop(sp)); // Last in first out(LIFO)
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));

    printf("After popping, Full: %d\n", isFull(sp));
    printf("After popping, Empty: %d\n", isEmpty(sp));
    return 0;
}