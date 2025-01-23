#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode; // If the list is empty, set head to the new node
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    { // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode; // Link the last node to the new node
    newNode->prev = temp; // Link the new node back to the last node
}

void insertAtFirst(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);

    struct Node *temp = *head;
    temp->prev = newNode;
    newNode->next = temp;
    *head = newNode;
}

void deleteAtFirst(struct Node** head){
    struct Node* deleteNode = *head;

    *head = (*head)->next;
    (*head)->prev = NULL;

    free(deleteNode);
}

// void deleteAtEnd(struct Node** head){
//     struct Node *temp = *head;
//     while (temp->next!=NULL)
//     {
//         temp = temp->next;
//     }

//     struct Node* deleteNode = temp;

//     temp = temp->prev;
//     temp->next = NULL;

//     while (temp!=NULL)
//     {
//         temp = temp->prev;
//     }
//     *head = temp;
//     free(deleteNode);
    
// }

// Function to display the list forward
void displayForward(struct Node *head)
{
    printf("Forward: ");
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to display the list backward
void displayBackward(struct Node *head)
{
    if (head == NULL)
        return;

    while (head->next != NULL)
    { // Traverse to the last node
        head = head->next;
    }
    printf("Backward: ");
    while (head != NULL)
    { // Traverse backward
        printf("%d -> ", head->data);
        head = head->prev;
    }
    printf("NULL\n");
}

// Main function
int main()
{
    struct Node *head = NULL;

    // Insert nodes
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    insertAtFirst(&head,9);


    // Display the list forward
    displayForward(head);

    // Display the list backward
    displayBackward(head);

    deleteAtFirst(&head);
    displayForward(head);
    displayBackward(head);

    deleteAtEnd(&head);
    displayForward(head);
    return 0;
}
