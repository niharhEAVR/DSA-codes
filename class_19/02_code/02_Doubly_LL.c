#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;  // If the list is empty, set head to the new node
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {  // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode;         // Link the last node to the new node
    newNode->prev = temp;         // Link the new node back to the last node
}

// Function to display the list forward
void displayForward(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to display the list backward
void displayBackward(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    while (temp->next != NULL) {  // Traverse to the last node
        temp = temp->next;
    }
    while (temp != NULL) {        // Traverse backward
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Insert nodes
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    // Display the list forward
    printf("Forward: ");
    displayForward(head);

    // Display the list backward
    printf("Backward: ");
    displayBackward(head);

    return 0;
}
