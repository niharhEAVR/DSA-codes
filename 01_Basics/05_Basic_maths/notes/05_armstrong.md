Yes. More important than memorizing the Armstrong Number algorithm is understanding **how to think about digit problems**, because many LeetCode problems follow the same pattern.

---

# What is an Armstrong Number?

An **Armstrong number** (also called a **Narcissistic number**) is a number that is equal to the **sum of each digit raised to the power of the number of digits**.

### Example 1

153

It has **3 digits**.

So,

[
1^3 + 5^3 + 3^3
]

= 1 + 125 + 27

= 153 ✅

So it is an Armstrong number.

---

### Example 2

9474

It has **4 digits**

[
9^4+4^4+7^4+4^4
]

= 6561 + 256 + 2401 + 256

= 9474 ✅

---

# How to think while solving

Whenever a number problem says

* each digit
* reverse number
* sum of digits
* palindrome
* Armstrong
* count digits

your brain should immediately think

> "I need to extract every digit."

And in C++, digits are extracted using

```cpp
digit = n % 10;
n /= 10;
```

This is the foundation of many problems.

---

# Step 1: Count digits

Before calculating powers, you need to know how many digits exist.

Example

```
153
```

Digits = 3

One simple way:

```cpp
temp = n;

while(temp > 0)
{
    count++;
    temp /= 10;
}
```

---

# Step 2: Extract every digit

Again use

```cpp
digit = temp % 10;
temp /= 10;
```

For 153

Iteration 1

```
digit = 3
```

Iteration 2

```
digit = 5
```

Iteration 3

```
digit = 1
```

---

# Step 3

Raise every digit to the power of count.

```
sum += digit^count
```

Finally compare

```
sum == originalNumber
```

If true

Return true

Otherwise false.

---

# Time Complexity

Counting digits

```
O(d)
```

Processing digits

```
O(d)
```

Overall

```
O(d)
```

where d is the number of digits.

For an `int`, that's at most 10 digits, so it's effectively constant time.

---

# Edge cases (very important for LeetCode)

These are where many wrong answers come from.

---

## Edge Case 1

### Number = 0

Many beginners write

```cpp
while(temp > 0)
```

For

```
0
```

the loop never runs.

Digit count becomes

```
0
```

which is wrong.

Actually

```
0
```

has **1 digit**.

So handle it separately:

```cpp
if(n == 0)
    return true;
```

or initialize the digit count appropriately.

---

## Edge Case 2

### Negative numbers

Example

```
-153
```

Normally Armstrong numbers are defined only for **non-negative integers**.

So

```cpp
if(n < 0)
    return false;
```

---

## Edge Case 3

### Overflow while calculating powers

Suppose

```
2147483647
```

Each digit is raised to the 10th power.

The accumulated sum can exceed a 32-bit `int`.

Use a larger type:

```cpp
long long sum = 0;
```

or even wider if constraints require it.

---

## Edge Case 4

### Using `pow()`

Many people write

```cpp
sum += pow(digit, count);
```

Problem:

`pow()` returns a `double`.

Sometimes

```
pow(9,10)
```

can produce a floating-point value that needs rounding before converting to an integer.

A safer approach is to compute integer powers yourself.

Example:

```cpp
int power(int base, int exp)
{
    int ans = 1;

    while(exp--)
        ans *= base;

    return ans;
}
```

Then

```cpp
sum += power(digit, count);
```

This avoids floating-point precision issues.

---

## Edge Case 5

### Losing the original number

Many beginners do

```cpp
while(n > 0)
{
    ...
    n /= 10;
}
```

At the end

```
n == 0
```

Then

```cpp
return sum == n;
```

This always compares with 0.

Always store

```cpp
original = n;
```

before modifying it.

---

## Edge Case 6

### Single-digit numbers

```
5
```

Digits = 1

[
5^1 = 5
]

So every single-digit number (`0` through `9`) is an Armstrong number.

Your algorithm should naturally return `true` for them.

---

# Common mistakes

❌ Forgetting to copy the original number.

❌ Not handling 0.

❌ Using `pow()` carelessly.

❌ Using `int` when the sum may overflow.

❌ Comparing with the modified number instead of the original.

---

# Interview thought process

When you see an Armstrong Number problem, think in this order:

1. Store the original number.
2. Reject negative numbers (if applicable).
3. Count the number of digits.
4. Extract each digit using `% 10`.
5. Raise the digit to the digit count.
6. Add to the sum.
7. Compare the sum with the original number.

---

## LeetCode-style template for digit problems

Many digit-based questions follow this pattern:

```cpp
int original = n;
int temp = n;

while (temp > 0)
{
    int digit = temp % 10;

    // Do something with digit

    temp /= 10;
}
```

The only thing that changes is what you do with `digit`:

* Sum of digits → `sum += digit`
* Reverse number → `rev = rev * 10 + digit`
* Count digits → `count++`
* Armstrong → `sum += digit^count`
* Palindrome → Build the reversed number and compare it with the original

If you become comfortable with this pattern, you'll be able to solve a large class of number-manipulation problems on LeetCode.
