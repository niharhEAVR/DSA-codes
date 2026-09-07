Yes! **This is exactly the right way to learn Merge Sort.**
A normal dry run often hides what recursion is doing. Let's make every recursive call a **separate box/frame**, and track what happens when it **goes down** and when it **comes back up (backtracking)**.

We'll use:

```cpp
int arr[] = {12, 8, 9, 3, 11, 5, 4};
```

Indexes:

```text
index:   0   1   2   3   4   5   6
array:  12   8   9   3  11   5   4
```

I'll use this Merge Sort structure:

```cpp
void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}
```

---

# 1. First understand what a "box" means

When we call:

```cpp
mergeSort(arr, 0, 6);
```

a recursion frame is created:

```text
┌──────────────────────────────┐
│ mergeSort(0, 6)              │
│                              │
│ low  = 0                     │
│ high = 6                     │
│ mid  = 3                     │
│                              │
│ elements = [12 8 9 3 11 5 4]│
└──────────────────────────────┘
```

Then it calls:

```cpp
mergeSort(arr, 0, 3);
```

So **another box** is created.

The first box does NOT disappear.

It's basically **waiting**.

That's extremely important.

---

# 2. Let's start the actual dry run

Initial:

```text
arr = [12, 8, 9, 3, 11, 5, 4]
```

Call:

```cpp
mergeSort(arr, 0, 6);
```

Calculate:

```text
low  = 0
high = 6

mid = (0 + 6) / 2
    = 3
```

So:

```text
┌─────────────────────────────────────┐
│ BOX 1                               │
│ mergeSort(0, 6)                     │
│ low = 0                             │
│ high = 6                            │
│ mid = 3                             │
│                                     │
│ [12  8  9  3 | 11  5  4]           │
│              ↑                      │
│             mid                     │
│                                     │
│ Next: mergeSort(0, 3)               │
└─────────────────────────────────────┘
```

Notice:

**BOX 1 is still alive.**

It is waiting for:

```cpp
mergeSort(arr, 0, 3);
```

to finish.

---

# 3. Go into the left side

Now:

```cpp
mergeSort(arr, 0, 3);
```

Calculate:

```text
low  = 0
high = 3
mid  = 1
```

New box:

```text
┌────────────────────────────────┐
│ BOX 2                           │
│ mergeSort(0, 3)                │
│ low = 0                        │
│ high = 3                       │
│ mid = 1                        │
│                                │
│ [12 8 | 9 3]                  │
│       ↑                        │
│      mid                       │
│                                │
│ Next: mergeSort(0, 1)          │
└────────────────────────────────┘
```

BOX 1 is waiting.

```text
BOX 1
  ↓ waiting
BOX 2
  ↓ running
```

---

# 4. Go deeper

Now:

```cpp
mergeSort(arr, 0, 1);
```

Calculate:

```text
low  = 0
high = 1
mid  = 0
```

New box:

```text
┌──────────────────────────────┐
│ BOX 3                        │
│ mergeSort(0, 1)             │
│ low = 0                     │
│ high = 1                    │
│ mid = 0                     │
│                              │
│ [12 | 8]                     │
│                              │
│ Next: mergeSort(0, 0)        │
└──────────────────────────────┘
```

Now it calls:

```cpp
mergeSort(arr, 0, 0);
```

---

# 5. We hit the BASE CASE

```text
low = 0
high = 0
```

Therefore:

```cpp
if (low >= high)
    return;
```

So:

```text
┌──────────────────────────────┐
│ BOX 4                        │
│ mergeSort(0, 0)             │
│ low = 0                     │
│ high = 0                    │
│                              │
│ [12]                         │
│                              │
│ BASE CASE → RETURN           │
└──────────────────────────────┘
```

Now something VERY important happens.

We **return to BOX 3**.

BOX 3 was waiting here:

```cpp
mergeSort(arr, 0, 0);
```

That call is now finished.

So BOX 3 continues to its next line:

```cpp
mergeSort(arr, mid + 1, high);
```

For BOX 3:

```text
mid = 0
```

therefore:

```cpp
mergeSort(arr, 1, 1);
```

---

# 6. Second child of BOX 3

