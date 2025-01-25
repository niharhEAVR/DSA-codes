To implement a **stack using a linked list with a fixed size** and operations such as display, here’s how we can modify the code:

### Enhanced Stack Using Linked List in C
```c
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node {
    int data;              // Data of the node
    struct Node* next;     // Pointer to the next node
};

// Define a structure for the stack
struct Stack {
    struct Node* top;      // Points to the top of the stack
    int size;              // Current size of the stack
    int maxSize;           // Maximum size of the stack
};

// Function to create a new stack with a fixed size
struct Stack* createStack(int maxSize) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    stack->size = 0;
    stack->maxSize = maxSize;
    return stack;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->size == 0;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->size == stack->maxSize;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d\n", data);
        return;
    }
    struct Node* node = createNode(data);
    node->next = stack->top; // Link the new node to the top
    stack->top = node;       // Update the top pointer
    stack->size++;           // Increase the size
    printf("%d pushed to stack\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Nothing to pop\n");
        return -1; // Return -1 to indicate the stack is empty
    }
    struct Node* temp = stack->top;
    int popped = temp->data;
    stack->top = stack->top->next; // Update the top pointer
    free(temp);                    // Free the memory of the popped node
    stack->size--;                 // Decrease the size
    return popped;
}

// Function to peek at the top element of the stack
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1; // Return -1 to indicate the stack is empty
    }
    return stack->top->data;
}

// Function to display the full stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    struct Node* temp = stack->top;
    printf("Stack elements (top to bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to get the current size of the stack
int currentSize(struct Stack* stack) {
    return stack->size;
}

// Main function to demonstrate stack operations
int main() {
    int maxStackSize = 5; // Set a fixed size for the stack
    struct Stack* stack = createStack(maxStackSize);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    push(stack, 60); // Attempting to push beyond the stack limit

    display(stack);
    printf("Current stack size: %d\n", currentSize(stack));

    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));
    printf("Top element: %d\n", peek(stack));

    display(stack);
    printf("Current stack size: %d\n", currentSize(stack));

    return 0;
}
```

### Changes and Additional Features
1. **Fixed Size**:  
   - Added a `maxSize` field in the `Stack` structure to define the maximum number of elements.  
   - Added a `size` field to track the current size.

2. **Check Stack Full**:  
   - Introduced `isFull` to check if the stack size has reached its `maxSize`.

3. **Display the Full Stack**:  
   - The `display` function prints all elements in the stack from top to bottom.

4. **Get Current Size**:  
   - `currentSize` returns the current number of elements in the stack.

5. **Enhanced Push and Pop**:  
   - `push` checks `isFull` before adding an element.  
   - `pop` decrements the stack size after removing an element.

### Sample Output
```plaintext
10 pushed to stack
20 pushed to stack
30 pushed to stack
40 pushed to stack
50 pushed to stack
Stack overflow! Cannot push 60
Stack elements (top to bottom): 50 40 30 20 10
Current stack size: 5
Popped element: 50
Popped element: 40
Top element: 30
Stack elements (top to bottom): 30 20 10
Current stack size: 3
```

This code ensures the stack adheres to a fixed size, prevents overflows and underflows, and allows for displaying all elements, making it more versatile.

---
---
---

Certainly! Here’s a **memory visualization** for the given linked-list-based stack implementation in C, step-by-step, after performing some operations.

### Example Operations
1. Create a stack with `maxSize = 5`.
2. Push the elements `10`, `20`, `30`, and `40`.
3. Pop an element.
4. Display the stack.

---

### Initial State (`maxSize = 5`)
```
Stack
+------+---------+
| Top  |   NULL  |
+------+---------+
| Size |    0    |
+------+---------+
```

---

### Step 1: Push `10`
- A new node is created in memory with `data = 10` and `next = NULL`.
- The `top` pointer of the stack now points to this node.

```
Memory
+------------+          +-------+
| Stack      |          | Node  |
| +--------+ |          | +---+ |
| | Top    | | -------> |  10|NULL
| +--------+ |          +-------+
| | Size   | |             
| |   1    | |             
| +--------+ |             
+------------+
```

---

### Step 2: Push `20`
- A new node is created with `data = 20`.
- `20->next` points to the current `top` (`10`).
- Update `top` to the new node.

```
Memory
+------------+          +-------+      +-------+
| Stack      |          | Node  |      | Node  |
| +--------+ |          | +---+ |      | +---+ |
| | Top    | | -------> |  20|* | ---> |  10|NULL
| +--------+ |          +-------+      +-------+
| | Size   | |             
| |   2    | |             
| +--------+ |             
+------------+
```

---

### Step 3: Push `30`
- A new node is created with `data = 30`.
- `30->next` points to the current `top` (`20`).
- Update `top` to the new node.

```
Memory
+------------+          +-------+      +-------+      +-------+
| Stack      |          | Node  |      | Node  |      | Node  |
| +--------+ |          | +---+ |      | +---+ |      | +---+ |
| | Top    | | -------> |  30|* | ---> |  20|* | ---> |  10|NULL
| +--------+ |          +-------+      +-------+      +-------+
| | Size   | |             
| |   3    | |             
| +--------+ |             
+------------+
```

---

### Step 4: Push `40`
- A new node is created with `data = 40`.
- `40->next` points to the current `top` (`30`).
- Update `top` to the new node.

```
Memory
+------------+          +-------+      +-------+      +-------+      +-------+
| Stack      |          | Node  |      | Node  |      | Node  |      | Node  |
| +--------+ |          | +---+ |      | +---+ |      | +---+ |      | +---+ |
| | Top    | | -------> |  40|* | ---> |  30|* | ---> |  20|* | ---> |  10|NULL
| +--------+ |          +-------+      +-------+      +-------+      +-------+
| | Size   | |             
| |   4    | |             
| +--------+ |             
+------------+
```

---

### Step 5: Pop an Element
- `top` points to the current top node (`40`).
- `40` is removed, and `top` is updated to the next node (`30`).
- The memory occupied by `40` is freed.

```
Memory
+------------+          +-------+      +-------+      +-------+
| Stack      |          | Node  |      | Node  |      | Node  |
| +--------+ |          | +---+ |      | +---+ |      | +---+ |
| | Top    | | -------> |  30|* | ---> |  20|* | ---> |  10|NULL
| +--------+ |          +-------+      +-------+      +-------+
| | Size   | |             
| |   3    | |             
| +--------+ |             
+------------+

(Note: The node for `40` is now freed and no longer in memory.)
```

---

### After Display Operation
When displaying the stack:
- Traverse the nodes starting from `top`:
  - Print `30 -> 20 -> 10 -> NULL`.

---

### Key Points
1. **Node Relationships**:
   - Each node has a `data` field and a `next` pointer that links to the next node in the stack.
2. **Dynamic Allocation**:
   - Memory for nodes is allocated dynamically when pushing and freed when popping.
3. **Visualization**:
   - The `top` pointer keeps track of the stack's head, and every node links to the previous node until `NULL` (the base of the stack).

Let me know if you'd like more clarification or another step visualized!