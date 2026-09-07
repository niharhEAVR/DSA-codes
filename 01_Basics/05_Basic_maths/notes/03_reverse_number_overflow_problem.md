This is an **excellent question**. Your **logic is 100% correct**.

The problem is **not your algorithm**.

The problem is **the data type (`int`)**.

Let's understand it step by step.

---

# Your code

```cpp
int rev{};

while(x != 0)
{
    rev *= 10;
    rev += x % 10;
    x /= 10;
}
```

This correctly reverses the number.

But suppose the input is

```text
1534236469
```

Let's reverse it.

```text
9646324351
```

Look carefully.

Original

```text
1534236469
```

Reversed

```text
9646324351
```

This number has **10 digits**.

---

# But how big can an `int` store?

In C++,

```cpp
int
```

usually stores values from

```text
-2,147,483,648

to

2,147,483,647
```

So the **maximum** positive `int` is

```text
2147483647
```

---

Now compare

Your answer

```text
9646324351
```

Maximum int

```text
2147483647
```

Clearly,

```text
9646324351 > 2147483647
```

So it **doesn't fit** inside an `int`.

This is called **integer overflow**.

---

# What exactly happened?

Suppose at some point

```cpp
rev = 964632435;
```

Now your code does

```cpp
rev *= 10;
```

which becomes

```text
964632435 × 10

=

9646324350
```

Can an `int` store

```text
9646324350 ?
```

No.

Maximum is

```text
2147483647
```

So the multiplication itself overflows.

That's exactly what the error says:

```text
964632435 * 10
```

cannot fit in an `int`.

---

# Why does the error happen **before** adding the digit?

Your code is

```cpp
rev *= 10;
```

Overflow already happens here.

The next line

```cpp
rev += digit;
```

never gets a valid value.

---

# How do we avoid it?

Before multiplying, ask yourself:

> **"Will multiplying by 10 exceed the maximum int?"**

---

## Maximum int

```text
2147483647
```

If

```text
rev > 214748364
```

then

```text
rev × 10
```

will definitely overflow.

Example

```text
214748365 ×10

=

2147483650
```

Already too large.

---

# But there is one more case

Suppose

```text
rev = 214748364
```

Multiplying gives

```text
2147483640
```

Still okay.

Now suppose the next digit is

```text
8
```

Then

```text
2147483640+8

=

2147483648
```

Overflow again.

So we need another condition.

---

# Therefore the safe condition becomes

```cpp
if(rev > INT_MAX / 10)
```

Overflow.

OR

```cpp
if(rev == INT_MAX/10 && digit > 7)
```

Overflow.

Why 7?

Because

```text
INT_MAX

=

2147483647
```

Last digit is

```text
7
```

---

Similarly for negative numbers,

Minimum int

```text
-2147483648
```

Last digit

```text
8
```

---

# The standard solution

```cpp
class Solution {
public:
    int reverse(int x) {

        int rev = 0;

        while(x != 0)
        {
            int digit = x % 10;

            if(rev > INT_MAX/10 || (rev == INT_MAX/10 && digit > 7))
                return 0;

            if(rev < INT_MIN/10 || (rev == INT_MIN/10 && digit < -8))
                return 0;

            rev = rev * 10 + digit;

            x /= 10;
        }

        return rev;
    }
};
```

This is the solution expected in interviews and on LeetCode.

---

# Why not use `long long`?

You might think:

```cpp
long long rev = 0;
```

Then no overflow!

But the problem specifically asks:

> Return **0** if the reversed number cannot be represented as a **32-bit signed integer**.

If you use `long long`, you can compute the reversed value safely, but before returning it you'd still need to check whether it fits in the `int` range.

---

# How can you avoid these mistakes in the future?

Whenever you see code like

```cpp
a = a * something;
```

or

```cpp
a = a + something;
```

ask yourself these three questions:

1. **What is the maximum value of `a`?**
2. **Can multiplying or adding make it exceed the data type's limit?**
3. **Should I check before performing the operation?**