Create:

```text
┌──────────────────────────────┐
│ BOX 5                        │
│ mergeSort(1, 1)             │
│ low = 1                     │
│ high = 1                    │
│                              │
│ [8]                          │
│                              │
│ BASE CASE → RETURN           │
└──────────────────────────────┘
```

Return to BOX 3.

Now **both children are finished**.

So BOX 3 finally executes:

```cpp
merge(arr, 0, 0, 1);
```

This is the **backtracking part**.

---

# 7. Now MERGE happens

BOX 3 had:

```text
low  = 0
mid  = 0
high = 1
```

So:

```text
left half  = [12]
right half = [8]
```

Merge starts with:

```text
i = low     = 0
j = mid + 1 = 1
```

Let's track it:

```text
arr = [12, 8, 9, 3, 11, 5, 4]
        ↑  ↑
        i  j
```

Compare:

```text
arr[i] = 12
arr[j] = 8

8 < 12
```

Take `8`.

```text
temp = [8]
j++
```

Now:

```text
i = 0
j = 2
```

Right side is finished.

So copy remaining left element:

```text
temp = [8, 12]
```

Then copy temp back:

```text
arr = [8, 12, 9, 3, 11, 5, 4]
```

🔥 **This is where the array actually changes.**

---

# 8. Return to BOX 2

Remember BOX 2:

```text
┌────────────────────────────────┐
│ BOX 2                           │
│ mergeSort(0, 3)                │
│ low = 0                        │
│ high = 3                       │
│ mid = 1                        │
│                                │
│ LEFT was: [12 8]               │
│                                │
│ left recursion finished ✓      │
│                                │
│ Next: mergeSort(2, 3)          │
└────────────────────────────────┘
```

Now BOX 2 calls:

```cpp
mergeSort(arr, 2, 3);
```

---

# 9. BOX 6

```text
┌──────────────────────────────┐
│ BOX 6                        │
│ mergeSort(2, 3)             │
│ low = 2                     │
│ high = 3                    │
│ mid = 2                     │
│                              │
│ [9 | 3]                      │
└──────────────────────────────┘
```

It calls:

```cpp
mergeSort(arr, 2, 2);
```

Base case:

```text
┌──────────────────────────────┐
│ BOX 7                        │
│ mergeSort(2, 2)             │
│ [9]                          │
│ RETURN                       │
└──────────────────────────────┘
```

Back to BOX 6.

Then:

```cpp
mergeSort(arr, 3, 3);
```

```text
┌──────────────────────────────┐
│ BOX 8                        │
│ mergeSort(3, 3)             │
│ [3]                          │
│ RETURN                       │
└──────────────────────────────┘
```

Both children done.

Now BOX 6 performs:

```cpp
merge(arr, 2, 2, 3);
```

Merge:

```text
[9] + [3]
```

Compare:

```text
9 vs 3
```

Take 3:

```text
temp = [3]
```

Then remaining 9:

```text
temp = [3, 9]
```

Array becomes:

```text
[8, 12, 3, 9, 11, 5, 4]
```

---

# 10. Now back to BOX 2 again

BOX 2 has finished both recursive calls:

```text
LEFT  → [8, 12]
RIGHT → [3, 9]
```

Now:

```cpp
merge(arr, 0, 1, 3);
```

This is a VERY important merge.

We have:

```text
left  = [8, 12]
right = [3, 9]
```

Track the variables:

```text
i = 0
j = 2
```

Visually:

```text
[8, 12, 3, 9]
 ↑       ↑
 i       j
```

Compare:

```text
8 vs 3
```

Take `3`.

```text
temp = [3]
j++
```

Now:

```text
[8, 12, 3, 9]
 ↑          ↑
 i          j
```

Compare:

```text
8 vs 9
```

Take `8`.

```text
temp = [3, 8]
i++
```

Now:

```text
[8, 12, 3, 9]
    ↑       ↑
    i       j
```

Compare:

```text
12 vs 9
```

Take `9`.

```text
temp = [3, 8, 9]
j++
```

Right side finished.

Remaining:

```text
12
```

So:

```text
temp = [3, 8, 9, 12]
```

Copy back:

