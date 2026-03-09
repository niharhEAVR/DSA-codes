### 🔹 **Definition**

**Linear Search** is the **simplest searching algorithm** used to find an element in a list or array.
It checks **each element one by one** until it either finds the target value or reaches the end of the array.

---

### 🔹 **How It Works**

1. Start from the **first element** of the array.
2. Compare the element with the **target value**.
3. If it matches → ✅ **Element found!**
4. If not → move to the **next element**.
5. Continue until the element is found or the array ends.

---

### 🔹 **Example**

Let’s search for `5` in this array:
`arr = [2, 4, 5, 7, 9]`

| Step | Current Element | Comparison | Result   |
| ---- | --------------- | ---------- | -------- |
| 1    | 2               | 2 == 5 ?   | ❌ No     |
| 2    | 4               | 4 == 5 ?   | ❌ No     |
| 3    | 5               | 5 == 5 ?   | ✅ Found! |

👉 Element `5` is found at **index 2** (0-based indexing).

---

### 🔹 **C++ Example**

```cpp
#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i; // element found, return index
    }
    return -1; // not found
}

int main() {
    int arr[] = {2, 4, 5, 7, 9};
    int n = 5;
    int target = 5;

    int result = linearSearch(arr, n, target);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
```

---

### 🔹 **Time Complexity**

* **Best Case:** `O(1)` → if element is at the beginning.
* **Worst Case:** `O(n)` → if element is at the end or not present.
  ✅ **Overall Time Complexity = O(n)** (linear time)

### 🔹 **Space Complexity**

* **O(1)** — only a few variables used.

---

### 🔹 **In Short (for Notes)**

> **Linear Search:**
> Sequentially checks every element until the target is found or end is reached.
> **Time:** O(n) | **Space:** O(1)
