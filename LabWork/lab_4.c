#include <stdio.h>
#include <stdlib.h>
#define MAX 5 // Maximum size of the queue

// Global variables for the queue
int queue[MAX];
int front = -1;
int rear = -1;

// Check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Check if the queue is full
int isFull() {
    return rear == MAX - 1;
}

// Enqueue operation
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full! Cannot enqueue %d.\n", value);
        return;
    }
    if (isEmpty()) {
        front = 0; // Set front to 0 if the queue was empty
    }
    rear++;
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

// Dequeue operation
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Indicate an error
    }
    int value = queue[front];
    if (front == rear) {
        // If only one element was left, reset the queue
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    printf("Dequeued: %d\n", value);
    return value;
}

// Display the queue elements
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i;
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function to test the queue implementation
int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Check if Queue is Empty\n");
        printf("5. Check if Queue is Full\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                if (isEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 5:
                if (isFull()) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}