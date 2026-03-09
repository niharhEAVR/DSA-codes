## 🧠 What is Insertion Sort?

Insertion Sort is a **simple sorting algorithm** that works the same way we **sort playing cards** in our hands.

➡️ You pick one card at a time (from left to right),
➡️ and **insert it into its correct position** among the already sorted cards in your hand.

---

## 🎴 Real-Life Analogy

Imagine sorting cards (numbers):

```
[5, 3, 4, 1, 2]
```

You start with the first card → it's already sorted by itself.

Then you pick the **next card**, and put it where it belongs in the **already sorted part**.

---

## ⚙️ Step-by-Step Example

Let’s sort:

```
[5, 3, 4, 1, 2]
```

### Step 1: Assume first element is sorted

```
[5] | [3, 4, 1, 2]
```

(Left side = sorted part, right side = unsorted part)

---

### Step 2: Take next element (3)

Insert 3 into correct position in `[5]`

```
Compare 3 < 5 → move 5 ahead
[3, 5] | [4, 1, 2]
```

---

### Step 3: Take next element (4)

Insert 4 into `[3, 5]`

```
Compare 4 < 5 → move 5 ahead
Compare 4 > 3 → stop, insert after 3
[3, 4, 5] | [1, 2]
```

---

### Step 4: Take next element (1)

Insert 1 into `[3, 4, 5]`

```
Compare 1 < 5 → move 5
Compare 1 < 4 → move 4
Compare 1 < 3 → move 3
Insert at beginning
[1, 3, 4, 5] | [2]
```

---

### Step 5: Take next element (2)

Insert 2 into `[1, 3, 4, 5]`

```
Compare 2 < 5 → move 5
Compare 2 < 4 → move 4
Compare 2 < 3 → move 3
Compare 2 > 1 → insert after 1
[1, 2, 3, 4, 5]
```

✅ Done! Sorted array: `[1, 2, 3, 4, 5]`

---

## 🔍 Visual Table of Passes

| Pass | Sorted Part     | Unsorted Part | Result          |
| ---- | --------------- | ------------- | --------------- |
| 1    | [5]             | [3, 4, 1, 2]  | [5, 3, 4, 1, 2] |
| 2    | [3, 5]          | [4, 1, 2]     | [3, 5, 4, 1, 2] |
| 3    | [3, 4, 5]       | [1, 2]        | [3, 4, 5, 1, 2] |
| 4    | [1, 3, 4, 5]    | [2]           | [1, 3, 4, 5, 2] |
| 5    | [1, 2, 3, 4, 5] | []            | [1, 2, 3, 4, 5] |

---

## 💻 Proper C++ DSA Implementation

```cpp
#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr, int n) {
    for (int i = 1; i < n; i++) { // Start from 2nd element
        int key = arr[i];          // The element to be inserted
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key; // Insert key at correct position

        // Print the array after each pass
        cout << "Pass " << i << ": ";
        for (auto x : arr) cout << x << " ";
        cout << endl;
    }
}

int main() {
    vector<int> arr = {5, 3, 4, 1, 2};

    insertionSort(arr, arr.size());

    cout << "\nFinal Sorted Array: ";
    for (auto x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
```

---

### ✅ Output:

```
Pass 1: 3 5 4 1 2 
Pass 2: 3 4 5 1 2 
Pass 3: 1 3 4 5 2 
Pass 4: 1 2 3 4 5 

Final Sorted Array: 1 2 3 4 5
```

---

## 🧮 Time and Space Complexity

| Case        | Explanation                                    | Time      |
| ----------- | ---------------------------------------------- | --------- |
| **Best**    | Already sorted → only 1 comparison per element | **O(n)**  |
| **Average** | Random order → moderate shifts                 | **O(n²)** |
| **Worst**   | Reverse order → maximum shifts                 | **O(n²)** |
| **Space**   | In-place (no extra array)                      | **O(1)**  |
| **Stable**  | ✅ Yes                                          |           |

---

## 🧩 Why It’s Called “Insertion” Sort

Because every time we “pick” an element,
we **insert it** into the correct position inside the sorted portion.

Think of it as “building” your sorted array one element at a time.

---

## ⚖️ Comparison with Other Sorts

| Algorithm          | Key Operation                   | Stability | Time  | Space | Idea              |
| ------------------ | ------------------------------- | --------- | ----- | ----- | ----------------- |
| **Selection Sort** | Find minimum & swap             | ❌ No      | O(n²) | O(1)  | Select smallest   |
| **Bubble Sort**    | Compare & swap adjacent         | ✅ Yes     | O(n²) | O(1)  | Bubble up largest |
| **Insertion Sort** | Insert element in correct place | ✅ Yes     | O(n²) | O(1)  | Build sorted list |

