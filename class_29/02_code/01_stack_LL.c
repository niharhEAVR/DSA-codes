#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top; // Link the new node to the previous top
    *top = newNode;       // Update the top pointer
    printf("Pushed %d onto the stack.\n", data);
}

int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty! Cannot pop.\n");
        return -1;
    }
    struct Node* temp = *top;
    int poppedData = temp->data;
    *top = (*top)->next; // Update the top pointer
    free(temp);          // Free the memory of the popped node
    printf("Popped %d from the stack.\n", poppedData);
    return poppedData;
}

int peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty! Nothing to peek.\n");
        return -1;
    }
    return top->data;
}

int isEmpty(struct Node* top) {
    return top == NULL;
}

int main() {
    struct Node* stack = NULL; 

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    printf("Top element is: %d\n", peek(stack));

    pop(&stack);
    pop(&stack);
    
    printf("Top element is: %d\n", peek(stack));

    printf("Stack is empty: %s\n", isEmpty(stack) ? "Yes" : "No");

    return 0;
}
