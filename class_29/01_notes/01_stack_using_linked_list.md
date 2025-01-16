### Implementing Stack Using Linked List in C

In C, we use structures to define the **Node** and the **Stack**. Here's how:

#### Code Implementation

```c
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Push operation
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top; // Link the new node to the previous top
    *top = newNode;       // Update the top pointer
    printf("Pushed %d onto the stack.\n", data);
}

// Pop operation
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty! Cannot pop.\n");
        return -1;
    }
    struct Node* temp = *top;
    int poppedData = temp->data;
    *top = (*top)->next; // Update the top pointer
    free(temp);          // Free the memory of the popped node
    printf("Popped %d from the stack.\n", poppedData);
    return poppedData;
}

// Peek operation
int peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty! Nothing to peek.\n");
        return -1;
    }
    return top->data;
}

// Check if stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Main function
int main() {
    struct Node* stack = NULL; // Initialize an empty stack

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element is: %d\n", peek(stack));

    pop(&stack);
    pop(&stack);

    printf("Stack is empty: %s\n", isEmpty(stack) ? "Yes" : "No");

    return 0;
}
```

---

### Explanation of the Code

1. **Node Structure**:
   - Each node represents an element in the stack.
   - Contains `data` (the value) and `next` (pointer to the next node).

2. **Push Operation**:
   - Creates a new node.
   - Links it to the current top.
   - Updates the top pointer to the new node.

3. **Pop Operation**:
   - Retrieves the data from the top node.
   - Updates the top pointer to the next node.
   - Frees the memory of the removed node.

4. **Peek Operation**:
   - Returns the data of the top node without removing it.

5. **IsEmpty**:
   - Checks if the top pointer is `NULL`.

---

### How the Stack Works with Linked List

- **Dynamic Memory Management**: Unlike an array-based stack, a linked list-based stack doesn’t require predefining the size. Nodes are dynamically created as needed.
- **Top of the Stack**: The `top` pointer always points to the last inserted node, making push and pop operations efficient with O(1) time complexity.

---

### Why Use a Stack with Linked List?

#### Real-World Analogy: Plates in a Cafeteria
- Imagine a stack of plates in a cafeteria. You can only add or remove plates from the top.
- **Push**: Add a plate on top.
- **Pop**: Remove the top plate.
- **Peek**: Check the top plate without removing it.

In this analogy:
- Each plate is a node.
- The stack of plates is the linked list.

#### Advantages in Real Life
1. **Undo/Redo Functionality**:
   - In text editors, the undo operation uses a stack to keep track of changes.
   - The most recent change is at the top (LIFO).

2. **Browser Backtracking**:
   - When you navigate web pages, the back button uses a stack to store the history of visited pages.

3. **Expression Evaluation**:
   - In calculators or compilers, stacks are used to evaluate expressions (e.g., postfix or infix).

4. **Recursive Function Calls**:
   - The system stack in memory uses a similar structure to manage function calls and return addresses.

---

### Why Linked List Over Array for Stacks?

| Feature                | Linked List Stack          | Array Stack           |
|------------------------|----------------------------|-----------------------|
| **Memory Usage**       | Dynamic, uses memory as needed. | Fixed, predefined size. |
| **Overflow**           | No overflow if memory is available. | Can overflow if capacity is reached. |
| **Resize Complexity**  | No resizing needed.        | Resizing requires copying elements. |
| **Efficiency**         | O(1) for push and pop.     | O(1) for push and pop, but resizing can be costly. |



---
---
---



Let’s visualize how the memory layout changes during the execution of your program.

---

### Memory Visualization During Execution

#### 1. **Program Start**
- `stack` is initialized as `NULL`.
- No memory is allocated yet.

**Memory:**
```
stack -> NULL
```

---

#### 2. **Push 10**
- A new node is created with `data = 10`.
- `newNode->next` points to the current `stack` (which is `NULL`).
- `stack` is updated to point to the new node.

**Memory:**
```
stack -> [10 | NULL]
```

---

#### 3. **Push 20**
- A new node is created with `data = 20`.
- `newNode->next` points to the current `stack` (which is `[10 | NULL]`).
- `stack` is updated to point to the new node.

**Memory:**
```
stack -> [20 | *] -> [10 | NULL]
```

---

#### 4. **Push 30**
- A new node is created with `data = 30`.
- `newNode->next` points to the current `stack` (which is `[20 | *]`).
- `stack` is updated to point to the new node.

**Memory:**
```
stack -> [30 | *] -> [20 | *] -> [10 | NULL]
```

---

#### 5. **Peek**
- The `peek` function accesses `stack->data` without modifying the structure.
- The output is `30`.

---

#### 6. **Pop**
- The `pop` function retrieves `stack->data` (30).
- `stack` is updated to point to `stack->next` (which is `[20 | *]`).
- The node `[30 | *]` is freed.

**Memory:**
```
stack -> [20 | *] -> [10 | NULL]
```

---

#### 7. **Pop Again**
- The `pop` function retrieves `stack->data` (20).
- `stack` is updated to point to `stack->next` (which is `[10 | NULL]`).
- The node `[20 | *]` is freed.

**Memory:**
```
stack -> [10 | NULL]
```

---

#### 8. **Check If Empty**
- The `isEmpty` function checks if `stack == NULL`.
- Since `stack` points to `[10 | NULL]`, it returns `false`.

---

#### 9. **Final State**
- If you continue popping, eventually `stack` will point to `NULL`, indicating the stack is empty.

**Memory (after final pop):**
```
stack -> NULL
```

---

### Key Points About Memory Allocation
1. **Dynamic Allocation**:
   - Each node is allocated memory dynamically using `malloc`.
   - The `free` function releases memory when a node is popped.

2. **Pointer Updates**:
   - The `stack` pointer always points to the top node.
   - `next` pointers connect the nodes, forming a chain.

3. **Stack Growth**:
   - As you push elements, memory is allocated for each new node.
   - The stack "grows" dynamically in memory.

4. **Stack Shrinkage**:
   - When you pop elements, memory is released, and the stack "shrinks."
