# 🧩 1. What is an Array?

An **array** is a **collection of elements** stored **in contiguous memory locations**, all having the **same data type**.

In simple words:

> Array = group of similar elements placed side-by-side in memory.

Example:

```cpp
int arr[5] = {10, 20, 30, 40, 50};
```

Here:

* The array name `arr` points to the first element’s address.
* Memory layout (contiguous):

| Index | Value | Address (example) |
| ----- | ----- | ----------------- |
| 0     | 10    | 1000              |
| 1     | 20    | 1004              |
| 2     | 30    | 1008              |
| 3     | 40    | 1012              |
| 4     | 50    | 1016              |

*(Each `int` = 4 bytes, so addresses increase by 4.)*

---

# ⚙️ 2. Array Basics (Core Interview Points)

| Concept            | Explanation                    |
| ------------------ | ------------------------------ |
| **Declaration**    | `int arr[5];`                  |
| **Initialization** | `int arr[5] = {1,2,3,4,5};`    |
| **Accessing**      | `arr[2]` → 3rd element         |
| **Size**           | `sizeof(arr) / sizeof(arr[0])` |
| **Indexing**       | 0-based → starts from index 0  |
| **Type**           | Homogeneous (same data type)   |

---

# 🧮 3. Memory & Address Calculation

For an array `arr[0...n-1]`,
base address = `arr[0]`.

Address of `arr[i]`:

```
address(arr[i]) = base_address + (i * size_of_each_element)
```

**Example:**
If base = 1000 and each element = 4 bytes,
`address(arr[3]) = 1000 + (3 × 4) = 1012`

👉 This formula is why **random access** in arrays is **O(1)** (constant time).

---

# ⚡ 4. Array Operations & Their Complexities

| Operation              | Description        | Time Complexity  |
| ---------------------- | ------------------ | ---------------- |
| **Access (Read)**      | `arr[i]`           | O(1)             |
| **Search (Linear)**    | Check each element | O(n)             |
| **Insertion (End)**    | Add element at end | O(1) (amortized) |
| **Insertion (Middle)** | Shift elements     | O(n)             |
| **Deletion (Middle)**  | Shift elements     | O(n)             |
| **Traversal**          | Visit all elements | O(n)             |

✅ Arrays allow **fast random access**,
❌ but **slow insertion/deletion** (since shifting is required).

---

# 🧠 5. Types of Arrays

### 🔹 1D Array

A simple list of elements.

```cpp
int arr[5] = {1,2,3,4,5};
```

### 🔹 2D Array

Array of arrays → like a matrix.

```cpp
int mat[2][3] = { {1,2,3}, {4,5,6} };
```

Visually:

```
1 2 3
4 5 6
```

### 🔹 3D Array

Used for 3D matrices (less common).

```cpp
int cube[2][2][2];
```

---

# 🧩 6. Key Interview Questions About Arrays

Below are **must-know topics** that interviewers frequently ask (especially for beginners and intermediate developers):

---

## 🔸 1. Traversing / Printing

```cpp
for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
```

---

## 🔸 2. Finding Maximum / Minimum

```cpp
int max = arr[0];
for (int i = 1; i < n; i++)
    if (arr[i] > max)
        max = arr[i];
```

🕒 O(n)

---

## 🔸 3. Searching

### Linear Search

```cpp
for (int i = 0; i < n; i++)
    if (arr[i] == key) return i;
```

### Binary Search (sorted array only)

```cpp
int low=0, high=n-1;
while(low<=high){
    int mid=(low+high)/2;
    if(arr[mid]==key) return mid;
    else if(arr[mid]>key) high=mid-1;
    else low=mid+1;
}
```

🕒 O(log n)

---

## 🔸 4. Reverse an Array

```cpp
int start=0, end=n-1;
while(start<end){
    swap(arr[start], arr[end]);
    start++; end--;
}
```

---

## 🔸 5. Rotate an Array (Left / Right)

**Example:** Rotate `[1,2,3,4,5]` left by 2 → `[3,4,5,1,2]`

👉 Techniques:

* Using temporary array
* Reversal algorithm
* Using modulo operations

🕒 O(n), 💾 O(1) (in-place)

---

## 🔸 6. Find Duplicates

* Use nested loops (O(n²))
* Use `unordered_set` for O(n)

---

## 🔸 7. Find Missing Number (1 to n)

Sum method:

```
expected_sum = n*(n+1)/2
actual_sum = sum(arr)
missing = expected_sum - actual_sum
```

---

## 🔸 8. Kadane’s Algorithm (Maximum Subarray Sum)

```cpp
int maxSum = arr[0], currSum = 0;
for (int i=0; i<n; i++) {
    currSum = max(arr[i], currSum + arr[i]);
    maxSum = max(maxSum, currSum);
}
```

🕒 O(n)

---

## 🔸 9. Two Sum Problem

Find two numbers that add up to a target.

### Hash map approach:

```cpp
unordered_map<int,int> m;
for(int i=0;i<n;i++){
    if(m.count(target-arr[i])) return {m[target-arr[i]], i};
    m[arr[i]] = i;
}
```

🕒 O(n)

---

## 🔸 10. Sorting

Common sorts asked:

* **Bubble Sort** – O(n²)
* **Selection Sort** – O(n²)
* **Insertion Sort** – O(n²)
* **Merge Sort** – O(n log n)
* **Quick Sort** – O(n log n) average

---

# ⚙️ 7. Advantages & Disadvantages

| Advantages                         | Disadvantages                    |
| ---------------------------------- | -------------------------------- |
| Easy to use and access via index   | Fixed size                       |
| Fast random access (O(1))          | Insertion/deletion costly        |
| Contiguous memory (cache-friendly) | Requires contiguous memory block |
| Easy to sort and traverse          | Only same-type elements          |

---

# 🧠 8. Common Interview Traps / Edge Cases

1. **Out of bounds index** → segmentation fault.
2. **Array size** must be known at compile time in static arrays.
3. **Dynamic allocation** using `new`:

   ```cpp
   int* arr = new int[n];
   delete[] arr; // free memory
   ```
4. **Passing array to function** actually passes *a pointer*, not a copy.

---

# 🔍 9. Concept of Dynamic Arrays (vector in C++)

When you don’t know the array size at compile time,
use **`std::vector`** (resizable array).

```cpp
vector<int> v = {10, 20, 30};
v.push_back(40);
v.pop_back();
```

✅ Dynamic resizing
✅ Random access
✅ Many built-in functions

---

# 💬 10. Frequently Asked Interview Questions

✅ Find second largest element
✅ Move all zeros to end
✅ Remove duplicates from sorted array
✅ Merge two sorted arrays
✅ Rearrange positive and negative numbers
✅ Find equilibrium index
✅ Majority element (Boyer-Moore)
✅ Find subarray with given sum

---

# 🧾 Summary Table

| Concept            | Key Point                           | Time            |
| ------------------ | ----------------------------------- | --------------- |
| Access             | Constant time                       | O(1)            |
| Insertion (middle) | Shifting required                   | O(n)            |
| Deletion           | Shifting required                   | O(n)            |
| Searching          | Linear / Binary                     | O(n) / O(log n) |
| Memory             | Contiguous                          |                 |
| Space              | Fixed (static), dynamic with vector |                 |
