`std::next_permutation()` is one of the most useful STL algorithms in C++. It generates the **next lexicographically greater permutation** of a sequence.

It is commonly used in:

* Backtracking
* Brute force problems
* Generating all arrangements of elements
* Competitive Programming

Let's understand it from the beginning.

---

# 1. What is a permutation?

A permutation means **arrangement**.

Example:

Elements:

```
1 2 3
```

Possible permutations:

```
123
132
213
231
312
321
```

There are

\[
n!
\]

permutations.

For 3 numbers:

```
3! = 6
```

---

# 2. What is Lexicographical Order?

Think of dictionary order.

For numbers:

```
123
132
213
231
312
321
```

Each next number is slightly bigger than the previous one.

This is called **lexicographical order**.

---

# 3. What does next_permutation() do?

Suppose you have

```
123
```

Calling

```cpp
next_permutation()
```

changes it to

```
132
```

Again

```
132
```

↓

```
213
```

Again

```
231
```

Again

```
312
```

Again

```
321
```

Again...

There is no next permutation.

So it becomes

```
123
```

and returns **false**.

---

# Syntax

```cpp
next_permutation(first, last);
```

Example

```cpp
vector<int> v = {1,2,3};

next_permutation(v.begin(), v.end());
```

Now

```
1 3 2
```

---

# Return Value

Returns

```
true
```

if next permutation exists.

Returns

```
false
```

if current permutation is already the largest.

Example

```cpp
vector<int> v = {3,2,1};

bool ans = next_permutation(v.begin(), v.end());
```

Result

```
ans = false

v = {1,2,3}
```

Notice it automatically becomes the smallest permutation.

---

# Example 1

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {1,2,3};

    next_permutation(v.begin(), v.end());

    for(int x : v)
        cout << x << " ";
}
```

Output

```
1 3 2
```

---

# Example 2

Generate all permutations

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s = "ABC";

    do
    {
        cout << s << endl;
    }
    while(next_permutation(s.begin(), s.end()));
}
```

Output

```
ABC
ACB
BAC
BCA
CAB
CBA
```

---

# Why do we use do-while?

Wrong

```cpp
while(next_permutation(...))
{
}
```

This starts from the **second permutation**.

Correct

```cpp
do
{
    print();
}
while(next_permutation(...));
```

First permutation gets printed first.

---

# Example 3

```cpp
vector<int> v = {1,2,3};

do
{
    for(int x:v)
        cout<<x;
    cout<<endl;
}
while(next_permutation(v.begin(),v.end()));
```

Output

```
123
132
213
231
312
321
```

---

# Important Requirement

The array must be **sorted** if you want **all permutations**.

Correct

```
1 2 3
```

Wrong

```
2 1 3
```

If you start with

```
2 1 3
```

Output will be

```
213
231
312
321
```

It skips

```
123
132
```

because it only generates permutations **after the current one**.

---

# Duplicates

Suppose

```
1 1 2
```

Then

```cpp
do
{
}
while(next_permutation(...));
```

Output

```
112
121
211
```

Notice

No duplicate permutations are produced.

Very useful.

---

# Time Complexity

For each call

```
O(n)
```

because it may reverse part of the array.

Generating all permutations

```
n! × O(n)
```

---

# How does it work internally?

Suppose

```
1 2 4 3
```

Need next permutation.

---

## Step 1

Find first decreasing element from right.

```
1 2 4 3
      ^
```

Compare

```
4 > 3
```

Keep moving.

Now

```
2 < 4
```

Found pivot.

```
1 2 4 3
  ^
```

Pivot = 2

---

## Step 2

Find smallest number greater than pivot on right.

Right side

```
4 3
```

Smallest greater than 2

```
3
```

Swap

```
1 3 4 2
```

---

## Step 3

Reverse right part.

Current

```
1 3 4 2
```

Reverse

```
4 2
```

↓

```
2 4
```

Answer

```
1 3 2 4
```

That's the next lexicographically larger permutation.

---

## Another Example

Current

```
12354
```

### Step 1

Find pivot

```
1 2 3 5 4
      ^
```

Pivot = 3

---

### Step 2

Smallest greater than 3

```
4
```

Swap

```
12453
```

---

### Step 3

Reverse right

```
53
```

↓

```
35
```

Final

```
12435
```

---

# Why reverse?

