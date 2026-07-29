This is one of the **most important concepts** in C++, not just STL.

If you understand **comparators**, you can solve many sorting and priority queue questions in interviews.

---

# What is a Comparator?

A **comparator** is simply a **rule** that tells C++:

> **"When comparing two elements, which one should come first?"**

That's it.

Think of it as a **decision maker**.

---

# Real-Life Example

Suppose there are three students.

```text
Nihar   85

Rahul   92

Amit    78
```

Now I ask you:

> "Sort these students."

Immediately you'll ask:

> **Sort by what?**

* Name?
* Marks?
* Age?
* Height?

The answer depends on the **comparison rule**.

That rule is called the **comparator**.

---

# Example 1: Integers

Suppose

```cpp
vector<int> v = {5,2,8,1,7};
```

You write

```cpp
sort(v.begin(), v.end());
```

Who decides that

```text
1
```

comes before

```text
2
```

?

Internally C++ uses a comparator equivalent to

```cpp
bool compare(int a, int b)
{
    return a < b;
}
```

If

```cpp
compare(2,5)
```

returns

```cpp
true
```

then

```text
2 comes before 5
```

---

# How sort() thinks

Suppose

```text
5 2
```

C++ asks

```cpp
compare(5,2)
```

which means

```cpp
return 5 < 2;
```

Result

```cpp
false
```

So

```text
5 should NOT come before 2
```

Swap them.

Now compare

```text
2 5
```

```cpp
compare(2,5)
```

returns

```cpp
true
```

Keep them.

This happens thousands of times during sorting.

---

# Default Comparator

Whenever you write

```cpp
sort(v.begin(), v.end());
```

C++ internally behaves as if you wrote

```cpp
sort(v.begin(), v.end(), less<int>());
```

`less<int>()` means

```cpp
a < b
```

Ascending order.

---

# Descending Order

You can tell C++

> "Use another rule."

```cpp
sort(v.begin(), v.end(), greater<int>());
```

Now the comparator becomes

```cpp
a > b
```

Output

```text
8 7 5 2 1
```

---

# Making Your Own Comparator

Suppose

```cpp
vector<int> v = {5,2,8,1};
```

You want

> Even numbers first.

Result should be

```text
2 8 1 5
```

How?

Write your own rule.

```cpp
bool cmp(int a, int b)
{
    if(a%2==0 && b%2!=0)
        return true;

    if(a%2!=0 && b%2==0)
        return false;

    return a<b;
}
```

Then

```cpp
sort(v.begin(), v.end(), cmp);
```

Output

```text
2 8 1 5
```

Amazing, right?

You taught C++ your own sorting rule.

---

# Most Common Interview Example

Suppose

```cpp
vector<pair<int,int>> v=
{
    {1,90},
    {2,75},
    {3,85}
};
```

Meaning

```text
Roll Marks

1     90

2     75

3     85
```

Now sort by marks.

Comparator

```cpp
bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.second < b.second;
}
```

Call

```cpp
sort(v.begin(), v.end(), cmp);
```

Output

```text
2 75

3 85

1 90
```

---

# What does sort() actually do?

Suppose

```cpp
sort(v.begin(),v.end(),cmp);
```

Internally it repeatedly calls

```cpp
cmp(a,b)
```

For example

```cpp
cmp(5,2)
```

or

```cpp
cmp(8,5)
```

or

```cpp
cmp(2,1)
```

It keeps asking

> Should **a** come before **b**?

If your function says

```cpp
true
```

it places `a` before `b`.

Otherwise

`b` comes first.

---

# Rule to Remember

Your comparator always answers one question:

> **Should the first argument come before the second argument?**

If

```cpp
return true;
```

Yes.

If

```cpp
return false;
```

No.

That's all.

---

# Example

Comparator

```cpp
bool cmp(int a,int b)
{
    return a>b;
}
```

Now C++ asks

```cpp
cmp(8,5)
```

Returns

```cpp
true
```

Means

```text
8 should come before 5
```

Descending order.

---

# Another Example

Comparator

```cpp
bool cmp(string a,string b)
{
    return a.length()<b.length();
}
```

Input

```text
Cat

Elephant

Dog

Monkey
```

Output

```text
Cat

Dog

Monkey

Elephant
```

Now you're sorting by **length**, not alphabetically.

---

# Another Example

Sort by absolute value.

```cpp
bool cmp(int a,int b)
{
    return abs(a)<abs(b);
}
```

Input

```text
-10

2

-3

5
```

Output

```text
2

-3

5

-10
```

---

# Comparator in priority_queue

Comparators are used everywhere.

Default

```cpp
priority_queue<int> pq;
```

Largest element on top.

Because it uses

```cpp
less<int>
```

Internally.

---

Min Heap

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

Now comparator changed.

Smallest element comes first.

---

# Comparator in set

Default

```cpp
set<int>
```

Ascending order.

You can write

```cpp
set<int, greater<int>> s;
```

Output

```text
9

7

5

2
```

Descending order.

---

# Comparator in map

```cpp
map<int,string,greater<int>> mp;
```

Keys

```text
10

7

5

2
```

Instead of

```text
2

5

7

10
```

---

# Where Will You See Comparators?

| STL Container    | Uses Comparator? |
| ---------------- | ---------------- |
| `sort()`         | ✅                |
| `stable_sort()`  | ✅                |
| `set`            | ✅                |
| `multiset`       | ✅                |
| `map`            | ✅                |
| `multimap`       | ✅                |
| `priority_queue` | ✅                |

---

# Easy Analogy

Imagine you're hiring people.

There are five candidates.

How do you rank them?

