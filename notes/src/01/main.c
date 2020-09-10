#include <stdio.h>
#include <stdlib.h>
#define ELEMENT int


/*
 * Stack
 */
typedef struct {
    ELEMENT* buffer;
    ELEMENT* top;
    int length;
} Stack;


Stack* stack_create(int length) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = stack->buffer = 
        (ELEMENT*)malloc(sizeof(ELEMENT)*length);
    stack->length = length;
    return stack;
}


void stack_drop(Stack* stack) {
    free(stack->buffer);
    free(stack);
}


int stack_length(Stack* stack) {
    return stack->top - stack->buffer;
}


int stack_empty(Stack* stack) {
    return stack->buffer == stack->top;
}


ELEMENT stack_top(Stack* stack) {
    if ( (stack->top-stack->buffer) > 0 ) {
        return stack->top[-1];
    } else {
        return -1;
    }
}


void stack_push(Stack* stack, ELEMENT ele) {
    if( (stack->top-stack->buffer) < stack->length ) {
        *(stack->top)++ = ele;
    }
}


ELEMENT stack_pop(Stack* stack) {
    if ( (stack->top-stack->buffer) > 0 ) {
        (stack->top)--;
        return *(stack->top);
    } else {
        return -1;
    }
}


int main() {
    Stack* stack = stack_create(32);
    printf("empty=%d\n", stack_empty(stack));
    printf("\n");
    
    stack_push(stack, 123);
    printf("length=%d\n", stack_length(stack));
    printf("empty=%d\n", stack_empty(stack));
    printf("top=%d\n", stack_top(stack));
    printf("\n");

    stack_push(stack, 456);
    printf("length=%d\n", stack_length(stack));
    printf("empty=%d\n", stack_empty(stack));
    printf("top=%d\n", stack_top(stack));
    printf("\n");

    printf("pop=%d\n", stack_pop(stack));
    printf("empty=%d\n", stack_empty(stack));
    printf("\n");

    printf("pop=%d\n", stack_pop(stack));
    printf("empty=%d\n", stack_empty(stack));
    printf("\n");

    stack_drop(stack);
    return 0;
}
