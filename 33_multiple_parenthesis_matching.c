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


int match(char a, char b){
    if(a == '(' && b == ')'){
        return 1;    
    }
    if(a == '{' && b == '}'){
        return 1;
    }
    if(a == '[' && b == ']'){
        return 1;
    }
    return 0;
}

int parenthesis_match(char *exp){
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size*sizeof(char));
    char popped_ch;
    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            push(exp[i],sp);
        }
        else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}'){
            if(isEmpty(sp)){
                return 0;
            }
            popped_ch = pop(sp);
            if(!match(popped_ch,exp[i])){
                return 0;
            }
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
    char *exp = "[2-4*{7*<1+9>/3(4+7)}]";
    if(parenthesis_match(exp)){
        printf("The parenthesis are balanced\n");
    }
    else{
        printf("The parenthesis are not balanced\n");
    }

    return 0;
}