---

## 🧠 When to Use Insertion Sort

✅ When your array is **small** (less than ~50 elements)
✅ When the data is **almost sorted already**
✅ When you need a **simple stable algorithm**

---

## 🌈 Intuitive Visual (Text-based)

```
Start:  [5 | 3 4 1 2]
Take 3 → move 5 → [3 5 | 4 1 2]
Take 4 → insert after 3 → [3 4 5 | 1 2]
Take 1 → move 5,4,3 → [1 3 4 5 | 2]
Take 2 → move 3 → [1 2 3 4 5]
Done ✅
```

---
---
---


## 🧠 Step 1: What’s the problem?

You have an **unsorted list**, and you need to sort it in ascending order.

Example:

```
[13, 46, 24, 52, 20, 9]
```

Goal →

```
[9, 13, 20, 24, 46, 52]
```

---

## 💡 Step 2: What’s the idea behind *insertion sort*?

Imagine you’re **sorting cards in your hand**:

* You start with the first card — already sorted.
* You pick the next card and **insert it** into the correct place among the cards in your hand.
* Keep doing this for every card.

That’s literally **insertion sort**.

---

## 🪜 Step 3: Step-by-step example

Let’s sort this array step-by-step:

```
arr = [13, 46, 24, 52, 20, 9]
```

We divide it conceptually into two parts:

* **Sorted part** (left side)
* **Unsorted part** (right side)

At the start:

```
[13] [46, 24, 52, 20, 9]
↑ Sorted ↑ Unsorted
```

---

### Step 1:

Take the next element (46).
Compare with 13 — 46 > 13, so leave it.

✅ Now sorted part → `[13, 46]`

---

### Step 2:

Next element = 24
Compare backward in the sorted part:

* Is 46 > 24? Yes → move 46 to the right.
* Now compare with 13 → 13 < 24 → stop here.

Insert 24 in that place.

✅ Now: `[13, 24, 46, 52, 20, 9]`

---

### Step 3:

Next = 52
Compare backward:

* 46 < 52 → already sorted.

✅ `[13, 24, 46, 52, 20, 9]`

---

### Step 4:

Next = 20
Compare backward:

* 52 > 20 → shift 52
* 46 > 20 → shift 46
* 24 > 20 → shift 24
* 13 < 20 → stop.

Insert 20 here.

✅ `[13, 20, 24, 46, 52, 9]`

---

### Step 5:

Next = 9
Compare backward:

* 52 > 9 → shift 52
* 46 > 9 → shift 46
* 24 > 9 → shift 24
* 20 > 9 → shift 20
* 13 > 9 → shift 13
  (no more left, insert 9 at beginning)

✅ `[9, 13, 20, 24, 46, 52]`

---

🎯 DONE!
You inserted each element in its correct place — like sorting cards.

---

## ⚙️ Step 4: Build your logic (pseudocode)

You can now think like this:

```
for i = 1 to n-1:
    current = arr[i]
    j = i - 1
    while (j >= 0 and arr[j] > current):
        arr[j + 1] = arr[j]  // shift element right
        j = j - 1
    arr[j + 1] = current  // insert current in correct place
```

---

## 💻 Step 5: Write the code in C++

```cpp
#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int current = arr[i];
        int j = i - 1;

        // Shift larger elements to the right
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert current in the right position
        arr[j + 1] = current;
    }
}

int main() {
    vector<int> arr = {13, 46, 24, 52, 20, 9};

    insertionSort(arr);

    cout << "[ ";
    for (auto x : arr) cout << x << " ";
    cout << "]" << endl;

    return 0;
}
```

---

## 🧩 Output:

```
[ 9 13 20 24 46 52 ]
```

---

## 🧠 Step 6: Time & Space Complexity

| Case       | Explanation               | Time  |
| ---------- | ------------------------- | ----- |
| Best Case  | Already sorted            | O(n)  |
| Worst Case | Reverse order             | O(n²) |
| Average    | Random data               | O(n²) |
| Space      | Uses only a few variables | O(1)  |

---

## 🚀 Step 7: How to practice and think on your own

When you want to write this by yourself:

1. Start with an example array.
2. Pretend you’re sorting cards.
3. Think: “How would I move elements backward until I find the correct spot?”
4. Write that logic in loops.