This habit will help you avoid overflow bugs in many problems.

---

## One more important thing

You wrote:

```cpp
rev *= 10;
rev += x % 10;
```

Most people write:

```cpp
rev = rev * 10 + digit;
```

Both are mathematically equivalent.

The second version is generally preferred because:

* it's one expression,
* it's easier to read,
* and it makes it natural to perform the overflow check **before** the calculation.

Your logic is correct—the only issue was that the intermediate multiplication produced a value that an `int` could not represent.




---
---
---
---
---
---
---




Absolutely. Let's forget `INT_MAX`, overflow checks, and everything else for a moment.

I'll explain it the way I'd explain it to someone who's just started programming.

---

# Imagine you have a small bottle

Suppose your bottle can hold **only 20 liters**.

Right now it has

```text
18 liters
```

Now someone says:

> "Add 5 liters."

Can you do it?

No.

Because

```text
18 + 5 = 23 liters
```

But the bottle can hold only

```text
20 liters
```

So what should you do?

You **check first**.

```text
Current = 18

Maximum = 20

Want to add 5

Will it become more than 20?

YES

Don't add it.
```

Notice something?

You **didn't** add the water.

You checked **before** adding it.

---

# The same thing happens with `int`

An `int` is like that bottle.

It can only hold numbers up to

```text
2147483647
```

---

# Your code

```cpp
rev = rev * 10 + digit;
```

Suppose

```text
rev = 214748364
digit = 8
```

Now C++ is about to do

```text
214748364 × 10 + 8
```

which becomes

```text
2147483648
```

But the bottle (`int`) can hold only

```text
2147483647
```

Oops!

Too big.

Overflow.

---

# So what should we do?

Instead of doing

```text
Multiply

↓

Overflow

↓

Oops
```

we do

```text
Check

↓

Safe?

↓

Yes → Multiply

No → Stop
```

---

# Now let's understand the check

Maximum number

```text
2147483647
```

Forget the last digit for a second.

Look only at this:

```text
214748364
```

This is

```cpp
INT_MAX / 10
```

because

```text
2147483647 / 10

=

214748364
```

(integer division)

---

Now imagine your `rev` is

```text
214748365
```

Can you multiply it by 10?

Let's try.

```text
214748365 × 10

=

2147483650
```

Look carefully.

Maximum allowed

```text
2147483647
```

Your answer

```text
2147483650
```

Already too big.

So we don't even multiply.

We simply say

> "No, this won't fit."

---

# Another example

Suppose

```text
rev = 100
```

Multiply by 10

```text
1000
```

Safe?

Yes.

Then do it.

---

# One last example

Suppose

```text
rev = 214748364
```

Multiply

```text
2147483640
```

Still okay.

Now we add the last digit.

If digit is

```text
5
```

Result

```text
2147483645
```

Safe.

---

If digit is

```text
8
```

Result

```text
2147483648
```

Too big.

Don't do it.

---

# That's why there are **two checks**

### Check 1

```cpp
if (rev > INT_MAX / 10)
```

Means:

> Even multiplying by 10 is too dangerous.

---

### Check 2

```cpp
if (rev == INT_MAX / 10 && digit > 7)
```

Means:

> Multiplication is okay, but adding this digit is too much.

---

# Think of it like building a number

Suppose you've already built

```text
214748364
```

Now you're about to attach one more digit.

```
214748364_
```

What digits can you safely put?

```
0 ✅
1 ✅
2 ✅
3 ✅
4 ✅
5 ✅
6 ✅
7 ✅
8 ❌
9 ❌
```

Why?

Because the biggest valid `int` is

```text
2147483647
```

So the last digit can be at most **7**.

---

## I have one question for you.

Suppose

```text
rev = 214748365
```

Before multiplying, answer this:

```
214748365 × 10 = ?
```

Can that number fit inside

```text
2147483647
```

Just answer **Yes** or **No**.

Once you answer that, I think the whole idea will click.



---
---
---
---
---
---
---
---




