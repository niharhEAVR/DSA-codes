Let’s break down the **insertion process** in your linked list program step by step, with a detailed explanation and visualization for each insertion function.

---

### Initial Linked List Setup

Before any insertion, the linked list is created with three nodes:

```c
head->data = 5;
head->next = second;

second->data = 11;
second->next = third;

third->data = 51;
third->next = NULL;
```

### Initial State of the Linked List
```
[5 | next] -> [11 | next] -> [51 | NULL]
head
```

---

## 1. **Inserting at a Specific Index**: `insertAtIndex`

#### Function:
```c
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for the new node
    struct Node *p = head; // Temporary pointer to traverse the list
    int i = 0;

    while (i != index - 1) // Traverse to the node just before the target index
    {
        p = p->next;
        i++;
    }

    ptr->data = data;       // Assign data to the new node
    ptr->next = p->next;    // Link the new node to the next node
    p->next = ptr;          // Link the previous node to the new node

    return head;
}
```

#### Insertion Process:
- **Input**: Insert `56` at index `1` in the linked list.
- **Initial Linked List**:
  ```
  [5 | next] -> [11 | next] -> [51 | NULL]
  head
  ```

1. **Allocate Memory**:
   - A new node is created:
     ```
     [56 | next]
     ```

2. **Traverse to Index - 1**:
   - Start from `head` and move to the node just before the target index (`index - 1 = 0`).
   - `p` points to the first node (`head`).

3. **Link the New Node**:
   - Set the `next` of the new node (`ptr`) to the `next` of `p`:
     ```
     ptr->next = p->next;
     ```
   - The new node now points to the second node (`[11 | next]`).

4. **Update Previous Node**:
   - Update the `next` of `p` to point to the new node:
     ```
     p->next = ptr;
     ```

#### Final State of the Linked List After Insertion:
```
[5 | next] -> [56 | next] -> [11 | next] -> [51 | NULL]
head
```

---

## 2. **Inserting at the Beginning**: `insertFirstElement`

#### Function:
```c
struct Node *insertFirstElement(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for the new node
    ptr->next = head;       // Link the new node to the current head
    ptr->data = data;       // Assign data to the new node
    return ptr;             // Return the new node as the new head
}
```

#### Insertion Process:
- **Input**: Insert `44` at the beginning of the linked list.
- **Initial Linked List**:
  ```
  [5 | next] -> [56 | next] -> [11 | next] -> [51 | NULL]
  head
  ```

1. **Allocate Memory**:
   - A new node is created:
     ```
     [44 | next]
     ```

2. **Link the New Node to the Head**:
   - Set the `next` of the new node (`ptr`) to point to the current head:
     ```
     ptr->next = head;
     ```

3. **Update the Head**:
   - The new node becomes the new head of the linked list:
     ```
     return ptr;
     ```

#### Final State of the Linked List After Insertion:
```
[44 | next] -> [5 | next] -> [56 | next] -> [11 | next] -> [51 | NULL]
head
```

---

### Final Output After All Operations

1. **Initial Traversal**:
   ```
   Element: 5
   Element: 11
   Element: 51
   ```

2. **After Inserting `56` at Index `1`**:
   ```
   Element: 5
   Element: 56
   Element: 11
   Element: 51
   ```

3. **After Inserting `44` at the Beginning**:
   ```
   Element: 44
   Element: 5
   Element: 56
   Element: 11
   Element: 51
   ```

---

### Visualizing the Final Linked List
```
[44 | next] -> [5 | next] -> [56 | next] -> [11 | next] -> [51 | NULL]
head
```

---

### Summary of How Insertion Works
1. **At Index**:
   - Traverse to the node before the target index.
   - Insert the new node by updating pointers.

2. **At Beginning**:
   - Directly link the new node to the current head.
   - Update the head to the new node.


---
---
---



Here’s an upgraded version of your code with two new insertion functions:

1. **Insert at the End**: Adds a new node at the end of the linked list.
2. **Insert After a Node**: Adds a new node after a specific node in the linked list.

---

### Upgraded Code

```c
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct Node *insertFirstElement(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// Function to insert at the end of the linked list
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL) // If the list is empty, the new node becomes the head
    {
        return ptr;
    }

    while (p->next != NULL) // Traverse to the last node
    {
        p = p->next;
    }

    p->next = ptr; // Link the last node to the new node
    return head;
}

// Function to insert after a specific node
void insertAfterNode(struct Node *prevNode, int data)
{
    if (prevNode == NULL)
    {
        printf("The given previous node cannot be NULL\n");
        return;
    }

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 5;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 51;
    third->next = NULL;

    // Traverse the original linked list
    linkedListTraversal(head);
    printf("\n");

    // Insert at index
    head = insertAtIndex(head, 56, 1);
    linkedListTraversal(head);
    printf("\n");

    // Insert at the beginning
    head = insertFirstElement(head, 44);
    linkedListTraversal(head);
    printf("\n");

    // Insert at the end
    head = insertAtEnd(head, 99);
    linkedListTraversal(head);
    printf("\n");

    // Insert after a specific node
    insertAfterNode(second, 77); // Insert 77 after the second node
    linkedListTraversal(head);

    return 0;
}
```

---

### Explanation of New Functions

#### **1. Insert at the End**
```c
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL) // If the list is empty, the new node becomes the head
    {
        return ptr;
    }

    while (p->next != NULL) // Traverse to the last node
    {
        p = p->next;
    }

    p->next = ptr; // Link the last node to the new node
    return head;
}
```
- **Steps**:
  1. Create a new node with the given `data`.
  2. Traverse to the last node using `p`.
  3. Link the last node's `next` to the new node.
- **Special Case**: If the list is empty (`head == NULL`), the new node becomes the head.

---

#### **2. Insert After a Node**
```c
void insertAfterNode(struct Node *prevNode, int data)
{
    if (prevNode == NULL)
    {
        printf("The given previous node cannot be NULL\n");
        return;
    }

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
}
```
- **Steps**:
  1. Create a new node with the given `data`.
  2. Set the new node's `next` to the `next` of the `prevNode`.
  3. Update the `next` of `prevNode` to point to the new node.
- **Special Case**: If `prevNode` is `NULL`, insertion is not possible.

---

### Final Output

1. **Original Linked List**:
   ```
   Element: 5
   Element: 11
   Element: 51
   ```

2. **After Inserting `56` at Index `1`**:
   ```
   Element: 5
   Element: 56
   Element: 11
   Element: 51
   ```

3. **After Inserting `44` at the Beginning**:
   ```
   Element: 44
   Element: 5
   Element: 56
   Element: 11
   Element: 51
   ```

4. **After Inserting `99` at the End**:
   ```
   Element: 44
   Element: 5
   Element: 56
   Element: 11
   Element: 51
   Element: 99
   ```

5. **After Inserting `77` After the Second Node**:
   ```
   Element: 44
   Element: 5
   Element: 56
   Element: 77
   Element: 11
   Element: 51
   Element: 99
   ```
