#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100 
typedef struct Stack {
    int data[MAX_SIZE]; 
    int top;
} Stack;
void initStack(Stack* stack) {
    stack->top = -1; 
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1; }
int isEmpty(Stack* stack) {
    return stack->top == -1; } }
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    stack->data[++stack->top] = value; 
    printf("Pushed %d onto the stack.\n", value);
}
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
        return -1; }
    return stack->data[stack->top--]; }
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Cannot peek.\n");
        return -1; 
    }
    return stack->data[stack->top]; 
}
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}
int main() {
    Stack stack;
    initStack(&stack); 
    int value;
    char choice;
    do {
        printf("Enter a value to push onto the stack: ");
        scanf("%d", &value); 
        push(&stack, value);
        printf("Do you want to push another value? (y/n): ");
        scanf(" %c", &choice); 
    } while (choice == 'y' || choice == 'Y');
    display(&stack);
    int topValue = peek(&stack);
    if (topValue != -1) {
        printf("Top element is: %d\n", topValue);
    }
    do {
        int poppedValue = pop(&stack);
        if (poppedValue != -1) {
            printf("Popped %d from the stack.\n", poppedValue);
        }
        printf("Do you want to pop another value? (y/n): ");
        scanf(" %c", &choice); 
    } while (choice == 'y' || choice == 'Y');
    return 0;
}
