#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node
{
    int data;          // Data of the node
    struct Node *next; // Pointer to the next node
};

// Define a structure for the stack
struct Stack
{
    struct Node *top; // Points to the top of the stack
    int size;         // Current size of the stack
    int maxSize;      // Maximum size of the stack
};

// Function to create a new stack with a fixed size
struct Stack *createStack(int maxSize)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = NULL;
    stack->size = 0;
    stack->maxSize = maxSize;
    return stack;
}

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->size == 0;
}

// Function to check if the stack is full
int isFull(struct Stack *stack)
{
    return stack->size == stack->maxSize;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int data)
{
    if (isFull(stack))
    {
        printf("Stack overflow! Cannot push %d\n", data);
        return;
    }
    struct Node *node = createNode(data);
    node->next = stack->top; // Link the new node to the top
    stack->top = node;       // Update the top pointer
    stack->size++;           // Increase the size
    printf("%d pushed to stack\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow! Nothing to pop\n");
        return -1; // Return -1 to indicate the stack is empty
    }
    struct Node *temp = stack->top;
    int popped = temp->data;
    stack->top = stack->top->next; // Update the top pointer
    free(temp);                    // Free the memory of the popped node
    stack->size--;                 // Decrease the size
    return popped;
}

// Function to display the full stack
void display(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty!\n");
        return;
    }
    struct Node *temp = stack->top;
    printf("Stack elements (top to bottom): ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to get the current size of the stack
int currentSize(struct Stack *stack)
{
    return stack->size;
}

// Main function to demonstrate stack operations
int main()
{
    int maxStackSize = 5; // Set a fixed size for the stack
    struct Stack *stack = createStack(maxStackSize);

    while (1)
    {
        int ans;
        printf("1.push value in the stack\n2.pop value from the stack\n3.display stack\n4.exit\nEnter your choice: ");
        scanf("%d", &ans);
        int value = 0;
        switch (ans)
        {
        case 1:
            printf("Enter the value you want to push: ");
            scanf("%d", &value);
            push(stack, value);
            printf("\n");
            break;
        case 2:
            printf("Popped element: %d\n", pop(stack));
            printf("\n");
            break;
        case 3:
            display(stack);
            printf("Current stack size: %d\n", currentSize(stack));
            printf("\n");
            break;
        case 4:
            printf("Exiting...!");
            return 0;
        default:
            printf("Wrong input!");
            return 0;
        }
    }
}
