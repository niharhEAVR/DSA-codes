The **parenthesis matching problem** is a common problem in computer science that involves checking if parentheses (or other types of brackets) in an expression are properly balanced and correctly nested.

### Problem Definition

Given a string containing parentheses, brackets, or braces (e.g., `()`, `{}`, `[]`), determine if:
1. Every opening bracket has a corresponding closing bracket.
2. The brackets are properly nested.

For example:
- **Balanced**: `()`, `{[()]}`, `[{()}]`
- **Not Balanced**: `(]`, `([)]`, `{[}`

---

### Algorithm to Solve the Problem

The **stack** data structure is commonly used to solve this problem because of its Last In, First Out (LIFO) nature.

#### Steps:
1. Traverse the string character by character.
2. For each opening bracket (`(`, `{`, `[`), push it onto the stack.
3. For each closing bracket (`)`, `}`, `]`):
   - Check if the stack is empty:
     - If yes, the string is unbalanced (no matching opening bracket).
   - If no, pop the top of the stack and check if it matches the closing bracket:
     - If it matches, continue.
     - If it doesn't match, the string is unbalanced.
4. After traversing the string, check if the stack is empty:
   - If empty, the string is balanced.
   - If not, it means there are unmatched opening brackets.

---

### Example Code in C

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack structure
struct Stack {
    char* array;
    int top;
    int capacity;
};

// Function to create a stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(capacity * sizeof(char));
    return stack;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->array[stack->top--];
}

// Peek the top element of the stack
char peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->array[stack->top];
}

// Function to check if two characters are matching pairs
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Function to check if the parentheses are balanced
int isBalanced(char* expr) {
    int n = strlen(expr);
    struct Stack* stack = createStack(n);

    for (int i = 0; i < n; i++) {
        char ch = expr[i];

        // Push opening brackets onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            push(stack, ch);
        }
        // Handle closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {
            // If stack is empty or brackets don't match, it's unbalanced
            if (isEmpty(stack) || !isMatchingPair(pop(stack), ch)) {
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
int main() {
    char expr[] = "{[()]}";

    if (isBalanced(expr)) {
        printf("The expression is balanced.\n");
    } else {
        printf("The expression is not balanced.\n");
    }

    return 0;
}
```

---

### How It Works

1. **Input**: `{[()]}`
   - Push `{` onto the stack.
   - Push `[` onto the stack.
   - Push `(` onto the stack.
   - Encounter `)`:
     - Pop `(` from the stack and check if it matches `)`. It does.
   - Encounter `]`:
     - Pop `[` from the stack and check if it matches `]`. It does.
   - Encounter `}`:
     - Pop `{` from the stack and check if it matches `}`. It does.
   - The stack is empty, so the expression is balanced.

2. **Input**: `{[(])}`
   - Push `{`, `[`, and `(` onto the stack.
   - Encounter `]`:
     - Pop `(` from the stack and check if it matches `]`. It doesn't.
   - The expression is unbalanced.

---

### Real-World Applications

1. **Code Editors**:
   - Syntax highlighting and error detection in programming languages.
   - Ensures parentheses, braces, and brackets are properly matched.

2. **Mathematical Expressions**:
   - Validating expressions like `(a + b) * (c - d)`.

3. **Compilers**:
   - Ensuring the proper nesting of code blocks.
