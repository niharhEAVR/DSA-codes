#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

// Function to check if the stack is empty
int isEmpty(struct stack *ptr)
{
    return ptr->top == -1;
}

// Function to check if the stack is full
int isFull(struct stack *ptr)
{
    return ptr->top == ptr->size - 1;
}

// Function to push an element onto the stack
void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d.\n", value);
    }
    else
    {
        ptr->arr[++(ptr->top)] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

// Function to pop an element from the stack
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop.\n");
        return -1; // Return an invalid value to indicate error
    }
    else
    {
        int poppedValue = ptr->arr[ptr->top];
        printf("Popped %d from the stack.\n", poppedValue);
        ptr->arr[(ptr->top)--] = 0;
    }
}

// Function to peek at the top element of the stack
int peek(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is empty. Nothing to peek.\n");
        return -1; // Return an invalid value to indicate error
    }
    else
    {
        for (int i = 0; i < ptr->size; i++)
        {
            printf("%d ",ptr->arr[i]);
        }
        return ptr->arr[ptr->top];
    }
}

int main()
{
    // Dynamically allocate memory for the stack structure
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    if (s == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    for (int i = 0; i < s->size; i++)
    {
        s->arr[i] = 0;
    }
    
    if (s->arr == NULL)
    {
        printf("Memory allocation for array failed.\n");
        free(s); // Free the stack structure if array allocation fails
        return 1;
    }

    printf("Size of struct stack: %lu bytes\n", sizeof(struct stack));
    printf("Size of dynamically allocated arr: %lu bytes\n", s->size * sizeof(int));
    printf("Total allocated memory: %lu bytes\n", sizeof(struct stack) + (s->size * sizeof(int)));

    // Example usage
    push(s, 10);
    push(s, 20);
    push(s, 30);

    printf("Top element is: %d\n", peek(s));

    pop(s);
    pop(s);

    printf("Top element is: %d\n", peek(s));

    // Free allocated memory
    free(s->arr);
    free(s);

    return 0;
}
