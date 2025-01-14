#include <stdio.h>
#include <stdbool.h>
#define MAX 5 // Maximum size of the stack

int stack[MAX]; // Array to store stack elements
int top = -1;   // Initialize stack as empty

// Function to push an element onto the stack
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow! Cannot push %d.\n", value);
    }
    else
    {
        stack[++top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

// Function to pop an element from the stack
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! Cannot pop.\n");
    }
    else
    {
        printf("Popped %d from the stack.\n", stack[top--]);
    }
}

// Function to peek at the top element of the stack
void peek()
{
    if (top == -1)
    {
        printf("Stack is empty. Nothing to peek.\n");
    }
    else
    {
        printf("Top element is %d.\n", stack[top]);
    }
}

// Function to check if the stack is empty
bool isEmpty()
{
    return top == -1;
}

int main()
{
    // Example usage of stack operations
    push(10);
    push(20);
    peek();
    push(30);
    pop();
    pop();
    peek();
    pop();
    printf("Is stack empty? %s\n", isEmpty() ? "Yes" : "No");
    return 0;
}
