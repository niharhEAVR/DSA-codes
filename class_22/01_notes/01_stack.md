### Stack Data Structure Explained with Visualization

A **stack** is a linear data structure that follows the **Last In, First Out (LIFO)** principle. The last element added (pushed) to the stack is the first one to be removed (popped).

---

### Key Operations
1. **Push**: Add an element to the top of the stack.
2. **Pop**: Remove the top element from the stack.
3. **Peek**: View the top element without removing it.
4. **Empty**: Check if the stack is empty.

---

### Real-World Analogy
Think of a **stack of plates** in a cafeteria:
- **Push**: Add a plate to the top of the stack.
- **Pop**: Take the top plate off the stack.
- **Peek**: Look at the top plate without removing it.
- **Empty**: Check if there are no plates left.

---

### Memory Visualization
A stack grows or shrinks dynamically in memory. Imagine a stack represented as an array:

#### Example Stack Operations
```c
+---+---+---+---+---+
|   |   |   |   |   |  <-- Empty stack
+---+---+---+---+---+

Push(10):
+---+---+---+---+---+
| 10|   |   |   |   |  <-- Top points to 10
+---+---+---+---+---+

Push(20):
+---+---+---+---+---+
| 10| 20|   |   |   |  <-- Top points to 20
+---+---+---+---+---+

Peek():
Top element is 20.

Pop():
+---+---+---+---+---+
| 10|   |   |   |   |  <-- Top points to 10
+---+---+---+---+---+

Empty():
No, the stack is not empty.
```

---

### C Implementation of Stack

Here’s how you can implement and use a stack in C:

```c
#include <stdio.h>
#include <stdbool.h>
#define MAX 5  // Maximum size of the stack

int stack[MAX]; // Array to store stack elements
int top = -1;   // Initialize stack as empty

// Function to push an element onto the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d.\n", value);
    } else {
        stack[++top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop.\n");
    } else {
        printf("Popped %d from the stack.\n", stack[top--]);
    }
}

// Function to peek at the top element of the stack
void peek() {
    if (top == -1) {
        printf("Stack is empty. Nothing to peek.\n");
    } else {
        printf("Top element is %d.\n", stack[top]);
    }
}

// Function to check if the stack is empty
bool isEmpty() {
    return top == -1;
}

int main() {
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
```

---

### Output of the Program
```arduino
Pushed 10 onto the stack.
Pushed 20 onto the stack.
Top element is 20.
Pushed 30 onto the stack.
Popped 30 from the stack.
Popped 20 from the stack.
Top element is 10.
Popped 10 from the stack.
Is stack empty? Yes
```

---

### Key Points
1. The **stack pointer (`top`)** keeps track of the topmost element.
2. **Overflow** occurs when trying to push onto a full stack.
3. **Underflow** occurs when trying to pop from an empty stack.
4. **Dynamic memory** can be used instead of arrays for a resizable stack.