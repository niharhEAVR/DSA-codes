#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Node **head, int value)
{
    Node *newNode = createNode(value);
    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
        return;
    }

    Node *temp = *head;
    while (temp->next != *head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = *head;
}

int dequeue(Node **head)
{
    if(*head == NULL){
        printf("Sorry cant possible!\n");
        return 0;
    }
    struct Node *firstNode = *head;
    int value = firstNode->data;
    struct Node *temp = *head;
    while(temp->next != *head){
        temp = temp->next;
    }
    temp->next = temp->next->next;
    *head = temp->next;
    free(firstNode); 
    return value;
}

void display(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    Node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head); // Stop when we reach the starting node
    printf("(back to head): %d\n", temp->data);
}

int main()
{
    Node *head = NULL;
    enqueue(&head, 10);
    enqueue(&head, 20);
    enqueue(&head, 30);
    enqueue(&head, 40);
    display(head);
    printf("The %d dequeued from the Queue\n", dequeue(&head));
    display(head);
    return 0;
}