Absolutely. **Two Pointer** is one of the most useful basic DSA techniques, especially for the kind of questions you're preparing for in TCS Ignite.

## 1. What is Two Pointer?

The name literally means:

> **Use two variables/pointers to keep track of two positions in an array/string.**

For example:

```cpp
int left = 0;
int right = n - 1;
```

So if the array is:

```text
[1, 2, 3, 4, 5, 6]
 ↑             ↑
left          right
```

You move `left` and/or `right` depending on the problem.

---

# 2. Why do we need it?

Suppose you have:

> Find whether two numbers in a **sorted array** add up to `10`.

Array:

```text
[1, 2, 3, 4, 6, 8, 9]
```

A beginner might use two loops:

```cpp
for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
        if(arr[i] + arr[j] == 10)
            return true;
    }
}
```

This takes **O(n²)**.

Two pointer can solve it in **O(n)**.

---

# 3. The basic Two Pointer pattern

Start from both ends:

```text
[1, 2, 3, 4, 6, 8, 9]
 ↑                 ↑
 L                 R
```

Calculate:

```text
arr[L] + arr[R]
= 1 + 9
= 10
```

We found the answer!

But suppose the target was `12`.

### Step 1

```text
1 + 9 = 10
```

Too small.

So we need a **larger sum**.

Move `L` forward:

```text
[1, 2, 3, 4, 6, 8, 9]
    ↑              ↑
    L              R
```

Now:

```text
2 + 9 = 11
```

Still too small.

Move `L` again:

```text
[1, 2, 3, 4, 6, 8, 9]
       ↑           ↑
       L           R
```

```text
3 + 9 = 12
```

Found it.

---

# 4. The most important rule

For a **sorted array**:

```text
sum < target
→ move LEFT forward

sum > target
→ move RIGHT backward

sum == target
→ found answer
```

Think:

> **Need bigger → left++**
> **Need smaller → right--**

That's the core idea.

---

# 5. Code

```cpp
bool twoSum(vector<int>& arr, int target) {

    int left = 0;
    int right = arr.size() - 1;

    while(left < right) {

        int sum = arr[left] + arr[right];

        if(sum == target)
            return true;

        else if(sum < target)
            left++;

        else
            right--;
    }

    return false;
}
```

---

# 6. Why does moving the pointer work?

This is the part you **really need to understand**, rather than memorizing the code.

Suppose:

```text
[1, 2, 3, 4, 6, 8, 9]
 ↑                 ↑
 L                 R
```

Current sum:

```text
1 + 9 = 10
```

Suppose target = `12`.

We need a bigger sum.

Could we move `R`?

```text
1 + 8 = 9
```

That makes the sum **even smaller**.

So moving `R` is useless.

Therefore:

```text
L++
```

is the only useful direction.

That's why the technique works on a **sorted array**.

---

# 7. Two Pointer doesn't always mean left + right

This is VERY important.

There are actually different patterns.

### Pattern 1 — Opposite ends

```text
L →          ← R
[1 2 3 4 5 6]
```

Common for:

* Two Sum in sorted array
* Palindrome
* Reverse array
* Container with most water
* Pair problems

---

### Pattern 2 — Both pointers move forward

Example:

```text
L
↓
[1 2 3 4 5 6]
  ↑
  R
```

Both start near the beginning.

This is commonly called the **slow/fast pointer** or **same-direction two pointer** technique.

For example, removing duplicates from a sorted array:

```text
[1,1,2,2,3]
```

One pointer keeps track of where to place the next unique element, while another scans the array.

---

# 8. How do I know when to use Two Pointer?

This is probably the most important thing for your TCS preparation.

When you see a question involving:

### 🔹 Array/string

AND especially:

### 🔹 Pair of elements

Think:

> **Can Two Pointer work here?**

For example:

> Find two numbers whose sum is 20.

Think:

```text
Two Pointer?
```

If the array is **sorted**, then very likely yes.

---

### Another clue: opposite ends

If the question involves:

> Check whether a string is palindrome.

Example:

```text
madam
↑   ↑
L   R
```

Compare:

```text
s[L] == s[R]
```

Then:

```text
L++
R--
```

So:

```cpp
bool isPalindrome(string s) {

    int left = 0;
    int right = s.size() - 1;

    while(left < right) {

        if(s[left] != s[right])
            return false;

        left++;
        right--;
    }

    return true;
}
```

That's two pointer.

---

# 9. Two Pointer vs Normal For Loop

This is where you were asking earlier about **"how do I determine which technique to use?"**

Suppose:

> Find whether an array contains two numbers whose sum is `10`.

### Brute force

```cpp
for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
        ...
    }
}
```

Two nested loops:

```text
O(n²)
```

### Two Pointer

If sorted:

```cpp
int left = 0;
int right = n - 1;

while(left < right) {
    ...
}
```

One loop:

```text
O(n)
```

So you should develop this thought process:

```text
Question
   ↓
Array/String?
   ↓
Involves two positions/elements?
   ↓
Is the array sorted OR can it be sorted?
   ↓
Try Two Pointer
```

---

# 10. VERY IMPORTANT: Sorting changes things

Suppose:

```text
[8, 2, 5, 1, 9, 4]
```

Target = `10`.

You **cannot directly** use the left/right sum logic because the array isn't sorted.

But you could sort it:

```text
[1, 2, 4, 5, 8, 9]
```

Then:

```text
L                 R
↑                 ↑
1                 9

1 + 9 = 10
```

So Two Pointer becomes possible.

But be careful:

```text
Sorting = O(n log n)
Two pointer = O(n)
```

Overall:

```text
O(n log n)
```

---

# 11. Two Pointer vs Sliding Window

You'll encounter these together a LOT.

Don't confuse them.

### Two Pointer

Usually focuses on **two positions/elements**.

Example:

```text
Find two numbers whose sum = target
```

```text
L →        ← R
```

### Sliding Window

Usually focuses on a **continuous subarray/substring**.

Example:

> Find the longest subarray with sum ≤ K.

```text
L → [  window  ] ← R
```

You expand/shrink a window.

So a simple mental distinction:

```text
Two Pointer
→ relationship between positions/elements

Sliding Window
→ relationship between a continuous range
```

---

# 12. For your TCS Ignite level

You don't need to master every advanced variation right now.

Focus on these **5 two-pointer patterns**:

| Pattern                 | Example      |
| ----------------------- | ------------ |
| Opposite ends           | Palindrome   |
| Sorted pair sum         | Two Sum      |
| Remove duplicates       | Sorted array |
| Move elements           | Move zeroes  |
| Merge two sorted arrays | Merge arrays |

If you understand **why the pointers move**, rather than memorizing code, you'll be able to recognize many TCS-style questions.

### The one sentence to remember:

> **Two Pointer = use two indices to avoid repeatedly checking the same elements, usually by moving them intelligently based on the problem's structure.**

And the most basic pattern to memorize is:

```cpp
int left = 0;
int right = n - 1;

while(left < right) {

    // use arr[left] and arr[right]

    if(condition)
        left++;
    else
        right--;
}
```

The next thing you should learn is **how to recognize Two Pointer questions from the wording of a problem**—that's actually more important than the code.
