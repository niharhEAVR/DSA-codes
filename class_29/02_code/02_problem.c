// Paranthesis Matching Problem!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    char *array;
    int top;
    int capacity;
};

struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char *)malloc(capacity * sizeof(char));
    return stack;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, char item)
{
    stack->array[++stack->top] = item;
}

char pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        return '\0';
    }
    return stack->array[stack->top--];
}

char peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        return '\0';
    }
    return stack->array[stack->top];
}

// Function to check if two characters are matching pairs
int isMatchingPair(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Function to check if the parentheses are balanced
int isBalanced(char *expr)
{
    int n = strlen(expr);
    struct Stack *stack = createStack(n);

    for (int i = 0; i < n; i++)
    {
        char ch = expr[i];

        // Push opening brackets onto the stack
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(stack, ch);
        }
        // Handle closing brackets
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            // If stack is empty or brackets don't match, it's unbalanced
            if (isEmpty(stack) || !isMatchingPair(pop(stack), ch))
            {
                return 0;
            }
        }
    }

    // If stack is not empty, there are unmatched opening brackets
    int balanced = isEmpty(stack);
    free(stack);
    return balanced;
}

// Main function
int main()
{
    char expr[] = "{[(5+6)(a+b)*[c-d]]}";

    if (isBalanced(expr))
    {
        printf("The expression is balanced.\n");
    }
    else
    {
        printf("The expression is not balanced.\n");
    }

    return 0;
}
