> “What *exactly happens* when we rotate an array?”

Let’s break it down **visually and conceptually** so you fully understand the rotation logic — because this concept shows up a lot in array and binary search problems.

---

## 🧩 1. What "rotation" means

Rotation means **shifting** elements **circularly**.

Imagine your array as a **circle** instead of a straight line —
when elements move off one end, they reappear at the other end.

---

### Example:

Original sorted array:

```
[1, 2, 3, 4, 5]
```

---

## 🔁 2. Rotate Right by 1 position

Move the **last element** to the **front**.

```
Before: [1, 2, 3, 4, 5]
After : [5, 1, 2, 3, 4]
```

Visually:

```
→ move 5 from end to start
```

---

## 🔁 3. Rotate Left by 1 position

Move the **first element** to the **end**.

```
Before: [1, 2, 3, 4, 5]
After : [2, 3, 4, 5, 1]
```

Visually:

```
1 → goes to the back
```

---

## 🔄 4. Rotate by multiple positions (k)

When we say:

> Rotate left by k = 2 positions

We take the **first 2 elements** and move them to the **end** in the same order.

```
Before: [1, 2, 3, 4, 5]
Cut here →   ↑
After : [3, 4, 5, 1, 2]
```

So `[3,4,5,1,2]` = `[1,2,3,4,5]` rotated left by 2 positions.

---

## ⚙️ 5. Rotation Formula (Conceptual)

If `n` is the array size and `k` is the number of rotations:

For **left rotation**:

```
new_index = (old_index - k + n) % n
```

For **right rotation**:

```
new_index = (old_index + k) % n
```

This formula just tells you where each element *moves* after rotation.

---

## 🧠 6. Why it’s called "rotated sorted array"

Because it’s **still sorted**, but the **starting point changed**.

Examples:

| Original Sorted | Rotation   | Rotated Array   |
| --------------- | ---------- | --------------- |
| [1, 2, 3, 4, 5] | Left by 1  | [2, 3, 4, 5, 1] |
| [1, 2, 3, 4, 5] | Left by 2  | [3, 4, 5, 1, 2] |
| [1, 2, 3, 4, 5] | Right by 2 | [4, 5, 1, 2, 3] |

---

## ✅ So the “rotation logic” in one line:

> **Rotation means taking part of the array from one end and putting it at the other end — while keeping the internal order of elements unchanged.**
