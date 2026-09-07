Perfect! Since you've understood **count digits** and **reverse a number**, **palindrome** becomes very easy.

Let's learn it step by step.

---

# What is a palindrome?

A palindrome is something that reads the **same forwards and backwards**.

Examples:

```text
121
```

Forward

```text
121
```

Backward

```text
121
```

Same.

So it is a palindrome.

---

Another example

```text
12321
```

Forward

```text
12321
```

Backward

```text
12321
```

Same.

Palindrome.

---

Not a palindrome

```text
123
```

Forward

```text
123
```

Backward

```text
321
```

Different.

Not a palindrome.

---

# How do we check?

Suppose

```text
n = 12321
```

Question:

How do we know if it's a palindrome?

One simple idea:

1. Reverse the number.
2. Compare it with the original.

If both are equal

↓

Palindrome.

---

# Example 1

Original

```text
121
```

Reverse

```text
121
```

Compare

```text
121 == 121
```

True.

Answer

```text
Palindrome
```

---

# Example 2

Original

```text
456
```

Reverse

```text
654
```

Compare

```text
456 == 654
```

False.

Not a palindrome.

---

# Step-by-Step Logic

Suppose

```text
n = 12321
```

First save the original number.

```cpp
original = n;
```

Why?

Because while reversing, `n` becomes `0`.

If we don't save it, we lose the original number.

---

Now reverse it.

We already know how.

Start

```text
rev = 0
```

### Iteration 1

```text
digit = 1

rev = 0×10 +1

=1

n=1232
```

---

### Iteration 2

```text
digit=2

rev=1×10+2

=12

n=123
```

---

### Iteration 3

```text
digit=3

rev=12×10+3

=123

n=12
```

---

### Iteration 4

```text
digit=2

rev=1232

n=1
```

---

### Iteration 5

```text
digit=1

rev=12321

n=0
```

Finished.

---

Now compare

```text
original =12321

rev      =12321
```

Equal?

Yes.

Palindrome.

---

# Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n = 12321;

    int original = n;
    int rev = 0;

    while(n > 0)
    {
        int digit = n % 10;

        rev = rev * 10 + digit;

        n /= 10;
    }

    if(original == rev)
        cout << "Palindrome";
    else
        cout << "Not Palindrome";
}
```

Output

```text
Palindrome
```

---

# Dry Run for a Non-Palindrome

Suppose

```text
n = 123
```

Reverse

```text
321
```

Compare

```text
123 == 321
```

False.

Output

```text
Not Palindrome
```

---

# Time Complexity

The loop runs once for each digit.

If there are `d` digits:

* **Time:** `O(d)`
* **Space:** `O(1)`

---

# Interview Question (LeetCode 9)

If you solve **LeetCode 9: Palindrome Number**, there are **two special cases**.

### Case 1: Negative numbers

```text
-121
```

Forward

```text
-121
```

Backward

```text
121-
```

They are not the same.

So

```cpp
-121
```

is **not** a palindrome.

---

### Case 2: Numbers ending with 0

Suppose

```text
10
```

Reverse

```text
01
```

As an integer,

```text
01 = 1
```

Compare

```text
10 != 1
```

Not a palindrome.

In fact, **every number ending in `0` (except `0` itself) cannot be a palindrome**, because the reversed number would start with `0`, and leading zeros are not stored in integers.

---

# A Small Challenge

Can you dry-run this yourself?

```text
n = 1221
```

Fill in this table:

| n    | digit | rev |
| ---- | ----: | --: |
| 1221 |     ? |   ? |
| 122  |     ? |   ? |
| 12   |     ? |   ? |
| 1    |     ? |   ? |

If you can complete this table correctly, you've fully understood palindrome checking using reversal.

---

### One important note

The method above is perfect for learning and works in many cases. However, **the actual LeetCode "Palindrome Number" problem** has one extra challenge: if reversing the number causes an `int` overflow, you need to avoid that. The most elegant solution is to **reverse only half of the number**, which avoids overflow entirely.

I recommend learning this simple full-reversal method first. Once you're comfortable with it, we can move on to the optimized interview solution that reverses only half the digits.




---
---
---
---
---
---
---
---
---
---
---


```cpp
class Solution
{
public:
    bool isPalindrome(int x)
    {
        int copy = x;
        int palindrome{};
        while (x != 0)
        {
            int digit = x % 10;
            if (palindrome > INT_MAX / 10 || (palindrome == INT_MAX / 10 && digit > 7))
                return 0;
            if (palindrome < INT_MIN / 10 || (palindrome == INT_MIN / 10 && digit < -8))
                return 0;
            palindrome = (palindrome * 10) + digit;
            x /= 10;
        }
        return copy == palindrome;
    }
};
```



Very good observation! There are actually **two separate issues** in your code.

---

# Issue 1: Why does a negative number return `true`?

Let's dry run your code.

Suppose

```cpp
x = -121;
```

Initially

```cpp
copy = -121;
palindrome = 0;
```

Now the loop starts.

### First iteration

```cpp
digit = x % 10;
```

In C++,

```cpp
-121 % 10 = -1
```

So

```cpp
digit = -1;
```

Now

```cpp
palindrome = 0 * 10 + (-1);

