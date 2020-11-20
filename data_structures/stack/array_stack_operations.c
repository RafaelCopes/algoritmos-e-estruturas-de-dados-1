#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned capacity;
    int *array;
};

struct Stack* createStack(unsigned capacity);
void push(struct Stack* stack, int item);
int pop(struct Stack* stack);
int peek(struct Stack* stack);
int isEmpty(struct Stack* stack);
int isFull(struct Stack* stack);
void printStack(struct Stack* stack);

int main() {
    struct Stack* stack = createStack(10);

    push(stack, 5);
    push(stack, 3);
    push(stack, 22);
    push(stack, 4);    
    push(stack, 36);
    push(stack, 65);

    printStack(stack);

    push(stack, 2);

    pop(stack);
    pop(stack);

    printf("%d is at the top of the stack\n", peek(stack));

    printStack(stack);

    printf("%d popped from stack\n", pop(stack));
    printf("%d is at the top of the stack\n", peek(stack));

    printStack(stack);

    return 0;
}

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));

    stack->capacity = capacity;
    stack ->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));

    return stack;
};

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
};

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
};

void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("The stack is full!\n");

        return;
    }

    stack->array[++stack->top] = item; 
    
    printf("%d pushed to stack!\n", item);
};

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("The stack is already empty!\n");

        return -1;
    }

    return stack->array[stack->top--];
};

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }

    return stack->array[stack->top];
};

void printStack(struct Stack* stack) {
    printf("\n");

    for (int i = stack->top; i >= 0; i--) {   
        if (stack->array[i]) {
            printf("%d\n", stack->array[i]);
        }
    }
    printf("\n");
};
