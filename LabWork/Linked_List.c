#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the beginning.\n", data);
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        printf("Inserted %d at the end.\n", data);
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Inserted %d at the end.\n", data);
}

// Function to insert a node after a specific value
void insertByValue(struct Node** head, int value, int data) {
    if (*head == NULL) {
        printf("The list is empty. Cannot insert %d after %d.\n", data, value);
        return;
    }

    struct Node* temp = *head;

    // Search for the node with the given value
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list. Cannot insert %d.\n", value, data);
        return;
    }

    // Insert the new node after the found node
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d after %d.\n", data, value);
}

// Function to insert a node before a specific value
void insertBeforeValue(struct Node** head, int value, int data) {
    if (*head == NULL) {
        printf("The list is empty. Cannot insert %d before %d.\n", data, value);
        return;
    }

    // If the first node is the target
    if ((*head)->data == value) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // Search for the node with the given value
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list. Cannot insert %d.\n", value, data);
        return;
    }

    // Insert the new node before the found node
    struct Node* newNode = createNode(data);
    prev->next = newNode;
    newNode->next = temp;
    printf("Inserted %d before %d.\n", data, value);
}

// Function to delete a node by value
void deleteByValue(struct Node** head, int value) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the head node itself holds the value
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        printf("Deleted %d from the list.\n", value);
        return;
    }

    // Search for the node to delete
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If the value was not present
    if (temp == NULL) {
        printf("%d not found in the list.\n", value);
        return;
    }

    // Unlink the node and free memory
    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list.\n", value);
}

// Function to search for a value
void searchValue(struct Node* head, int value) {
    struct Node* temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("%d found at position %d.\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("%d not found in the list.\n", value);
}

// Function to display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("\nThe list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("\nList elements: ");
    while (temp != NULL) {
        printf("%d ->> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to reverse the list
void reverseList(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty. Cannot reverse.\n");
        return;
    }

    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev to current
        current = next;       // Move current to next
    }

    *head = prev; // Update head to the last node
    printf("Reversed the list.\n");
}

// Main function with menu
int main() {
    struct Node* head = NULL;
    int choice, data, value;

    while (1) {
        printf("\n--- Linked List Operations ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Value\n");
        printf("4. Insert Before a Value\n");
        printf("5. Delete by Value\n");
        printf("6. Search for Value\n");
        printf("7. Display List\n");
        printf("8. Reverse List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                displayList(head);
                break;
            case 2:
                printf("Enter the value to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                displayList(head);
                break;
            case 3:
                printf("Enter the value after which to insert: ");
                scanf("%d", &value);
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                insertByValue(&head, value, data);
                displayList(head);
                break;
            case 4:
                printf("Enter the value before which to insert: ");
                scanf("%d", &value);
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                insertBeforeValue(&head, value, data);
                displayList(head);
                break;
            case 5:
                printf("Enter the value to delete: ");
                scanf("%d", &data);
                deleteByValue(&head, data);
                displayList(head);
                break;
            case 6:
                printf("Enter the value to search: ");
                scanf("%d", &data);
                searchValue(head, data);
                break;
            case 7:
                displayList(head);
                break;
            case 8:
                reverseList(&head);
                displayList(head);
                break;
            case 9:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}