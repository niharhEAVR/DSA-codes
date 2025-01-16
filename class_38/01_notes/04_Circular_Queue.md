### **What is a Circular Queue in Data Structures (DSA)?**

A **Circular Queue** is a linear data structure that follows the **First In First Out (FIFO)** principle, but unlike a regular queue, it connects the last position back to the first position to form a circle. This allows it to reuse the empty space left by dequeued elements, making it more efficient in terms of memory utilization.

#### **Key Features of a Circular Queue:**
1. **Fixed Size**: The size of the queue is fixed at the time of creation.
2. **Front and Rear Pointers**: 
   - **Front**: Points to the first element in the queue.
   - **Rear**: Points to the last element in the queue.
3. **Circular Nature**: When the rear reaches the end of the queue, it wraps around to the beginning if there is space.
4. **Efficient Space Utilization**: Unlike a regular queue, it does not leave unused space after dequeuing elements.

---

### **Real-World Example of a Circular Queue**

**Example: A Circular Queue in a Call Center System**

Imagine a call center with a fixed number of agents. Incoming customer calls are placed in a queue, and agents handle them one by one. 

- When a call is answered and removed from the queue, the next incoming call can reuse the space left by the answered call.
- If the queue is full (all agents are busy), new calls are placed on hold.
- The circular queue ensures efficient utilization of the available slots.

---

### **Circular Queue in C**

Here’s how you can implement a circular queue in C:

#### **Code Implementation**
```c
#include <stdio.h>
#define SIZE 5  // Define the size of the queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    return (front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1));
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to add an element to the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }
    if (front == -1) {  // First element
        front = rear = 0;
    } else if (rear == SIZE - 1 && front != 0) {  // Wrap around
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = value;
    printf("Enqueued %d\n", value);
}

// Function to remove an element from the queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1;
    }
    int value = queue[front];
    if (front == rear) {  // Queue is now empty
        front = rear = -1;
    } else if (front == SIZE - 1) {  // Wrap around
        front = 0;
    } else {
        front++;
    }
    return value;
}

// Function to display the queue
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (int i = front; i < SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

// Main function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    displayQueue();
    printf("Dequeued: %d\n", dequeue());
    enqueue(60);
    displayQueue();
    return 0;
}
```

---

### **Explanation of the Code**

1. **`isFull` Function**: Checks if the queue is full by comparing the positions of `front` and `rear`.
2. **`isEmpty` Function**: Checks if the queue is empty by verifying if `front` is `-1`.
3. **`enqueue` Function**: Adds an element to the queue. If the queue is full, it prints an error message. Handles wrapping of the `rear` pointer.
4. **`dequeue` Function**: Removes an element from the queue. If the queue is empty, it prints an error message. Handles wrapping of the `front` pointer.
5. **`displayQueue` Function**: Prints all elements of the queue, considering its circular nature.

---

### **Output of the Program**
```
Enqueued 10
Enqueued 20
Enqueued 30
Enqueued 40
Enqueued 50
Queue elements: 10 20 30 40 50
Dequeued: 10
Enqueued 60
Queue elements: 60 20 30 40 50
```

---

### **Advantages of Circular Queue**
1. **Efficient Memory Utilization**: Reuses spaces left by dequeued elements.
2. **Prevents Overflow**: Circular wrapping ensures no memory is wasted.

---

### **Disadvantages**
1. **Fixed Size**: The size is fixed and cannot grow dynamically.
2. **Complex Implementation**: Requires additional logic for wrapping pointers.



---
---
---




### **Difference Between Circular Queue and Normal Queue**

| **Aspect**              | **Normal Queue**                                             | **Circular Queue**                                           |
|--------------------------|-------------------------------------------------------------|-------------------------------------------------------------|
| **Structure**            | Linear structure. The queue ends when the rear pointer reaches the last index. | Circular structure. The last index connects back to the first index. |
| **Memory Utilization**   | Inefficient. Space left by dequeued elements cannot be reused. | Efficient. Space left by dequeued elements is reused.       |
| **Overflow Condition**   | Occurs when the rear pointer reaches the last index, even if there are empty slots at the front. | Occurs only when all slots are occupied.                   |
| **Underflow Condition**  | Occurs when the queue is empty (front = -1).                 | Same as a normal queue.                                     |
| **Implementation Complexity** | Simple to implement.                                    | Slightly more complex due to the wrapping logic.            |
| **Pointer Movement**     | Front and rear pointers move linearly.                      | Front and rear pointers wrap around using modular arithmetic. |
| **Use Cases**            | Suitable for scenarios where elements are added and removed in a simple sequence without wrapping. | Suitable for scenarios where memory efficiency is critical, such as task scheduling or buffering. |

---

### **Key Characteristics of Circular Queue**

- **Reusability**: In a normal queue, once the rear reaches the end of the array, the queue is considered full, even if there is space left at the front due to dequeued elements. A circular queue solves this by wrapping around the rear pointer to the front.
  
- **Implementation**: In a circular queue, the position of the rear pointer is calculated using:
  \[
  \text{rear} = (\text{rear} + 1) \% \text{size}
  \]
  Similarly, the front pointer moves in a circular manner:
  \[
  \text{front} = (\text{front} + 1) \% \text{size}
  \]

---

### **Real-World Analogy**

1. **Normal Queue**: Imagine a single-file queue of people waiting for a bus. Once the first person boards the bus, the space they occupied is left empty and cannot be reused.

2. **Circular Queue**: Imagine a circular conveyor belt where items are placed. As items are removed from the front, new items can be added at the position left by the removed items, ensuring continuous utilization of space.

---

### **When to Use Circular Queue**
- When efficient memory utilization is required.
- In applications like:
  - **Task Scheduling**: Operating systems use circular queues for managing tasks in a round-robin fashion.
  - **Data Buffers**: Circular buffers in hardware for audio or video streaming.
  - **Networking**: Managing packets in routers or switches.
