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
