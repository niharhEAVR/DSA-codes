Exactly. ✅ Your understanding is correct.

For **"Find the largest element in an array"**, there are two common approaches:

### 1. Brute force — Sort

```cpp
sort(arr.begin(), arr.end());

cout << arr[n - 1];
```

Example:

```text
[5, 2, 9, 1, 7]
        ↓ sort
[1, 2, 5, 7, 9]
                ↑
              answer
```

**Time:** `O(n log n)`
**Extra space:** depends on the sorting implementation, but for DSA discussions you can generally focus on `O(1)` auxiliary space for in-place sorting like `sort`.

But notice: **sorting is unnecessary** just to find the maximum.

---

### 2. Optimal — One traversal

```cpp
int maxi = arr[0];

for(int i = 1; i < n; i++) {
    maxi = max(maxi, arr[i]);
}

cout << maxi;
```

Example:

```text
[5, 2, 9, 1, 7]

maxi = 5

5 → maxi = 5
2 → maxi = 5
9 → maxi = 9
1 → maxi = 9
7 → maxi = 9

answer = 9
```

**Time:** `O(n)`
**Space:** `O(1)`

This is optimal because **you have to inspect every element at least once** in the general case. Otherwise, an unseen element could be larger.

---

## 🧠 One thing to remember

Don't just memorize:

> "Largest → use max."

Understand the pattern:

> **When I need an aggregate value (maximum/minimum/sum/count), I can often solve it with one traversal.**

For example:

```cpp
int mini = arr[0];   // minimum
int maxi = arr[0];   // maximum
long long sum = 0;   // sum
int count = 0;       // count
```

Then traverse once.

### One common mistake ⚠️

Don't initialize:

```cpp
int maxi = 0;
```

if the array can contain negative numbers.

For:

```text
[-10, -5, -20]
```

that would incorrectly give `0`.

Use:

```cpp
int maxi = arr[0];
```

or:

```cpp
int maxi = INT_MIN;
```

For your DSA preparation, **`arr[0]` is a good habit** because it also works naturally when `n >= 1`.
