// WAP in c that how do you find the middle element of a linked list in one traversal.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void findMiddle(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next; // Move one step
        printf("\nslow element: %d\n", slow->data);
        fast = fast->next->next; // Move two steps
        printf("\nfast element: %d\n", fast->data);
    }

    if (slow != NULL)
    {
        printf("Middle element: %d\n", slow->data);
    }
}

void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;

    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 50);

    printf("Linked List:\n");
    printList(head);

    findMiddle(head);

    return 0;
}