* Highest salary first?
* Youngest first?
* Tallest first?
* Most experienced first?

The interviewer asks:

> "What rule are you using?"

That rule is the **comparator**.

In C++, the comparator tells the STL:

> **"This is how two elements should be ordered."**

---

# The Golden Rule ⭐

Whenever you write a comparator, ask yourself **only one question**:

```text
Should 'a' come before 'b'?
```

If yes:

```cpp
return true;
```

If no:

```cpp
return false;
```

Everything else—whether you're sorting integers, pairs, custom objects, using `set`, `map`, or `priority_queue`—is just a different application of this same idea.

---

### One small correction to your intuition

A comparator **doesn't perform the sorting itself**.

Instead:

* `sort()` (or `set`, `priority_queue`, etc.) is the **worker**.
* The comparator is the **rulebook** the worker follows.

The algorithm keeps comparing pairs of elements, asks the comparator which one should come first, and uses those answers to build the final order. Once you understand that relationship, comparators become much less mysterious.



---
---
---
---
---
---
---



Excellent question. This is exactly the kind of question interviewers like because it shows you're thinking about **performance**, not just syntax.

The short answer is:

> **Yes, calling a comparator is extra work. But it does NOT change the overall time complexity.**

Let's understand why.

---

# Without Comparator

Suppose you write

```cpp
sort(v.begin(), v.end());
```

Internally, C++ is doing something like:

```cpp
if (a < b)
```

---

# With Comparator

```cpp
bool cmp(int a, int b)
{
    return a > b;
}

sort(v.begin(), v.end(), cmp);
```

Now instead of

```cpp
if (a < b)
```

it does

```cpp
if (cmp(a, b))
```

which becomes

```cpp
return a > b;
```

So yes, there is **one extra function call**.

---

# Doesn't that make it slower?

Imagine you're sorting only two numbers.

Without comparator

```text
Compare

5 < 2
```

1 operation.

---

With comparator

```text
Call cmp()

↓

5 > 2

↓

Return true/false
```

Maybe 2 or 3 operations.

So for **one comparison**, it is slightly more work.

---

# But what about the whole sorting?

Suppose there are

```text
1000 numbers
```

A sorting algorithm performs approximately

```text
1000 × log₂(1000)

≈ 1000 × 10

≈ 10,000 comparisons
```

Whether each comparison is

```cpp
a < b
```

or

```cpp
cmp(a,b)
```

the algorithm still performs about **10,000 comparisons**.

So the complexity remains

```text
O(N log N)
```

---

# Think of it like this

Imagine two teachers checking exam papers.

### Teacher A

Each paper takes

```text
1 minute
```

---

### Teacher B

Each paper takes

```text
1.2 minutes
```

Now there are

```text
100 papers
```

Teacher A

```text
100 minutes
```

Teacher B

```text
120 minutes
```

Teacher B is slower.

But both are still

```text
O(N)
```

The difference is only a **constant factor**.

In Big-O notation, **constant factors are ignored**.

---

# What Big-O measures

Big-O doesn't care if each comparison takes:

* 1 CPU instruction
* 5 CPU instructions
* 10 CPU instructions

It only cares **how the work grows as N increases**.

Example:

|    N | Comparisons |
| ---: | ----------: |
|   10 |         ~33 |
|  100 |        ~664 |
| 1000 |       ~9966 |

Whether one comparison costs 1 unit or 3 units, the growth is still proportional to **N log N**.

---

# A Better Example

Suppose your comparator is

```cpp
bool cmp(int a, int b)
{
    return a > b;
}
```

This is almost free.

Now imagine a terrible comparator:

```cpp
bool cmp(int a, int b)
{
    // Imagine this takes 1000 operations
    return expensiveCalculation(a) < expensiveCalculation(b);
}
```

Now each comparison is expensive.

The sorting algorithm still performs about **N log N comparisons**, but each comparison costs much more.

Mathematically:

```text
Time = (Number of comparisons) × (Cost of one comparison)
```

So:

```text
≈ O(N log N) × Cost(comparator)
```

If the comparator is constant time (which it usually is), we write simply:

```text
O(N log N)
```

---

# Why is the comparator usually fast?

Because it's normally just something like:

```cpp
return a < b;
```

or

```cpp
return a.second < b.second;
```

or

```cpp
return a.age < b.age;
```

Each of these takes **constant time (O(1))**.

---

# This is why interviewers expect

Comparators should be **simple**.

Good:

```cpp
bool cmp(Student a, Student b)
{
    return a.marks > b.marks;
}
```

Bad:

```cpp
bool cmp(Student a, Student b)
{
    // Read a file
    // Query a database
    // Perform heavy calculations
}
```

That would make sorting unnecessarily slow.

---

## Interview Insight ⭐

There's one more subtle performance point.

Notice this comparator:

```cpp
bool cmp(Student a, Student b)
{
    return a.marks < b.marks;
}
```

Every comparison **copies** two `Student` objects.

A better version is:

```cpp
bool cmp(const Student& a, const Student& b)
{
    return a.marks < b.marks;
}
```

Now no objects are copied—only references are passed.

The time complexity is still **O(N log N)**, but it's noticeably faster for large objects.

---

### The Golden Rule

A sorting algorithm asks the comparator:

> **"Should A come before B?"**

It asks this question roughly **O(N log N)** times.

As long as answering that question takes **O(1)** time, the overall sorting complexity remains:

```text
O(N log N)
```

So yes, there is a tiny amount of extra work per comparison, but it changes the **constant factor**, not the **time complexity**. That's why custom comparators are used everywhere in C++ STL.
