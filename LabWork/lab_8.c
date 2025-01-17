#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in a doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void insertBeforeValue(struct Node** head, int value, int data);
void insertAfterValue(struct Node** head, int value, int data);
void deleteFromBeginning(struct Node** head);
void deleteFromEnd(struct Node** head);
void displayForward(struct Node* head);
void displayBackward(struct Node* head);
void searchNode(struct Node* head, int value);

int main() {
    struct Node* head = NULL;
    int choice, value, data;

    do {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert Before a Value\n");
        printf("4. Insert After a Value\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Display Forward\n");
        printf("8. Display Backward\n");
        printf("9. Search Node\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                displayForward(head);
                displayBackward(head);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                displayForward(head);
                displayBackward(head);
                break;
            case 3:
                printf("Enter value to insert before: ");
                scanf("%d", &value);
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insertBeforeValue(&head, value, data);
                displayForward(head);
                displayBackward(head);
                break;
            case 4:
                printf("Enter value to insert after: ");
                scanf("%d", &value);
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insertAfterValue(&head, value, data);
                displayForward(head);
                displayBackward(head);
                break;
            case 5:
                deleteFromBeginning(&head);
                displayForward(head);
                displayBackward(head);
                break;
            case 6:
                deleteFromEnd(&head);
                displayForward(head);
                displayBackward(head);
                break;
            case 7:
                displayForward(head);
                break;
            case 8:
                displayBackward(head);
                break;
            case 9:
            	displayForward(head);
                displayBackward(head);
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchNode(head, value);
                break;
            case 10:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 10);

    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (!newNode) return;
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    printf("Node inserted at the beginning.\n");
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (!newNode) return;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Node inserted at the end.\n");
}

// Function to insert a node before a specific value
void insertBeforeValue(struct Node** head, int value, int data) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = *head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        *head = newNode;
    }
    temp->prev = newNode;
    printf("Node inserted before value %d.\n", value);
}

// Function to insert a node after a specific value
void insertAfterValue(struct Node** head, int value, int data) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = *head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->prev = temp;
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    printf("Node inserted after value %d.\n", value);
}

// Function to delete a node from the beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
    printf("Node deleted from the beginning.\n");
}

// Function to delete a node from the end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
    }
    free(temp);
    printf("Node deleted from the end.\n");
}

// Function to display the list in forward direction
void displayForward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("\nList in forward direction: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to display the list in backward direction
void displayBackward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("\nList in backward direction: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Function to search for a node in the list
void searchNode(struct Node* head, int value) {
    int position = 1;
    while (head != NULL) {
        if (head->data == value) {
            printf("Value %d found at position %d.\n", value, position);
            return;
        }
        head = head->next;
        position++;
    }
    printf("Value %d not found in the list.\n", value);
}