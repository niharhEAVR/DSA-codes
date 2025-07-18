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
