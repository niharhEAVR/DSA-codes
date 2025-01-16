### **What is a Double-Ended Queue (Deque)?**

A **Double-Ended Queue (Deque)** is a data structure that allows elements to be added or removed from both ends of the queue (front and rear). It combines the properties of both a stack and a queue, providing flexibility in data management.

---

### **Types of Deques**
1. **Input-Restricted Deque**: Insertion is allowed only at one end, but deletion is possible from both ends.
2. **Output-Restricted Deque**: Deletion is allowed only at one end, but insertion is possible from both ends.

---

### **Real-World Analogy**
**Example: A Train with Two Entry/Exit Points**

Imagine a train with doors at both the front and rear:
- Passengers can **enter** or **exit** from either the front or rear doors.
- This flexibility allows efficient handling of passenger flow during peak hours or emergencies.

---

### **Key Operations in a Deque**
1. **Insert Front**: Add an element at the front.
2. **Insert Rear**: Add an element at the rear.
3. **Delete Front**: Remove an element from the front.
4. **Delete Rear**: Remove an element from the rear.
5. **IsEmpty**: Check if the deque is empty.
6. **IsFull**: Check if the deque is full.

---

### **Implementation of Deque in C**

Here’s a simple implementation using an array:

```c
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

// Structure for the deque
struct Deque {
    int arr[SIZE];
    int front;
    int rear;
};

// Initialize the deque
void initializeDeque(struct Deque* dq) {
    dq->front = -1;
    dq->rear = -1;
}

// Check if the deque is full
int isFull(struct Deque* dq) {
    return (dq->front == 0 && dq->rear == SIZE - 1) || (dq->front == dq->rear + 1);
}

// Check if the deque is empty
int isEmpty(struct Deque* dq) {
    return dq->front == -1;
}

// Insert an element at the front
void insertFront(struct Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full. Cannot insert %d at front.\n", value);
        return;
    }
    if (dq->front == -1) {  // First element
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {  // Wrap around
        dq->front = SIZE - 1;
    } else {
        dq->front--;
    }
    dq->arr[dq->front] = value;
    printf("Inserted %d at front.\n", value);
}

// Insert an element at the rear
void insertRear(struct Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full. Cannot insert %d at rear.\n", value);
        return;
    }
    if (dq->front == -1) {  // First element
        dq->front = dq->rear = 0;
    } else if (dq->rear == SIZE - 1) {  // Wrap around
        dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->arr[dq->rear] = value;
    printf("Inserted %d at rear.\n", value);
}

// Delete an element from the front
int deleteFront(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot delete from front.\n");
        return -1;
    }
    int value = dq->arr[dq->front];
    if (dq->front == dq->rear) {  // Single element
        dq->front = dq->rear = -1;
    } else if (dq->front == SIZE - 1) {  // Wrap around
        dq->front = 0;
    } else {
        dq->front++;
    }
    printf("Deleted %d from front.\n", value);
    return value;
}

// Delete an element from the rear
int deleteRear(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot delete from rear.\n");
        return -1;
    }
    int value = dq->arr[dq->rear];
    if (dq->front == dq->rear) {  // Single element
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {  // Wrap around
        dq->rear = SIZE - 1;
    } else {
        dq->rear--;
    }
    printf("Deleted %d from rear.\n", value);
    return value;
}

// Display the deque
void displayDeque(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements: ");
    if (dq->rear >= dq->front) {
        for (int i = dq->front; i <= dq->rear; i++) {
            printf("%d ", dq->arr[i]);
        }
    } else {
        for (int i = dq->front; i < SIZE; i++) {
            printf("%d ", dq->arr[i]);
        }
        for (int i = 0; i <= dq->rear; i++) {
            printf("%d ", dq->arr[i]);
        }
    }
    printf("\n");
}

// Main function
int main() {
    struct Deque dq;
    initializeDeque(&dq);

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    displayDeque(&dq);

    deleteFront(&dq);
    displayDeque(&dq);

    insertRear(&dq, 30);
    insertFront(&dq, 2);
    displayDeque(&dq);

    deleteRear(&dq);
    displayDeque(&dq);

    return 0;
}
```

---

### **Explanation**

1. **Array Representation**:
   - The deque is implemented as a circular array to allow wrapping of the `front` and `rear` pointers.

2. **Insert Operations**:
   - **`insertFront`**: Decrements the `front` pointer and inserts the value.
   - **`insertRear`**: Increments the `rear` pointer and inserts the value.

3. **Delete Operations**:
   - **`deleteFront`**: Removes the element at the `front` pointer and adjusts the pointer.
   - **`deleteRear`**: Removes the element at the `rear` pointer and adjusts the pointer.

4. **Wrap Around**:
   - If the `front` or `rear` reaches the end of the array, it wraps around to the beginning.

---

### **Output**

```
Inserted 10 at rear.
Inserted 20 at rear.
Inserted 5 at front.
Deque elements: 5 10 20
Deleted 5 from front.
Deque elements: 10 20
Inserted 30 at rear.
Inserted 2 at front.
Deque elements: 2 10 20 30
Deleted 30 from rear.
Deque elements: 2 10 20
```

---

### **Advantages of Deque**
1. **Flexibility**: Allows insertion and deletion from both ends.
2. **Efficient Memory Usage**: Circular structure ensures no space is wasted.

### **Applications**
1. **Task Scheduling**: Managing priorities in operating systems.
2. **Sliding Window Problems**: Efficiently handling subarray or subsequence problems.
3. **Palindrome Checking**: Adding and removing characters from both ends. 
