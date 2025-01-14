Let's break down how the **linked list** is working in your code and how pointers are used to link the nodes together.

---

### Key Concepts in Your Code

1. **Node Structure**:
   ```c
   struct Node {
       int data;           // Stores the data (integer)
       struct Node *next;  // Pointer to the next node in the list
   };
   ```
   - Each node has:
     - `data`: Holds the value of the node.
     - `next`: Points to the next node in the list. If it's `NULL`, it indicates the end of the list.

2. **Memory Allocation**:
   ```c
   head = (struct Node *)malloc(sizeof(struct Node));
   second = (struct Node *)malloc(sizeof(struct Node));
   third = (struct Node *)malloc(sizeof(struct Node));
   ```
   - Each node (`head`, `second`, `third`) is dynamically allocated memory on the heap using `malloc`.

3. **Linking Nodes**:
   ```c
   head->data = 5;
   head->next = second;
   ```
   - The first node (`head`) is assigned the value `5`.
   - The `next` pointer of `head` is set to point to `second`.

   ```c
   second->data = 11;
   second->next = third;
   ```
   - The second node is assigned the value `11`.
   - The `next` pointer of `second` is set to point to `third`.

   ```c
   third->data = 51;
   third->next = NULL;
   ```
   - The third node is assigned the value `51`.
   - The `next` pointer of `third` is set to `NULL`, indicating the end of the list.

---

### How the Linked List Works
The linked list structure after the above steps looks like this:

```
head -> [5 | next] -> [11 | next] -> [51 | NULL]
```

- `head` is a pointer to the first node.
- The `next` pointer in each node links it to the subsequent node.
- The last node's `next` pointer is `NULL`, indicating the end of the list.

---

### How Pointers Work in the Traversal

#### Traversal Function:
```c
void linkedListTraversal(struct Node *ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next; // Move to the next node
    }
}
```

1. **Input**:
   - The function receives a pointer (`ptr`) to the first node (`head`).

2. **Traversal Logic**:
   - The `while` loop continues as long as `ptr` is not `NULL`.
   - In each iteration:
     - `ptr->data` prints the data of the current node.
     - `ptr = ptr->next` moves the pointer to the next node in the list.

3. **Pointer Movement**:
   - Initially, `ptr` points to `head`.
   - After the first iteration:
     - `ptr` is updated to `head->next`, which is `second`.
   - After the second iteration:
     - `ptr` is updated to `second->next`, which is `third`.
   - After the third iteration:
     - `ptr` is updated to `third->next`, which is `NULL`.
   - When `ptr` becomes `NULL`, the loop ends.

---

### Step-by-Step Execution

1. **Initial State**:
   - `ptr = head` (points to the first node).

2. **First Iteration**:
   - Print: `Element: 5`
   - Move: `ptr = head->next` (points to `second`).

3. **Second Iteration**:
   - Print: `Element: 11`
   - Move: `ptr = second->next` (points to `third`).

4. **Third Iteration**:
   - Print: `Element: 51`
   - Move: `ptr = third->next` (points to `NULL`).

5. **End**:
   - The loop exits because `ptr == NULL`.

---

### Output of the Program
```
Element: 5
Element: 11
Element: 51
```

---

### Summary of Pointer Usage

1. **Node Linking**:
   - The `next` pointer in each node connects it to the next node.

2. **Traversal**:
   - The `ptr` pointer iterates through the list by following the `next` pointers.

3. **End of List**:
   - The `next` pointer of the last node is `NULL`, marking the end of the list.

This is how pointers enable the creation and traversal of a linked list. Let me know if you'd like further clarification!