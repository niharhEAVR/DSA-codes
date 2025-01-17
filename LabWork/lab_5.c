#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the queue

// Circular Queue structure
typedef struct {
    int data[MAX];
    int front;
    int rear;
} CircularQueue;

// Initialize the queue
void initializeQueue(CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(CircularQueue* q) {
    return q->front == -1;
}

// Check if the queue is full
int isFull(CircularQueue* q) {
    return (q->rear + 1) % MAX == q->front;
}

// Enqueue operation
void enqueue(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d.\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0; // Set front to 0 if the queue is empty
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Dequeue operation
int dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Indicate an error
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        // If the last element is dequeued, reset the queue
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    printf("Dequeued: %d\n", value);
    return value;
}

// Display the queue elements
void displayQueue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->data[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function to test the circular queue implementation
int main() {
    CircularQueue q;
    initializeQueue(&q);

    int choice, value;

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}