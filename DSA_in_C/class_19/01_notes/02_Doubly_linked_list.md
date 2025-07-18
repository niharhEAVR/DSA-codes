### **Doubly Linked List**

A **doubly linked list** is a type of linked list where each node contains three parts:

1. **Data**: The value stored in the node.
2. **Next Pointer**: A pointer to the next node in the list.
3. **Previous Pointer**: A pointer to the previous node in the list.

This allows traversal in **both directions**: forward and backward.

---

### **Real-World Analogy**

#### **Analogy: A Train with Compartments**

Imagine a train with compartments connected in both directions:

- Each compartment is a **node**.
- Each compartment has:
  - A door at the **front** to connect to the next compartment (next pointer).
  - A door at the **back** to connect to the previous compartment (previous pointer).
- The first compartment has no door at the back (like `prev = NULL`).
- The last compartment has no door at the front (like `next = NULL`).

---

### **Structure of a Doubly Linked List**

```plaintext
NULL <- [Node1] <-> [Node2] <-> [Node3] -> NULL
```

- `Node1`:
  - `prev = NULL` (no previous node).
  - `next = Node2` (points to the next node).
- `Node2`:
  - `prev = Node1` (points to the previous node).
  - `next = Node3` (points to the next node).
- `Node3`:
  - `prev = Node2` (points to the previous node).
  - `next = NULL` (no next node).

---

### **Advantages of Doubly Linked List**

1. **Bidirectional Traversal:**
   - You can move both forward and backward through the list.
   - Example: In the train analogy, you can walk forward or backward between compartments.

2. **Easier Deletion:**
   - Unlike a singly linked list, you don’t need to traverse the list to find the previous node during deletion.
   - The `prev` pointer directly gives access to the previous node.

3. **Flexibility:**
   - Suitable for use cases like undo/redo operations or implementing a browser’s back/forward navigation.

---

### **Operations in Doubly Linked List**

#### **1. Insertion**

- **At the Beginning:**
  - Create a new node.
  - Set its `next` pointer to the current head.
  - Update the current head's `prev` pointer to the new node.
  - Update the head pointer to the new node.

- **At the End:**
  - Create a new node.
  - Traverse to the last node.
  - Set the last node's `next` pointer to the new node.
  - Set the new node's `prev` pointer to the last node.

---

#### **2. Deletion**

- **From the Beginning:**
  - Update the head pointer to the second node.
  - Set the second node's `prev` pointer to `NULL`.
  - Free the memory of the first node.

- **From the End:**
  - Traverse to the second-last node.
  - Set its `next` pointer to `NULL`.
  - Free the memory of the last node.

---

### **Code Example: Doubly Linked List in C**

```c
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;  // If the list is empty, set head to the new node
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {  // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode;         // Link the last node to the new node
    newNode->prev = temp;         // Link the new node back to the last node
}

// Function to display the list forward
void displayForward(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to display the list backward
void displayBackward(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    while (temp->next != NULL) {  // Traverse to the last node
        temp = temp->next;
    }
    while (temp != NULL) {        // Traverse backward
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Insert nodes
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    // Display the list forward
    printf("Forward: ");
    displayForward(head);

    // Display the list backward
    printf("Backward: ");
    displayBackward(head);

    return 0;
}
```

---

### **Output:**

```
Forward: 10 -> 20 -> 30 -> NULL
Backward: 30 -> 20 -> 10 -> NULL
```

---

### **Real-World Applications of Doubly Linked List**

1. **Browser Navigation:**
   - When you press "Back" or "Forward," the browser navigates through pages stored in a doubly linked list.

2. **Undo/Redo Operations:**
   - Applications like text editors use doubly linked lists to store changes, allowing you to move forward (redo) or backward (undo).

3. **Music Playlists:**
   - You can move to the previous or next song in a playlist.
