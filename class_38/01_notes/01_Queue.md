### **Queue in Data Structures and Algorithms (DSA)**

A **queue** is a linear data structure that follows the **First In, First Out (FIFO)** principle. This means that the first element added to the queue will be the first one to be removed, just like in a real-world queue (e.g., a line at a ticket counter).

In a queue:
- **Enqueue**: Adding an element to the end of the queue.
- **Dequeue**: Removing an element from the front of the queue.
- **Front**: The element at the front of the queue.
- **Rear**: The element at the end of the queue.
- **Peek**: Checking the element at the front without removing it.
- **IsEmpty**: Checking if the queue is empty.

### **Real-World Analogy for Queue**

Imagine a line at a supermarket checkout. The first person to get in line is the first person to be served. The process is FIFO:
- As new customers arrive, they join the end of the line (enqueue).
- The customer at the front of the line is served and leaves the line (dequeue).

### **Queue Implementation in C**

Here’s how a queue can be implemented in C using an array:

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the queue

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(Queue* q) {
    return q->rear == MAX - 1;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

// Function to enqueue (add element to the queue)
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) {  // If the queue is empty, set front to 0
        q->front = 0;
    }
    q->arr[++(q->rear)] = value;
    printf("Enqueued %d\n", value);
}

// Function to dequeue (remove element from the queue)
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;  // Indicating queue is empty
    }
    int value = q->arr[q->front++];
    if (q->front > q->rear) {  // Reset the queue if it becomes empty
        q->front = q->rear = -1;
    }
    return value;
}

// Function to peek at the front element
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->arr[q->front];
}

// Main function to demonstrate queue operations
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Front element: %d\n", peek(&q));

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    printf("Front element after dequeuing: %d\n", peek(&q));

    return 0;
}
```

### **Explanation of Code**
- **Queue Structure**: We define a `Queue` structure with an array `arr[]` to store elements, and two integers `front` and `rear` to keep track of the positions.
- **Enqueue**: Adds an element to the rear of the queue.
- **Dequeue**: Removes an element from the front of the queue.
- **Peek**: Returns the front element without removing it.
- **isFull & isEmpty**: Check if the queue is full or empty, respectively.

### **Real-World Example:**
Consider the following scenarios where a queue is used:
1. **Printer Queue**: In a printer, print jobs are queued up. The first document to be sent to the printer is the first one to be printed.
2. **Customer Service**: In a call center, calls are handled in the order they are received. The first call to arrive is the first one answered.
3. **Ticket Counter**: At a bus or train station, customers line up to buy tickets. The first customer in line gets served first.

### **Queue Types**
- **Linear Queue**: The basic queue, as implemented above.
- **Circular Queue**: A more efficient version where the rear and front pointers wrap around to the beginning when the end of the array is reached.
- **Priority Queue**: Elements are dequeued based on priority rather than their arrival order.
- **Double-ended Queue (Deque)**: Allows insertion and deletion from both ends.




---



Here's a step-by-step memory visualization of how a queue operates using an array. We'll go through the enqueue and dequeue operations while keeping track of the `front` and `rear` pointers.

### **Initial Queue Setup**
Let's assume the queue size is 5 (`MAX = 5`). Initially, the queue is empty:

```
Queue: [empty, empty, empty, empty, empty]
front = -1
rear = -1
```

### **Step 1: Enqueue 10**
We add `10` to the queue. Since the queue is empty, both `front` and `rear` point to index `0`.

```
Queue: [10, empty, empty, empty, empty]
front = 0
rear = 0
```

### **Step 2: Enqueue 20**
We add `20` to the queue. The `rear` pointer moves to index `1`.

```
Queue: [10, 20, empty, empty, empty]
front = 0
rear = 1
```

### **Step 3: Enqueue 30**
We add `30` to the queue. The `rear` pointer moves to index `2`.

```
Queue: [10, 20, 30, empty, empty]
front = 0
rear = 2
```

### **Step 4: Dequeue (Remove 10)**
We remove the element at the `front` (which is `10`). The `front` pointer moves to index `1`. The element `10` is removed.

```
Queue: [empty, 20, 30, empty, empty]
front = 1
rear = 2
```

### **Step 5: Enqueue 40**
We add `40` to the queue. The `rear` pointer moves to index `3`.

```
Queue: [empty, 20, 30, 40, empty]
front = 1
rear = 3
```

### **Step 6: Dequeue (Remove 20)**
We remove the element at the `front` (which is `20`). The `front` pointer moves to index `2`. The element `20` is removed.

```
Queue: [empty, empty, 30, 40, empty]
front = 2
rear = 3
```

### **Step 7: Enqueue 50**
We add `50` to the queue. The `rear` pointer moves to index `4`.

```
Queue: [empty, empty, 30, 40, 50]
front = 2
rear = 4
```

### **Step 8: Dequeue (Remove 30)**
We remove the element at the `front` (which is `30`). The `front` pointer moves to index `3`. The element `30` is removed.

```
Queue: [empty, empty, empty, 40, 50]
front = 3
rear = 4
```

### **Step 9: Dequeue (Remove 40)**
We remove the element at the `front` (which is `40`). The `front` pointer moves to index `4`. The element `40` is removed.

```
Queue: [empty, empty, empty, empty, 50]
front = 4
rear = 4
```

### **Step 10: Dequeue (Remove 50)**
We remove the element at the `front` (which is `50`). The `front` and `rear` pointers are reset to `-1` because the queue is now empty.

```
Queue: [empty, empty, empty, empty, empty]
front = -1
rear = -1
```

### **Summary of Queue Operations**
- **Enqueue**: Adds elements to the rear and moves the `rear` pointer forward.
- **Dequeue**: Removes elements from the front and moves the `front` pointer forward.
- **Queue is empty** when both `front` and `rear` are `-1`.

This visualization shows how the queue evolves with each operation, keeping track of the `front` and `rear` pointers, and the elements in the array.