After finding the pivot, everything to its right is already in **descending order** (that's why we stopped there). Reversing it makes that suffix **ascending**, which is the **smallest possible** arrangement after increasing the pivot. This guarantees we get the **immediate next** permutation, not a later one.

---

# Common Interview Questions

### 1. Generate all permutations

```cpp
sort(v.begin(), v.end());

do
{
    // use permutation
}
while(next_permutation(v.begin(), v.end()));
```

---

### 2. Count permutations

```cpp
int cnt = 1;

while(next_permutation(v.begin(), v.end()))
    cnt++;
```

---

### 3. Previous permutation

There is also

```cpp
prev_permutation(v.begin(), v.end());
```

It generates the previous lexicographical permutation.

Example

```
321
```

↓

```
312
```

↓

```
231
```

↓

```
213
```

↓

```
132
```

↓

```
123
```

---

# Summary

| Feature                          | Details                                                                                    |
| -------------------------------- | ------------------------------------------------------------------------------------------ |
| Header                           | `#include <algorithm>`                                                                     |
| Function                         | `next_permutation(first, last)`                                                            |
| Return                           | `true` if next permutation exists, `false` otherwise                                       |
| Complexity                       | `O(n)` per call                                                                            |
| Requirement for all permutations | Start with the sequence sorted in ascending order                                          |
| Handles duplicates               | Yes, generates only unique lexicographic permutations when starting from a sorted sequence |
| Related function                 | `prev_permutation()`                                                                       |

## When should you use `next_permutation`?

Use it when:

* You need to try **every possible arrangement** of a small set of elements.
* You want the permutations in **sorted (lexicographical) order**.
* `n` is small (typically `n ≤ 8–10`), because the total number of permutations grows as `n!`.

For larger `n`, generating all permutations quickly becomes impractical due to the factorial growth.


















No problem. Let's learn it the way you've been liking recently—**step by step with logic**, not by memorizing.

Forget the STL for 5 minutes.

---

# Imagine you have 3 numbers

```text
1 2 3
```

How many different ways can you arrange them?

```text
123
132
213
231
312
321
```

These are called **permutations**.

Now imagine these are standing in a line.

```text
123
 ↓
132
 ↓
213
 ↓
231
 ↓
312
 ↓
321
```

Each arrangement has a **next arrangement**.

That is exactly what `next_permutation()` finds.

---

# Example 1

Suppose

```text
1 2 3
```

Now we ask:

> "What is the next arrangement?"

Answer:

```text
1 3 2
```

because that's the next one in order.

If we ask again,

```text
1 3 2
```

↓

```text
2 1 3
```

Again,

```text
2 1 3
```

↓

```text
2 3 1
```

Again,

```text
2 3 1
```

↓

```text
3 1 2
```

Again,

```text
3 1 2
```

↓

```text
3 2 1
```

---

Now ask again.

Current:

```text
3 2 1
```

Is there any larger arrangement?

No.

So

```cpp
next_permutation(...)
```

returns

```text
false
```

and changes it back to

```text
1 2 3
```

---

# What happens in C++?

```cpp
vector<int> v = {1,2,3};

next_permutation(v.begin(), v.end());
```

Now

```text
v = {1,3,2}
```

Call it again

```cpp
next_permutation(v.begin(), v.end());
```

Now

```text
v = {2,1,3}
```

Notice something important:

**The function changes the vector itself.**

---

# Now the real question

You may ask,

> **How does C++ know that after `123` comes `132`?**

Excellent question.

Let's see.

---

Current number

```text
123
```

Can we make it just a little bigger?

Yes.

```text
132
```

Can we make something even smaller than 132 but bigger than 123?

Let's check.

```text
124 ❌ (4 doesn't exist)

131 ❌ (two 1's)

213 ❌ bigger than 132
```

So

```text
132
```

is the smallest bigger arrangement.

That's why it is called the **next** permutation.

---

# Another example

Current

```text
231
```

What is the next arrangement?

Possible bigger arrangements

```text
312
321
```

Which is the smallest bigger one?

```text
312
```

So

```text
231
```

↓

```text
312
```

---

# What if we write a loop?

```cpp
vector<int> v = {1,2,3};

do
{
    for(int x : v)
        cout << x;
    cout << endl;
}
while(next_permutation(v.begin(), v.end()));
```

Let's execute it.

Initially

```text
123
```

Print

```text
123
```

Call `next_permutation()`

Now vector becomes

```text
132
```

Print

```text
132
```

Again

```text
213
```

Print

```text
213
```

Again

```text
231
```

Print

```text
231
```

Again

```text
312
```

Print

```text
312
```

Again

```text
321
```

Print

```text
321
```

Again

No next permutation.

Function returns

```text
false
```

Loop stops.

Output

```text
123
132
213
231
312
321
```

---

# But how does C++ find the next one?

Don't worry about the algorithm yet.

First understand **what** it does.

Think of it like this:

You have pages of a dictionary.

```
apple
apply
apt
ball
bat
```

If you're on **apple**, the next word is **apply**.

If you're on **apply**, the next is **apt**.

Similarly,

```
123
132
213
231
312
321
```

`next_permutation()` simply moves to the **next page** in this "dictionary" of permutations.

---

## First, tell me if this much is clear.

Especially these three points:

1. A permutation is just a different arrangement of the same elements.
2. `next_permutation()` changes the current arrangement to the **next lexicographically larger** arrangement.
3. If there is no next arrangement (like `321`), it returns `false` and resets the sequence to the smallest arrangement.

If you're comfortable with that, then I'll explain the **internal algorithm** (pivot, swap, reverse) visually. Once you see it once, you'll be able to solve interview questions based on it.
