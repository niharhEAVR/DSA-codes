#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the queue

typedef struct
{
    int arr[MAX];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(Queue *q)
{
    return q->rear == MAX - 1;
}

// Function to check if the queue is empty
int isEmpty(Queue *q)
{

    return q->front == -1 || q->front > q->rear;
}

// Function to enqueue (add element to the queue)
void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1)
    { // If the queue is empty, set front to 0
        q->front = 0;
    }
    q->arr[++(q->rear)] = value;
    printf("Enqueued %d\n", value);
}

// Function to dequeue (remove element from the queue)
int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return -1; // Indicating queue is empty
    }
    int value = q->arr[q->front++];
    if (q->front > q->rear)
    { // Reset the queue if it becomes empty
        q->front = q->rear = -1;
    }
    return value;
}

// Function to peek at the front element
void displayQ(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d", q->arr[i]);
        if (i < 4)
        {
            printf(" <- ");
        }
    }
    printf("\n");
}

// Main function to demonstrate queue operations
int main()
{
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    displayQ(&q);

    enqueue(&q, 60);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    displayQ(&q);
    return 0;
}
