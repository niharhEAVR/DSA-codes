#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function prototypes
Node* createNode(int data);
void insertAtEnd(Node **head, int data);
void insertAtBegin(Node **head, int data);
void insertAtPosition(Node **head, int data, int position);
void insertByValueBefore(Node **head, int target, int data);
void insertByValueAfter(Node **head, int target, int data);
void deleteFromEnd(Node **head);
void deleteFromBegin(Node **head);
void deleteAtPosition(Node **head, int position);
void deleteByValue(Node **head, int target);
void displayList(Node *head);
int search(Node *head, int key);
void freeList(Node **head);
int getListLength(Node *head);

int main() {
    Node *head = NULL;
    int choice, data, position, target;

    while (1) {
        printf("\n---- Singly Circular Linked List Operations ----\n");
        printf("1. Insert at End\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at Position\n");
        printf("4. Insert by Value Before\n");
        printf("5. Insert by Value After\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Beginning\n");
        printf("8. Delete at Position\n");
        printf("9. Delete by Value\n");
        printf("10. Display List\n");
        printf("11. Search for Element\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            	printf("\nInsert data at end of the given list:\n");
            	displayList(head);
            	printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                displayList(head);
                break;
            case 2:
            	printf("\nInsert data at beginning of the given list:\n");
            	displayList(head);
            	printf("Enter data: ");
                scanf("%d", &data);
                insertAtBegin(&head, data);
                displayList(head);
                break;
            case 3:
            	printf("\nInsert data at specific position of the given list:\n");
            	displayList(head);
            	printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                displayList(head);
                break;
            case 4:
            	printf("\nInsert by Value Before in the given list: \n");
				displayList(head);
                printf("Enter target data: ");
                scanf("%d", &target);
                printf("Enter new data: ");
                scanf("%d", &data);
                insertByValueBefore(&head, target, data);
                displayList(head);
                break;
            case 5:
            	printf("\nInsert by Value After in the given list: \n");
            	displayList(head);
                printf("Enter target data: ");
                scanf("%d", &target);
                printf("Enter new data: ");
                scanf("%d", &data);
                insertByValueAfter(&head, target, data);
                displayList(head);
                break;
            case 6:
            	printf("\nDelete the last element of the given list: \n");
            	displayList(head);
                deleteFromEnd(&head);
                displayList(head);
                break;
            case 7:
            	printf("\nDelete the 1st element of the given list: \n");
            	displayList(head);
                deleteFromBegin(&head);
                displayList(head);
                break;
            case 8:
            	printf("\nDelete the element of the given list by it's position': \n");
				displayList(head);
				printf("Enter the position: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                displayList(head);
                break;
            case 9:
            	printf("\nDelete by value from the given list: \n");
                displayList(head);
                printf("Enter target data: ");
                scanf("%d", &target);
                deleteByValue(&head, target);
                displayList(head);
                break;
            case 10:
            	printf("\nDisplay the list: ");
                displayList(head);
                break;
            case 11:
            	printf("\nEnter element to search: ");
                scanf("%d", &target);
                position = search(head, target);
                if (position != -1) {
                    printf("Element found at position: %d\n", position);
                } else {
                    printf("Element not found in the list.\n");
                }
                break;
            case 12:
                freeList(&head);
                printf("\nExiting program.\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode; // Circular link
    return newNode;
}

void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
    printf("Inserted %d at the end.\n", data);
}

void insertAtBegin(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
    printf("Inserted %d at the beginning.\n", data);
}

void insertAtPosition(Node **head, int data, int position) {
    if (position < 1) {
        printf("Invalid position! Position must be greater than or equal to 1.\n");
        return;
    }

    int length = getListLength(*head);
    if (position > length + 1) {
        printf("Invalid position! Position exceeds list length.\n");
        return;
    }

    if (position == 1) {
        insertAtBegin(head, data);
        return;
    }

    Node *newNode = createNode(data);
    Node *temp = *head;
    int i;
    for (i = 1; i < position - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", data, position);
}

void insertByValueBefore(Node **head, int target, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->data == target) {
        insertAtBegin(head, data);
        return;
    }
    Node *newNode = createNode(data);
    Node *temp = *head, *prev = NULL;
    do {
        prev = temp;
        temp = temp->next;
        if (temp->data == target) {
            newNode->next = temp;
            prev->next = newNode;
            printf("Inserted %d before %d.\n", data, target);
            return;
        }
    } while (temp != *head);
    printf("Target value %d not found.\n", target);
}

void insertByValueAfter(Node **head, int target, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *newNode = createNode(data);
    Node *temp = *head;
    do {
        if (temp->data == target) {
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Inserted %d after %d.\n", data, target);
            return;
        }
        temp = temp->next;
    } while (temp != *head);
    printf("Target value %d not found.\n", target);
}

void deleteFromEnd(Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = *head, *prev = NULL;
    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        free(temp);
        *head = NULL;
    } else {
        prev->next = *head;
        free(temp);
    }
    printf("Deleted from the end.\n");
}

void deleteFromBegin(Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = *head;
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
    } else {
        Node *last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = temp->next;
        *head = temp->next;
        free(temp);
    }
    printf("Deleted from the beginning.\n");
}

void deleteAtPosition(Node **head, int position) {
    if (*head == NULL || position < 1) {
        printf("Invalid position or list is empty.\n");
        return;
    }
    int length = getListLength(*head);
    if (position > length) {
        printf("Invalid position! Position exceeds list length.\n");
        return;
    }
    if (position == 1) {
        deleteFromBegin(head);
        return;
    }
    Node *temp = *head, *prev = NULL;
    int i;
    for (i = 1; i < position && temp->next != *head; i++) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    printf("Deleted node at position %d.\n", position);
}

void deleteByValue(Node **head, int target) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = *head, *prev = NULL;
    if ((*head)->data == target) {
        deleteFromBegin(head);
        return;
    }
    do {
        prev = temp;
        temp = temp->next;
        if (temp->data == target) {
            prev->next = temp->next;
            free(temp);
            printf("Deleted node with value %d.\n", target);
            return;
        }
    } while (temp != *head);
    printf("Value %d not found in the list.\n", target);
}

    	
    	
void displayList(Node *head) {
    if (head == NULL) {
        printf(">>List is empty<<\n");
        return;
    }
    Node *temp = head;
    printf(">>List elements: ");
    do {
        printf("<%d> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int search(Node *head, int key) {
    if (head == NULL) {
        return -1;
    }
    Node *temp = head;
    int position = 1;
    do {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    } while (temp != head);
    return -1;
}

void freeList(Node **head) {
    if (*head == NULL) {
        return;
    }
    Node *temp = *head;
    Node *nextNode;
    do {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while (temp != *head);
    *head = NULL;
    printf("\nList has been freed.");
}

int getListLength(Node *head) {
    if (head == NULL) {
        return 0;
    }
    int length = 0;
    Node *temp = head;
    do {
        length++;
        temp = temp->next;
    } while (temp != head);
    return length;
}
