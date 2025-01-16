#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Define the structure for the queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Function to add an element to the queue (enqueue)
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = createNode(value);
    if (q->rear == NULL) {  // If the queue is empty
        q->front = q->rear = newNode;
        printf("Enqueued: %d\n", value);
        return;
    }
    q->rear->next = newNode;  // Link the new node to the rear
    q->rear = newNode;        // Update the rear pointer
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue (dequeue)
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    struct Node* temp = q->front;  // Store the front node
    int value = temp->data;       // Retrieve the data
    q->front = q->front->next;    // Update the front pointer
    if (q->front == NULL) {       // If the queue is now empty
        q->rear = NULL;
    }
    free(temp);  // Free the memory of the dequeued node
    printf("Dequeued: %d\n", value);
    return value;
}

// Function to display the queue
void displayQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate the queue operations
int main() {
    struct Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    displayQueue(q);
    dequeue(q);
    displayQueue(q);
    enqueue(q, 40);
    displayQueue(q);
    return 0;
}
