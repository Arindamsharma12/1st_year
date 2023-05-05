#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack * ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack * ptr){
    if(ptr->top == (ptr->size - 1)){
        return 1;
    }
    else{
        return 0;
    }
}

void push(char value, struct stack *ptr){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", value);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int parenthesis_match(char *exp){
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size*sizeof(char));
    char c;
    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] == '('){
            push(exp[i],sp);
        }
        else if(exp[i] == ')'){
            if(isEmpty(sp)){
                return 0;
            }
            c = pop(sp);
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char *exp = "3*2 - (8+1)";
    if(parenthesis_match(exp)){
        printf("The parenthesis is matching\n");
    }
    else{
        printf("The parenthesis is not matching\n");
    }

    return 0;
}