```text
arr = [3, 8, 9, 12, 11, 5, 4]
```

🔥 BOX 2 is now completely finished.

---

# 11. Return all the way to BOX 1

Remember BOX 1:

```text
┌─────────────────────────────────────┐
│ BOX 1                               │
│ mergeSort(0, 6)                     │
│ low = 0                             │
│ high = 6                            │
│ mid = 3                             │
│                                     │
│ LEFT: mergeSort(0, 3) ✓             │
│                                     │
│ Next: mergeSort(4, 6)               │
└─────────────────────────────────────┘
```

So now we go into:

```cpp
mergeSort(arr, 4, 6);
```

Current array:

```text
[3, 8, 9, 12, 11, 5, 4]
              └────────┘
               4  5  6
```

---

# 12. BOX 9

```text
┌────────────────────────────────┐
│ BOX 9                          │
│ mergeSort(4, 6)               │
│ low = 4                       │
│ high = 6                      │
│ mid = 5                       │
│                                │
│ [11 5 | 4]                    │
└────────────────────────────────┘
```

Calls:

```cpp
mergeSort(arr, 4, 5);
```

---

# 13. BOX 10

```text
┌──────────────────────────────┐
│ BOX 10                       │
│ mergeSort(4, 5)             │
│ low = 4                     │
│ high = 5                    │
│ mid = 4                     │
│                              │
│ [11 | 5]                     │
└──────────────────────────────┘
```

Then:

```cpp
mergeSort(arr, 4, 4);
```

BOX 11:

```text
┌──────────────────────────────┐
│ BOX 11                       │
│ mergeSort(4, 4)             │
│ [11]                         │
│ RETURN                       │
└──────────────────────────────┘
```

Then BOX 10 calls:

```cpp
mergeSort(arr, 5, 5);
```

BOX 12:

```text
┌──────────────────────────────┐
│ BOX 12                       │
│ mergeSort(5, 5)             │
│ [5]                          │
│ RETURN                       │
└──────────────────────────────┘
```

Now merge BOX 10:

```text
[11] + [5]
```

Result:

```text
[5, 11]
```

Array:

```text
[3, 8, 9, 12, 5, 11, 4]
```

---

# 14. Back to BOX 9

BOX 9 now calls:

```cpp
mergeSort(arr, 6, 6);
```

BOX 13:

```text
┌──────────────────────────────┐
│ BOX 13                       │
│ mergeSort(6, 6)             │
│ [4]                          │
│ RETURN                       │
└──────────────────────────────┘
```

Now BOX 9 has:

```text
left  = [5, 11]
right = [4]
```

So:

```cpp
merge(arr, 4, 5, 6);
```

Compare:

```text
5 vs 4
```

Take 4.

Then remaining:

```text
5, 11
```

Result:

```text
[4, 5, 11]
```

Array:

```text
[3, 8, 9, 12, 4, 5, 11]
```

---

# 15. NOW THE BIG FINAL BACKTRACK

We're back at BOX 1.

BOX 1 now has:

```text
LEFT  = [3, 8, 9, 12]
RIGHT = [4, 5, 11]
```

And BOX 1 finally executes:

```cpp
merge(arr, 0, 3, 6);
```

Now watch the merge variables carefully.

```text
i = low     = 0
j = mid + 1 = 4
```

Array:

```text
[3, 8, 9, 12, 4, 5, 11]
 ↑             ↑
 i             j
```

---

### Comparison 1

```text
3 vs 4
```

Take `3`.

```text
temp = [3]
i++
```

---

### Comparison 2

```text
8 vs 4
```

Take `4`.

```text
temp = [3, 4]
j++
```

---

### Comparison 3

```text
8 vs 5
```

Take `5`.

```text
temp = [3, 4, 5]
j++
```

---

### Comparison 4

```text
8 vs 11
```

Take `8`.

```text
temp = [3, 4, 5, 8]
i++
```

---

### Comparison 5

```text
9 vs 11
```

Take `9`.

```text
temp = [3, 4, 5, 8, 9]
i++
```

---

### Comparison 6

```text
12 vs 11
```

Take `11`.

```text
temp = [3, 4, 5, 8, 9, 11]
j++
```