Awesome! You're **90% there**. You already understand **why** we need to check. Now let's understand **what each check does**.

We'll ignore C++ for a minute and just think logically.

---

# Maximum `int`

```text
2147483647
```

This is the **largest number** we are allowed to make.

---

# While reversing

Every time we do

```cpp
rev = rev * 10 + digit;
```

Suppose we already have

```text
214748364
```

Now we are about to add **one more digit**.

Like this:

```text
214748364_
```

The `_` is the new digit.

Question:

**What digits are allowed?**

```
2147483640 ✅
2147483641 ✅
2147483642 ✅
2147483643 ✅
2147483644 ✅
2147483645 ✅
2147483646 ✅
2147483647 ✅
2147483648 ❌
2147483649 ❌
```

Notice something?

Only

```text
0 to 7
```

are allowed.

That's why we have the **second check**.

```cpp
if(rev == INT_MAX/10 && digit > 7)
```

Let's read it in English.

> **If I've already reached `214748364`, then the next digit cannot be greater than `7`.**

That's all it means.

---

# Now let's understand the first check

Suppose

```text
rev = 214748365
```

Notice carefully.

It is already **bigger than**

```text
214748364
```

Now let's multiply it.

```text
214748365 × 10

=

2147483650
```

Can it ever fit?

```
2147483650
2147483651
2147483652
...
2147483659
```

Every possible answer is already greater than

```text
2147483647
```

So there is **no point checking the last digit**.

It is already impossible.

That's why we have the first check.

```cpp
if(rev > INT_MAX/10)
```

Read it in English:

> **If the number before multiplying is already larger than `214748364`, then multiplying by 10 will definitely overflow. Stop immediately.**

---

# Why do we need BOTH checks?

Because there are **two different situations**.

---

## Situation 1

```text
rev = 214748365
```

This is already too large.

The digit doesn't matter.

```
+0 ❌
+1 ❌
+2 ❌
...
+9 ❌
```

So we use

```cpp
if(rev > INT_MAX/10)
```

---

## Situation 2

```text
rev = 214748364
```

Now the digit **does matter**.

```
+0 ✅
+1 ✅
+2 ✅
...
+7 ✅
+8 ❌
+9 ❌
```

So we use

```cpp
if(rev == INT_MAX/10 && digit > 7)
```

---

# Think of it like this

Imagine you're trying to build the largest allowed number.

```
214748364_
```

There are two possibilities.

### Case 1

You've already gone too far.

```
214748365_
```

No matter what digit you put,

```
2147483650
2147483651
...
2147483659
```

All are invalid.

---

### Case 2

You're exactly at the limit before the last digit.

```
214748364_
```

Now you must carefully choose the last digit.

```
0-7 ✅

8-9 ❌
```

---

# Let's trace a real example

Suppose

```cpp
rev = 214748364;
digit = 6;
```

### Check 1

```cpp
rev > INT_MAX/10
```

```
214748364 > 214748364

False
```

Continue.

---

### Check 2

```cpp
rev == INT_MAX/10
```

```
True
```

Now check

```cpp
digit > 7
```

```
6 > 7

False
```

Safe.

Now calculate

```
214748364 × 10 + 6

=

2147483646
```

Correct.

---

Now change

```cpp
digit = 9;
```

Check 1

```
False
```

Check 2

```
9 > 7

True
```

Return `0`.

---

## Here's the easiest way to remember it

```
rev > INT_MAX/10
```

👉 **"I'm already too big."**

```
rev == INT_MAX/10 && digit > 7
```

👉 **"I'm exactly at the limit, and this next digit pushes me over."**

---

### Quick challenge (just two questions)

1. If `rev = 214748366`, **which check** will catch the overflow?

   * A) First check
   * B) Second check

2. If `rev = 214748364` and `digit = 8`, **which check** will catch it?

   * A) First check
   * B) Second check

Answer with something like **"1-A, 2-B"**. If you get that right, you've completely understood how these checks work.
