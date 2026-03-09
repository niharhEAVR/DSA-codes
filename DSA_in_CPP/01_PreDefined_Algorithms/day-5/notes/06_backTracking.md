### 👉 **What is backtracking (returning) in recursion?**

### 👉 **How recursion flows from left → right → merge?**

---

# 🧠 **FIRST: The Most Important Truth About Recursion**

### **Recursion is just function calls stacked on top of each other.**

Every time you call:

```
mergeSort(arr, low, mid);
```

The program **pauses** the current function
and goes into the new one.

Like this:

```
mergeSort(0,6)
   pauses
      mergeSort(0,3)
         pauses
            mergeSort(0,1)
               pauses
                  mergeSort(0,0)  (stops here)
               returns (backtracks)
               now go to right
                  mergeSort(1,1)
               returns
               MERGE(0,1)
```

This coming back is called:

# 🔄 **BACKTRACKING (RETURNING)**

---

# 🧩 **WHAT IS BACKTRACKING? (super simple example)**

Imagine you have a tunnel with multiple paths.
You go LEFT first.
You keep going left until you hit a dead end.

Then you RETURN back one level
and explore RIGHT.

That returning is:

# ⭐ **Backtracking = completed one branch → return → go to next branch**

Merge sort does the exact same thing.

---

# 🎯 **HOW IT WORKS IN YOUR MERGE SORT**

Your function:

```
mergeSort(arr, low, mid);     // 1. go left
mergeSort(arr, mid+1, high);  // 2. go right
mergee(...);                  // 3. merge
```

### 👉 Recursion ALWAYS does:

1. **Left call (go deep)**
2. Hit single element → return
3. Do right call
4. When BOTH sides done → merge

---

# 🧱 Let me show this visually (you will understand 100% now)

Call:

```
mergeSort(0,6)
```

It calls:

```
mergeSort(0,3)
```

That calls:

```
mergeSort(0,1)
```

That calls:

```
mergeSort(0,0)   <-- stops (base case)
```

Now this returns (backtrack):

```
mergeSort(1,1)   <-- stops
```

Now BOTH sides (0,0) and (1,1) are done
so merge happens:

```
merge(0,1)
```

---

# 🌳 **Flow looks like this:**

```
mergeSort(0,6)
    |
    v
mergeSort(0,3)
    |
    v
mergeSort(0,1)
    |
    v
mergeSort(0,0)  <-- BASE → RETURN
    |
    (backtrack)
    |
mergeSort(1,1)  <-- BASE → RETURN
    |
    (backtrack)
    |
merge(0,1)      <-- happens now
```

---

# ⭐ WHY MERGE ONLY HAPPENS AFTER BOTH LEFT & RIGHT FINISH?

Because merge needs **two sorted parts**.

So recursion ensures:

1. Finish left
2. Finish right
3. Then merge

---

# ✔️ SUPER SIMPLE SUMMARY

### Recursion works like this:

```
Go left until you can't
Then backtrack
Then go right
Then merge
Then backtrack again
```

That's literally everything.