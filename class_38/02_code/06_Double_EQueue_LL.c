#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void enqueue(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void dequeue(Node **head)
{
    Node *deleteNode = *head;

    *head = (*head)->next;
    (*head)->prev = NULL;

    free(deleteNode);
}

void displayForward(Node *head)
{
    printf("Forward: ");
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void displayBackward(Node *head)
{
    if (head == NULL)
        return;

    while (head->next != NULL)
    {
        head = head->next;
    }
    printf("Backward: ");
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->prev;
    }
    printf("NULL\n");
}

int main()
{
    Node *head = NULL;

    enqueue(&head, 10);
    enqueue(&head, 20);
    enqueue(&head, 30);

    displayForward(head);

    displayBackward(head);

    dequeue(&head);
    displayForward(head);
    displayBackward(head);

    return 0;
}
