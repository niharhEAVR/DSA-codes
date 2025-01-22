#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void insertAfterNode(Node *ptr, int data)
{
    if (ptr == NULL)
    {
        printf("This need to be a valid Node!\n");
        return;
    }

    Node *p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->next = ptr->next;
    ptr->next = p;
}

Node *insertAtLast(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    return head;
}

void linkedListTraversal(Node *head)
{
    printf("Elements are: ");
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL");
}

int main()
{
    Node *head;
    Node *second;
    Node *third;
    Node *fourth;

    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));

    head->data = 5;
    head->next = second;
    second->data = 8;
    second->next = third;
    third->data = 9;
    third->next = NULL;

    insertAfterNode(fourth,911);
    linkedListTraversal(head);

    printf("\n");
    head = insertAtLast(head, 13);
    head = insertAtLast(head, 43);
    linkedListTraversal(head);

    printf("\n");
    insertAfterNode(second,69);
    linkedListTraversal(head);

    return 0;
}