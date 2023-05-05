#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Stack
{
    int size;
    int top;
    char *arr;
} Stack;

int isEmpty(Stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(Stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(Stack *sp, char element)
{
    if (isFull(sp))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n");
    }
    else
    {
        sp->top++;
        sp->arr[sp->top] = element;
    }
}

char pop(Stack *sp)
{
    char element;
    if (isEmpty(sp))
    {
        printf("Stack underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        element = sp->arr[sp->top];
        sp->top--;
        return element;
    }
}

char stackTop(Stack *sp)
{
    return sp->arr[sp->top];
}

int precedence(char ch){
    if(ch == '*' || ch == '/'){
        return 3;
    }
    else if(ch == '+' || ch == '-'){
        return 2;
    }
    else
        return 0;
}

int isOperator(char ch){
    if(ch == '*' || ch == '+' || ch == '-' || ch == '/'){
        return 1;
    }
    else{
        return 0;
    }
}

char *infixToPostfix(char *infix)
{
    Stack *sp = (Stack *)malloc(sizeof(Stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // Track infix traversal
    int j = 0; // Track postfix addition
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(infix[i]) > precedence(stackTop(sp))){
                push(sp,infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "x-y/z-k*d";
    printf("postfix is %s",infixToPostfix(infix));
    return 0;
}