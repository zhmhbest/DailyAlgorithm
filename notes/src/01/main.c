#include <stdio.h>
#include <stdlib.h>
#define ELEMENT int
#define ELEMENT_NULL 0


/*
 * Stack
 */
typedef struct {
    ELEMENT* buffer;
    ELEMENT* top;
    int capacity;
} Stack;


Stack* stack_create(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = stack->buffer = 
        (ELEMENT*)malloc(sizeof(ELEMENT)*capacity);
    stack->capacity = capacity;
    return stack;
}
void stack_drop(Stack* stack) {
    free(stack->buffer);
    free(stack);
}


int stack_empty(Stack* stack) {
    return stack->buffer == stack->top;
}
int stack_length(Stack* stack) {
    return stack->top - stack->buffer;
}
int stack_remains(Stack* stack) {
    return stack->capacity - (stack->top - stack->buffer);
}


ELEMENT stack_top(Stack* stack) {
    if ( stack_length(stack) > 0 ) {
        return stack->top[-1];
    } else {
        return ELEMENT_NULL;
    }
}
void stack_push(Stack* stack, ELEMENT ele) {
    if( stack_remains(stack) > 0 ) {
        *(stack->top)++ = ele;
    }
}
ELEMENT stack_pop(Stack* stack) {
    if ( stack_length(stack) > 0 ) {
        (stack->top)--;
        return *(stack->top);
    } else {
        return ELEMENT_NULL;
    }
}


int main() {
    // Create
    Stack* stack = stack_create(32);
    printf("top=%d\n", stack_top(stack));
    printf("empty=%d\n", stack_empty(stack));
    printf("length=%d\n", stack_length(stack));
    printf("remains=%d\n", stack_remains(stack));
    printf("\n");

    // Push
    stack_push(stack, 123);
    printf("top=%d\n", stack_top(stack));
    printf("empty=%d\n", stack_empty(stack));
    printf("length=%d\n", stack_length(stack));
    printf("remains=%d\n", stack_remains(stack));
    printf("\n");

    // Push
    stack_push(stack, 456);
    printf("top=%d\n", stack_top(stack));
    printf("empty=%d\n", stack_empty(stack));
    printf("length=%d\n", stack_length(stack));
    printf("remains=%d\n", stack_remains(stack));
    printf("\n");

    // Pop
    printf("pop=%d\n", stack_pop(stack));
    printf("top=%d\n", stack_top(stack));
    printf("empty=%d\n", stack_empty(stack));
    printf("length=%d\n", stack_length(stack));
    printf("remains=%d\n", stack_remains(stack));
    printf("\n");

    // Pop
    printf("pop=%d\n", stack_pop(stack));
    printf("top=%d\n", stack_top(stack));
    printf("empty=%d\n", stack_empty(stack));
    printf("length=%d\n", stack_length(stack));
    printf("remains=%d\n", stack_remains(stack));
    printf("\n");

    // Drop
    stack_drop(stack);
    return 0;
}
