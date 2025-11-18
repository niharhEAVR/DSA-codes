## 🔹 Step 1: Time and Space Complexity

### **Better Approach**

```cpp
for (int i = 1; i < matrix.size(); i++)
{
    for (int j = 0; j < i; j++)
    {
        std::swap(matrix[i][j], matrix[j][i]);
    }
}

for (int i = 0; i < matrix.size(); i++)
{
    std::reverse(matrix[i].begin(), matrix[i].end());
}
```

#### ✅ Time Complexity (TC)

* **Transpose step:** roughly `n*(n-1)/2` swaps ⇒ **O(n²)**
* **Reverse step:** reversing each row of length `n` ⇒ `n * O(n)` ⇒ **O(n²)**
* **Total TC = O(n²) + O(n²) = O(2n²) = O(n²)**

#### ✅ Space Complexity (SC)

* Uses only constant space for temporary variables.
* **SC = O(1)**

---

### **Optimal Approach**

```cpp
for (int i = 0; i < n; i++)
{
    for (int j = i + 1; j < n; j++)
    {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = temp;
    }
}
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n / 2; j++)
    {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[i][n - 1 - j];
        matrix[i][n - 1 - j] = temp;
    }
}
```

#### ✅ Time Complexity

* **Transpose step:** same → **O(n²)**
* **Manual reversal step:** each row is reversed using `n/2` swaps ⇒ `n * (n/2)` ⇒ **O(n²)**
* **Total TC = O(n²) + O(n²) = O(2n²) = O(n²)**

#### ✅ Space Complexity

* Still only uses a few `temp` variables.
* **SC = O(1)**

---

✅ **Final:**

| Approach | Time Complexity | Space Complexity |
| -------- | --------------- | ---------------- |
| Better   | O(n²)           | O(1)             |
| Optimal  | O(n²)           | O(1)             |

So both have **same TC and SC**, but the difference lies in *practical performance and precision.*

---

## 🔹 Step 2: Dry Run (Optimal Approach)

Let’s take a **3×3 matrix**:

```
matrix =
1 2 3
4 5 6
7 8 9
```

### Step 1 → Transpose

Swap all elements across the main diagonal (`matrix[i][j]` ↔ `matrix[j][i]` for `j > i`).

| i | j | swap(matrix[i][j], matrix[j][i]) | Matrix after swap       |
| - | - | -------------------------------- | ----------------------- |
| 0 | 1 | swap(2,4)                        | 1 4 3<br>2 5 6<br>7 8 9 |
| 0 | 2 | swap(3,7)                        | 1 4 7<br>2 5 6<br>3 8 9 |
| 1 | 2 | swap(6,8)                        | 1 4 7<br>2 5 8<br>3 6 9 |

✅ **After Transpose:**

```
1 4 7
2 5 8
3 6 9
```

---

### Step 2 → Reverse each row manually

| Row | Before | After Reverse |
| --- | ------ | ------------- |
| 0   | 1 4 7  | 7 4 1         |
| 1   | 2 5 8  | 8 5 2         |
| 2   | 3 6 9  | 9 6 3         |

✅ **Final Rotated Matrix (90° clockwise):**

```
7 4 1
8 5 2
9 6 3
```

---

## 🔹 Step 3: Why “Optimal” is Stronger than “Better”

Both have same theoretical complexity, but:

| Aspect                  | Better                                                                                          | Optimal                                                                                                  |
| ----------------------- | ----------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------- |
| **Transpose loop**      | Loops `i=1` to `n` and `j< i` (slightly less intuitive).                                        | Loops `i=0` to `n` and `j=i+1` (cleaner logic, avoids redundant swaps).                                  |
| **Row reversal**        | Uses STL `reverse()` (slightly higher function call overhead).                                  | Performs reversal manually using in-place swaps — faster in tight memory environments and shows control. |
| **Readability**         | Slightly shorter but less transparent logic.                                                    | More explicit — shows full control over both steps.                                                      |
| **Performance (micro)** | `reverse()` and nested swaps both do same O(n²), but STL may have minor function-call overhead. | Manual reversal avoids that.                                                                             |

So the **Optimal** version is *not more asymptotically efficient*, but:

* It’s **cleaner**, **more readable**, **no hidden overhead**, and **avoids redundant loops**.
* It’s the **standard in interviews and real-world C++ solutions**.

---

✅ **In summary:**

* Both have **O(n²)** time and **O(1)** space.
* The **Optimal** approach is preferred because it is cleaner, eliminates unnecessary conditions, and uses direct indices for precise control — leading to *slightly faster execution and better code quality.*