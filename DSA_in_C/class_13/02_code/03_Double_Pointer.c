#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void modifyLocalHead(struct Node *head)
{
    head->data = 0;
    head = NULL; // This modifies only the local copy of head
}

void modifyOriginalHead(struct Node **head)
{
    *head = NULL; // This modifies the oiginal head
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL;
    modifyLocalHead(head);
    printf("The address it stores: %d\n", head);
    printf("The address it stores: %d\n", (struct Node *)malloc(sizeof(struct Node)));

    // so the context is head is storing the address of the node, thats why we can only change the working of the node structure not the actual head.

    printf("The address it stores: %d\n", &head);
    modifyOriginalHead(&head);
    if (head == NULL)
        printf("Head is NULL\n");
    else
        printf("Head is not NULL\n");

    return 0;
}