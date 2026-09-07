Perfect! This is the next logical topic because it uses the **same concept** you just learned: **divide by 10**.

Let's learn it from **basic mathematics**, not by memorizing code.

---

# Problem

Suppose

```text
12345
```

We want

```text
54321
```

How can we do that?

---

# Step 1: How do we get the last digit?

Suppose

```text
12345
```

How do we get **5**?

We use the **modulus operator (`%`)**.

```cpp
12345 % 10
```

Result

```text
5
```

Why?

Because

```text
12345 ÷ 10

Quotient = 1234

Remainder = 5
```

The `%` operator gives the **remainder**.

So

```cpp
lastDigit = n % 10;
```

---

## More Examples

```cpp
987 % 10 = 7
```

```cpp
456 % 10 = 6
```

```cpp
83 % 10 = 3
```

Notice the pattern?

```text
n % 10

always gives

the last digit
```

---

# Step 2: Remove the last digit

We already learned this.

```cpp
12345 / 10
```

Result

```text
1234
```

because integer division removes the decimal part.

So

```cpp
n = n / 10;
```

removes the last digit.

---

Now we know two important operations.

```text
n % 10

↓

Get last digit
```

```text
n / 10

↓

Remove last digit
```

---

# Step 3: Build the reversed number

Suppose

```text
12345
```

Initially

```text
reverse = 0
```

---

### First iteration

Current number

```text
12345
```

Last digit

```cpp
12345 % 10 = 5
```

Now

```text
reverse = 5
```

Remove last digit

```text
1234
```

---

### Second iteration

Current

```text
1234
```

Last digit

```text
4
```

Now here's the important question.

We already have

```text
5
```

How do we make

```text
54
```

Can we simply do

```cpp
reverse = reverse + digit;
```

?

Let's see.

```text
5 + 4 = 9 ❌
```

Wrong.

---

# The trick

Suppose we have

```text
5
```

How do we convert it into

```text
50
```

Multiply by 10.

```text
5 × 10 = 50
```

Now add

```text
4
```

Result

```text
54
```

So

```cpp
reverse = reverse * 10 + digit;
```

This is the most important line.

---

# Continue

Current reverse

```text
54
```

Next digit

```text
3
```

Multiply

```text
54 ×10 =540
```

Add

```text
3
```

Result

```text
543
```

---

Again

```text
543 ×10 =5430

+2

=5432
```

Again

```text
5432 ×10 =54320

+1

=54321
```

Finished.

---

# Complete Dry Run

Start

```text
n =12345

reverse =0
```

| n     | digit (`n%10`) | reverse         |
| ----- | -------------- | --------------- |
| 12345 | 5              | 0×10+5=5        |
| 1234  | 4              | 5×10+4=54       |
| 123   | 3              | 54×10+3=543     |
| 12    | 2              | 543×10+2=5432   |
| 1     | 1              | 5432×10+1=54321 |
| 0     | -              | Stop            |

Answer

```text
54321
```

---

# Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n = 12345;
    int reverse = 0;

    while(n > 0)
    {
        int digit = n % 10;

        reverse = reverse * 10 + digit;

        n = n / 10;
    }

    cout << reverse;
}
```

Output

```text
54321
```

---

# Why do we multiply by 10?

This is where many beginners get confused.

Suppose

```text
reverse = 87
```

The next digit is

```text
6
```

You want

```text
876
```

First, make space for one more digit:

```text
87 × 10 = 870
```

Now put the new digit in the empty ones place:

```text
870 + 6 = 876
```

So every iteration is:

```text
Old reverse
      ↓
Multiply by 10
      ↓
Add the new last digit
```

---

# Time Complexity

There is one loop that runs once per digit.

If the number has `d` digits:

* **Time:** `O(d)`
* **Space:** `O(1)`

---

# Common Interview Questions

### Reverse `1200`

```text
1200
```

Process

```text
0
0
2
1
```

Answer

```text
21
```

Leading zeros disappear because integers don't store them.

---

### Reverse `0`

```text
0
```

Output

```text
0
```

---

### Reverse `-123`

One simple approach is:

```cpp
bool negative = (n < 0);
n = abs(n);

// Reverse the number

if (negative)
    reverse = -reverse;
```

---

## Remember these two golden operations

| Operation        | Meaning               |
| ---------------- | --------------------- |
| `digit = n % 10` | Get the last digit    |
| `n = n / 10`     | Remove the last digit |

These two operations are the foundation for many number-based problems, including:

* Reverse a number
* Palindrome number
* Sum of digits
* Armstrong number
* Count digits
* Product of digits

If you master these, you'll find the rest much easier.
