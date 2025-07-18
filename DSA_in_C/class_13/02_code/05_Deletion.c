#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to print the linked list
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to delete the first node
void deleteFromBeginning(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = *head;
    *head = temp->next;
    free(temp);
}

// Function to delete the last node
void deleteFromEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL; 
}

// Function to delete a node at a specific position
void deleteFromPosition(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if (position == 0)
    {
        deleteFromBeginning(head);
        return;
    }
    struct Node *temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        printf("Position out of bounds.\n");
        return;
    }
    struct Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

// Function to delete a node by its value
void deleteByValue(struct Node **head, int value)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->data == value)
    {
        deleteFromBeginning(head);
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL && temp->next->data != value)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("Value not found.\n");
        return;
    }
    struct Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

// Function to add a node at the end
void append(struct Node **head, int newData)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head;
    newNode->data = newData;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}

int main()
{
    struct Node *head = NULL;

    // Create a linked list
    append(&head, 15);
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 93);

    printf("Original list: ");
    printList(head);

    printf("Deleting from the beginning...\n");
    deleteFromBeginning(&head);
    printList(head);

    // printf("Deleting from the end...\n");
    // deleteFromEnd(&head);
    // printList(head);

    printf("Deleting from position 2...\n");
    deleteFromPosition(&head, 2);
    printList(head);

    printf("Deleting by value 93...\n");
    deleteByValue(&head, 93);
    printList(head);

    return 0;
}