palindrome = -1;
```

Then

```cpp
x /= 10;
```

```cpp
x = -12;
```

---

### Second iteration

```cpp
digit = -2;

palindrome = -1 * 10 + (-2);

palindrome = -12;
```

---

### Third iteration

```cpp
digit = -1;

palindrome = -12 * 10 + (-1);

palindrome = -121;
```

Now

```cpp
x = 0;
```

Loop ends.

Finally,

```cpp
copy == palindrome

-121 == -121
```

This is

```cpp
true
```

So your program says **palindrome**.

---

## But why does LeetCode say it's wrong?

Because **mathematically**, negative numbers are **not considered palindromes**.

Think about writing it down.

Forward:

```text
-121
```

Reverse:

```text
121-
```

The minus sign moves to the end.

That's not the same.

So the problem statement defines:

```text
All negative numbers → Not Palindrome
```

It is **not because your reversing logic is wrong**.

It is because of the **definition of the problem**.

So simply write

```cpp
if (x < 0)
    return false;
```

at the beginning.

---

# Issue 2: Overflow check

Your overflow check is actually correct.

```cpp
if (palindrome > INT_MAX/10 || ...)
```

There is nothing wrong with it.

But...

**You don't even need it for this problem.**

Why?

Because LeetCode has a much better solution.

Instead of reversing the entire number,

it reverses **only half**.

Then overflow can never happen.

That's why most official solutions don't use these checks.

---

# Issue 3 (Very Important)

Suppose

```cpp
x = 10;
```

Let's dry run.

Reverse

```text
10

↓

1
```

Now

```cpp
copy = 10

palindrome = 1
```

Comparison

```cpp
10 == 1
```

False.

Correct.

---

Suppose

```cpp
x = 0;
```

Your loop

```cpp
while(x != 0)
```

never runs.

So

```cpp
copy = 0

palindrome = 0
```

Comparison

```cpp
0 == 0
```

True.

Also correct.

---

# The only thing missing is

```cpp
if (x < 0)
    return false;
```

---

# Final code

```cpp
class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0)
            return false;

        int copy = x;
        int palindrome = 0;

        while (x != 0) {

            int digit = x % 10;

            if (palindrome > INT_MAX / 10 ||
                (palindrome == INT_MAX / 10 && digit > 7))
                return false;

            if (palindrome < INT_MIN / 10 ||
                (palindrome == INT_MIN / 10 && digit < -8))
                return false;

            palindrome = palindrome * 10 + digit;

            x /= 10;
        }

        return copy == palindrome;
    }
};
```

---

# One question for you 🤔

Suppose I ask you to check whether

```text
123454321
```

is a palindrome.

Do we really need to reverse **all 9 digits**?

Or after reversing the **last 5 digits**, have we already collected enough information to compare the two halves?

That idea is the key to the **optimized LeetCode solution** (reverse only half the number). Once you answer that, the optimized solution becomes much easier to understand.



---
---
---
---
---










Great question. This is exactly where many beginners get confused.

The answer is:

> **We DO need an overflow check if we reverse the entire number.**

Your solution:

```cpp
palindrome = palindrome * 10 + digit;
```

**can overflow**, just like the Reverse Integer problem.

So your check is **correct**.

---

## Then why did I say "you don't need it"?

Because I was talking about the **optimized LeetCode solution**, not your solution.

There are **two different approaches**.

---

# Approach 1 (Your approach)

Reverse the **entire number**.

Example:

```text
12321
```

Reverse all digits

```text
12321
```

Since you're reversing the whole number,

```cpp
palindrome = palindrome * 10 + digit;
```

can become very large.

So **overflow is possible**.

Therefore:

✅ You **need** the overflow check.

---

# Approach 2 (LeetCode's optimized approach)

Reverse **only half** the number.

Example:

```text
12321
```

Original

```text
1 2 3 2 1
```

Instead of reversing everything, we only reverse the last half.

Let's dry run.

Initially

```text
x = 12321
rev = 0
```

Iteration 1

```text
digit = 1