Right side finished.

Remaining left:

```text
12
```

So:

```text
temp = [3, 4, 5, 8, 9, 11, 12]
```

Copy it back:

```text
arr = [3, 4, 5, 8, 9, 11, 12]
```

# 🎉 SORTED!

---

# 16. Now look at the COMPLETE recursion tree

This is probably the most important picture for you.

```text
                         mergeSort(0,6)
                         low=0 high=6
                         mid=3
                              │
              ┌───────────────┴───────────────┐
              ↓                               ↓
       mergeSort(0,3)                  mergeSort(4,6)
       low=0 high=3                    low=4 high=6
       mid=1                           mid=5
              │                               │
        ┌─────┴─────┐                   ┌─────┴─────┐
        ↓           ↓                   ↓           ↓
  mergeSort(0,1) mergeSort(2,3)   mergeSort(4,5) mergeSort(6,6)
     mid=0          mid=2             mid=4
       │               │                │
    ┌──┴──┐         ┌──┴──┐          ┌──┴──┐
    ↓     ↓         ↓     ↓          ↓     ↓
  (0,0) (1,1)     (2,2) (3,3)      (4,4) (5,5)
```

And the **backtracking / merging happens upward**:

```text
                         [3 4 5 8 9 11 12]
                                  ↑
                              FINAL MERGE
                                  ↑
                    ┌─────────────┴─────────────┐
                    │                           │
              [3 8 9 12]                    [4 5 11]
                  ↑                             ↑
                MERGE                         MERGE
                  ↑                             ↑
              [8 12] [3 9]                [5 11] [4]
                 ↑       ↑                    ↑
               MERGE   MERGE                MERGE
                 ↑       ↑                    ↑
              [12][8] [9][3]             [11][5] [4]
```

So the **downward journey** is:

```text
                    DIVIDE
                      ↓
                    DIVIDE
                      ↓
                    DIVIDE
                      ↓
                  ONE ELEMENT
```

And the **upward journey** is:

```text
                 ONE ELEMENT
                      ↓
                    MERGE
                      ↓
                    MERGE
                      ↓
                    MERGE
                      ↓
                 SORTED ARRAY
```

---

# 17. And here's the key thing about the variables

This is where recursion often gets confusing.

When BOX 1 has:

```text
low = 0
high = 6
mid = 3
```

and BOX 2 has:

```text
low = 0
high = 3
mid = 1
```

**BOX 2 does NOT overwrite BOX 1's variables.**

They are separate function calls with separate local variables.

Think:

```text
BOX 1
low=0 high=6 mid=3
       ↓
       waiting

BOX 2
low=0 high=3 mid=1
       ↓
       waiting

BOX 3
low=0 high=1 mid=0
       ↓
       waiting
```

When BOX 3 finishes, we go back to **BOX 2**, with its own:

```text
low = 0
high = 3
mid = 1
```

Then eventually BOX 2 finishes and we return to BOX 1, which still has:

```text
low = 0
high = 6
mid = 3
```

That's **exactly what the call stack is doing**.

---

# 18. One more thing: `i`, `j`, and `temp` are NOT recursion variables

This distinction is important.

The recursion variables are:

```text
low
high
mid
```

They belong to each `mergeSort()` call.

But when we execute:

```cpp
merge(arr, low, mid, high);
```

we enter a **different function**.

Inside `merge()` we have:

```text
i
j
temp
```

Those belong to the **merge function call**.

So conceptually:

```text
mergeSort BOX
│
├── low
├── high
├── mid
│
└── calls merge()
       │
       ├── i
       ├── j
       ├── temp
       └── k
```

And when `merge()` finishes, those merge variables are gone.

Then we return to the `mergeSort()` box.

---

## The entire Merge Sort in one sentence

If you understand this sequence, you've understood the algorithm:

> **Create a recursion box → calculate `mid` → go completely down the left side → hit base case → come back → go down the right side → hit base case → come back → merge the two sorted halves → continue going upward until the original box performs the final merge.**

That's the mental model you want to keep. **Don't memorize the code before this recursion tree feels natural.** Once this clicks, the code is actually quite small.
