#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the queue
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Define a queue structure
typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(Queue *q)
{
    return q->front == NULL;
}

// Function to enqueue (add an element to the queue)
void enqueue(Queue *q, int value)
{
    // Create a new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL)
    {
        // If the queue is empty, both front and rear point to the new node
        q->front = q->rear = newNode;
    }
    else
    {
        // Add the new node at the end and update the rear pointer
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued %d\n", value);
}

// Function to dequeue (remove an element from the queue)
int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return -1; // Indicating queue is empty
    }
    // Remove the front node
    Node *temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
    {
        // If the queue becomes empty, reset the rear pointer
        q->rear = NULL;
    }

    free(temp); // Free the memory of the removed node
    return value;
}

// Function to peek at the front element
void displayQ(Queue *q)
{

    Node *temp = q->front;

    printf("Elements of the Queue: ");
    while (temp != NULL)
    {
        printf("%d <- ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate queue operations
int main()
{
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    displayQ(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    displayQ(&q);

    enqueue(&q, 40);
    displayQ(&q); 

    return 0;
}