rev = 1

x = 1232
```

Iteration 2

```text
digit = 2

rev = 12

x = 123
```

Iteration 3

```text
digit = 3

rev = 123

x = 12
```

Now stop.

Why?

Because

```text
rev = 123

x = 12
```

Notice

```text
rev >= x
```

That means we've already processed half the digits.

---

Now compare

For odd digits,

```text
x == rev / 10
```

because the middle digit doesn't matter.

```text
12 == 123 / 10

12 == 12

True
```

Palindrome.

---

## Why is there no overflow now?

Look at a huge number.

```text
2147483647
```

It has **10 digits**.

The optimized solution reverses only **5 digits**.

Maximum reversed value becomes

```text
74638
```

Can `74638` overflow an `int`?

Of course not.

It's tiny.

So there's **no need for an overflow check**.

---

# Compare the two approaches

### Your approach

```text
2147483647

↓

7463847412
```

This is huge.

Overflow is possible.

Need overflow check.

---

### Optimized approach

Only reverse half.

```text
2147483647

↓

74638
```

Very small.

Overflow impossible.

No overflow check needed.

---

# So remember this rule

### If you write

```cpp
rev = rev * 10 + digit;
```

until the **entire number** is reversed,

✅ **Need overflow check.**

---

### If you reverse **only half** the digits,

❌ **No overflow check needed.**

---

So your solution is absolutely valid, and your overflow check is logically correct. The optimized LeetCode solution avoids the need for that check by never letting the reversed number grow large enough to overflow.

---

You ended your message with **"and"**, so I think you had another question. Go ahead—what was it?



---
---
---
---
---
---
---




Exactly! 🎯 That's the key idea.

The optimization of **reversing only half** is **specific to the Palindrome Number problem** because of what the problem is asking.

Let's compare the two problems.

---

# Problem 1: Reverse Integer (LeetCode 7)

The question asks:

> **Return the reversed integer.**

Example:

```text
123
```

You **must** return

```text
321
```

There is no shortcut.

You have to build the **entire reversed number**.

```text
12345

↓

5

↓

54

↓

543

↓

5432

↓

54321
```

Since you're building the whole number, it can overflow.

So you **must** check for overflow.

---

# Problem 2: Palindrome Number (LeetCode 9)

The question asks:

> **Is this number a palindrome?**

It does **not** ask you to return the reversed number.

It only wants

```text
true
```

or

```text
false
```

So once you've collected enough information to compare the left and right halves, you can stop.

For example:

```text
12321
```

After reversing half:

```text
Left half      = 12
Reversed right = 123
```

Now compare:

```text
12 == 123 / 10

12 == 12

True
```

You already know the answer.

There is no need to continue reversing.

---

# Think of it like reading a book

Suppose someone asks:

> **"What is the last word of this book?"**

You must read until the end.

That's like **Reverse Integer**.

---

Now suppose someone asks:

> **"Is this book the same from the front and the back?"**

You don't have to read every page.

You compare the first half with the second half.

Once you've compared both halves, you're done.

That's like **Palindrome Number**.

---

# Easy rule to remember

| Problem                                   | Need full reverse? | Overflow check? |
| ----------------------------------------- | ------------------ | --------------- |
| Reverse Integer                           | ✅ Yes              | ✅ Yes           |
| Palindrome Number (full reverse approach) | ✅ Yes              | ✅ Yes           |
| Palindrome Number (half reverse approach) | ❌ No               | ❌ No            |

So yes—the **half-reverse trick is designed specifically for the palindrome problem**. It works because the problem only asks **whether the number is a palindrome**, not for the reversed number itself.

That's why interviewers like this question: they want to see if you can notice that **you don't need to do more work than necessary**.