After you do it 2–3 times, you’ll naturally remember the process.



---
---
---



**How** time and space complexity are *calculated* will help you with *every* algorithm you ever learn — not just insertion sort.

---

## ⚙️ Step 1: What is Time Complexity?

**Time complexity** tells us **how the number of steps** an algorithm takes **grows with the input size (n)**.

> ❗It’s *not about actual seconds*, but about *how the steps scale* when data increases.

Example:

| Input size (n) | Steps taken   |
| -------------- | ------------- |
| 10 elements    | ~100 steps    |
| 100 elements   | ~10,000 steps |

Here, steps grew by ( n^2 ) → **O(n²)** complexity.

---

## ⚙️ Step 2: What happens inside Insertion Sort?

Here’s the algorithm again:

```cpp
for (int i = 1; i < n; i++) {
    int current = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > current) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = current;
}
```

We’ll analyze **how many times the inner loop runs** because that’s where most of the work happens.

---

## 🧠 Step 3: Count the steps per element

Let’s say our array has `n` elements.

| Step      | What we do                       | Possible iterations |
| --------- | -------------------------------- | ------------------- |
| `i = 1`   | Compare with 1 previous element  | ≤ 1                 |
| `i = 2`   | Compare with 2 previous elements | ≤ 2                 |
| `i = 3`   | Compare with 3 previous elements | ≤ 3                 |
| ...       | ...                              | ...                 |
| `i = n-1` | Compare with n−1 elements        | ≤ n−1               |

So total number of comparisons =
`1 + 2 + 3 + ... + (n−1)`

We know that formula:
[
1 + 2 + 3 + ... + (n−1) = \frac{n(n−1)}{2}
]

When we take only the **highest order term** (for Big-O), it becomes:
[
O(n^2)
]

---

## 💡 Step 4: Why O(n²)? — Visual intuition

Let’s imagine you have 6 elements:

```
[13, 46, 24, 52, 20, 9]
```

* 1st element → no work
* 2nd element → 1 comparison
* 3rd element → up to 2 comparisons
* 4th element → up to 3 comparisons
* 5th element → up to 4 comparisons
* 6th element → up to 5 comparisons

Total = 1 + 2 + 3 + 4 + 5 = 15 operations ≈ ( n^2 )

So, **as n grows**, work grows roughly like a *square*.

---

## 🧮 Step 5: Different Cases

| Case             | Meaning                 | Comparisons (approx.)     | Time Complexity |
| ---------------- | ----------------------- | ------------------------- | --------------- |
| **Best Case**    | Array already sorted    | n−1 comparisons, 0 shifts | **O(n)**        |
| **Worst Case**   | Array sorted in reverse | ~n²/2 comparisons         | **O(n²)**       |
| **Average Case** | Random data             | ~n²/4 comparisons         | **O(n²)**       |

---

## 💾 Step 6: Space Complexity

Let’s look at memory use:

```cpp
int current = arr[i];
int j = i - 1;
```

We only use:

* a few integer variables (`i`, `j`, `current`)
* no extra arrays or large structures

So, **space complexity = O(1)**
(“constant extra space” → it doesn’t grow with n)

---

## 🔍 Step 7: Summary Table

| Metric           | Description              | Value |
| ---------------- | ------------------------ | ----- |
| Best Case        | Already sorted           | O(n)  |
| Average Case     | Random order             | O(n²) |
| Worst Case       | Reverse sorted           | O(n²) |
| Space Complexity | Only few variables       | O(1)  |
| Stability        | Stable (preserves order) | ✅ Yes |

---

## 🧠 Step 8: How to find it for **your own programs**

Whenever you write a program, follow this checklist:

| Step | What to look for                         | What it means                        |
| ---- | ---------------------------------------- | ------------------------------------ |
| 1️⃣  | How many nested loops?                   | 1 → O(n), 2 → O(n²), 3 → O(n³), etc. |
| 2️⃣  | Do loops depend on n?                    | If yes → complexity grows with n     |
| 3️⃣  | Are there conditions or recursive calls? | Analyze worst-case branching         |
| 4️⃣  | Do you use extra arrays/lists?           | Adds to space complexity             |
| 5️⃣  | Count total operations roughly           | Convert to O(…) ignoring constants   |

---

### 💬 Example Practice

If you see code like this:

```cpp
for(int i=0; i<n; i++){
   for(int j=0; j<n; j++){
      // O(1) work
   }
}
```

→ Outer loop runs n times
→ Inner loop runs n times
→ Total = n * n = **O(n²)**
