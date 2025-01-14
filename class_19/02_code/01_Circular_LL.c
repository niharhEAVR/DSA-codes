#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;  // Point to itself to make it circular
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head) {  // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;  // Make it circular
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);  // Stop when we reach the starting node
    printf("(back to head)\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Insert nodes
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    // Display the list
    display(head);

    return 0;
}
