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
    printf("The value of the heads data: %d\n", head->data);
    modifyOriginalHead(&head);
    if (head == NULL)
        printf("Head is NULL\n");
    else
        printf("Head is not NULL\n");

    return 0;
}