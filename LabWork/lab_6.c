#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the priority queue

// Structure to represent a priority queue element
typedef struct {
    int value;
    int priority;
} Element;

// Global variables
Element priorityQueue[MAX];
int size = 0; // Current size of the priority queue

// Function to insert an element into the priority queue
void enqueue(int value, int priority) {
    if (size == MAX) {
        printf("Priority Queue is full! Cannot enqueue (%d, %d).\n", value, priority);
        return;
    }
    priorityQueue[size].value = value;
    priorityQueue[size].priority = priority;
    size++;
    printf("Enqueued: (%d, %d)\n", value, priority);
}

// Function to find the highest priority element
int findHighestPriorityIndex() {
    int highestPriorityIndex = 0;
    int i;
    for (i = 1; i < size; i++) {
        // Higher priority is represented by a smaller number
        if (priorityQueue[i].priority < priorityQueue[highestPriorityIndex].priority) {
            highestPriorityIndex = i;
        } else if (priorityQueue[i].priority == priorityQueue[highestPriorityIndex].priority) {
            // If priorities are equal, choose the one that was added first
            if (i < highestPriorityIndex) {
                highestPriorityIndex = i;
            }
        }
    }
    return highestPriorityIndex;
}

// Function to remove the highest priority element
void dequeue() {
    if (size == 0) {
        printf("Priority Queue is empty! Cannot dequeue.\n");
        return;
    }
    int index = findHighestPriorityIndex();
    printf("Dequeued: (%d, %d)\n", priorityQueue[index].value, priorityQueue[index].priority);

    // Shift elements to fill the gap
    int i;
    for (i = index; i < size - 1; i++) {
        priorityQueue[i] = priorityQueue[i + 1];
    }
    size--;
}

// Function to display the elements of the priority queue
void displayQueue() {
    if (size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }
    printf("Priority Queue elements: ");
    int i;
    for (i = 0; i < size; i++) {
        printf("(%d, %d) ", priorityQueue[i].value, priorityQueue[i].priority);
    }
    printf("\n");
}

// Main function to test the priority queue implementation
int main() {
    int choice, value, priority;

    while (1) {
        printf("\nPriority Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value and priority (lower number = higher priority): ");
                scanf("%d %d", &value, &priority);
                enqueue(value, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
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