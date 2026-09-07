Absolutely. For **your TCS B.Sc Ignite 2026 coding exam**, you do **not** need to learn every advanced matrix algorithm. You need to become very comfortable with **2D arrays/matrices and the common patterns TCS can turn into coding questions**.

TCS officially says the Ignite assessment is **120 minutes**, with Numerical, Verbal, Reasoning, and an **optional Coding** section. ([Tata Consultancy Services][1]) Matrix operations are also listed among the commonly prepared coding topics in current TCS preparation material. ([Scribd][2])

# 🧠 MATRIX — Everything You Need for TCS Ignite

I'll teach this from **absolute basics → exam-level patterns**.

---

# 1. What is a Matrix?

A matrix is simply a **2D array**.

For example:

```text
1  2  3
4  5  6
7  8  9
```

It has:

* **3 rows**
* **3 columns**

We can represent it in C++ as:

```cpp
int a[3][3];
```

Think of it like a table:

```text
       column
       0  1  2
row 0  1  2  3
row 1  4  5  6
row 2  7  8  9
```

So:

```cpp
a[row][column]
```

For example:

```cpp
a[1][2]
```

means:

```text
row = 1
column = 2
```

So the answer is:

```text
6
```

---

# 2. The MOST IMPORTANT thing: Nested Loops

Almost **everything in matrix questions** starts with this:

```cpp
for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
        cout << a[i][j] << " ";
    }
}
```

Understand this deeply.

### Outer loop → rows

```cpp
for(int i = 0; i < rows; i++)
```

### Inner loop → columns

```cpp
for(int j = 0; j < cols; j++)
```

So:

```cpp
a[i][j]
```

means:

> Current row `i`, current column `j`.

---

# 3. Matrix Input

Suppose input is:

```text
3 3
1 2 3
4 5 6
7 8 9
```

Code:

```cpp
int r, c;
cin >> r >> c;

int a[100][100];

for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
        cin >> a[i][j];
    }
}
```

This is **must-know**.

---

# 4. Matrix Output

```cpp
for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
        cout << a[i][j] << " ";
    }
    cout << endl;
}
```

The important part:

```cpp
cout << endl;
```

is **outside the inner loop**.

Why?

Because you want:

```text
1 2 3
4 5 6
7 8 9
```

not:

```text
1
2
3
4
5
6
...
```

---

# 5. Matrix Dimensions

You need to understand these terms:

### Square matrix

Rows = columns.

```text
1 2 3
4 5 6
7 8 9
```

3 × 3.

### Rectangular matrix

Rows ≠ columns.

```text
1 2 3
4 5 6
```

2 × 3.

### Important notation

If:

```text
r = rows
c = columns
```

then:

```text
a[r][c]
```

contains `r × c` elements.

---

# 6. Row Sum

Example:

```text
1 2 3
4 5 6
7 8 9
```

Row sums:

```text
1+2+3 = 6
4+5+6 = 15
7+8+9 = 24
```

Code:

```cpp
for(int i = 0; i < r; i++) {

    int sum = 0;

    for(int j = 0; j < c; j++) {
        sum += a[i][j];
    }

    cout << sum << endl;
}
```

### Pattern

Whenever the question says:

> Find sum of each row

think:

```cpp
fix i
move j
```

---

# 7. Column Sum

Same matrix:

```text
1 2 3
4 5 6
7 8 9
```

Column sums:

```text
1+4+7 = 12
2+5+8 = 15
3+6+9 = 18
```

Code:

```cpp
for(int j = 0; j < c; j++) {

    int sum = 0;

    for(int i = 0; i < r; i++) {
        sum += a[i][j];
    }

    cout << sum << endl;
}
```

Notice the difference.

### Row

```cpp
for(i)
    for(j)
        a[i][j]
```

### Column

```cpp
for(j)
    for(i)
        a[i][j]
```

This distinction is **very important**.

---

# 8. Find Maximum Element

```cpp
int mx = a[0][0];

for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {

        if(a[i][j] > mx) {
            mx = a[i][j];
        }

    }
}

cout << mx;
```

Same concept as finding maximum in a 1D array.

The only difference is that you have **two loops**.

---

# 9. Find Minimum Element

Exactly the same:

```cpp
int mn = a[0][0];

for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {

        if(a[i][j] < mn) {
            mn = a[i][j];
        }

    }
}
```

---

# 10. Count Even/Odd Numbers

```cpp
int even = 0;
int odd = 0;

for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {

        if(a[i][j] % 2 == 0)
            even++;
        else
            odd++;
    }
}
```

This type is very easy and very useful.

---

# 11. Main Diagonal ⭐⭐⭐

For:

```text
1 2 3
4 5 6
7 8 9
```

Main diagonal:

```text
1
   5
      9
```

Positions:

```text
a[0][0]
a[1][1]
a[2][2]
```

Notice:

```text
i == j
```

Therefore:

```cpp
for(int i = 0; i < n; i++) {
    cout << a[i][i] << " ";
}
```

### Main diagonal condition:

```cpp
i == j
```

Remember this forever.

---

# 12. Secondary Diagonal ⭐⭐⭐

Same matrix:

```text
1 2 3
4 5 6
7 8 9
```

Secondary diagonal:

```text
      3
   5
7
```

Positions:

```text
a[0][2]
a[1][1]
a[2][0]
```

Notice:

```text
i + j = n - 1
```

Therefore:

```cpp
for(int i = 0; i < n; i++) {
    cout << a[i][n - 1 - i] << " ";
}
```

### Secondary diagonal:

```cpp
j = n - 1 - i
```

This is one of the **most important matrix formulas for coding exams**.

---

# 13. Sum of Main Diagonal

```cpp
int sum = 0;

for(int i = 0; i < n; i++) {
    sum += a[i][i];
}
```

---

# 14. Sum of Secondary Diagonal

```cpp
int sum = 0;

for(int i = 0; i < n; i++) {
    sum += a[i][n - 1 - i];
}
```

---

# 15. Both Diagonals

For:

```text
1 2 3
4 5 6
7 8 9
```

Main:

```text
1 + 5 + 9 = 15
```

Secondary:

```text
3 + 5 + 7 = 15
```

Code:

```cpp
int mainDiag = 0;
int secondDiag = 0;

for(int i = 0; i < n; i++) {

    mainDiag += a[i][i];

    secondDiag += a[i][n - 1 - i];
}
```

---

# 16. Difference Between Diagonal Sums ⭐

A very common question:

```text
|main diagonal sum - secondary diagonal sum|
```

Code:

```cpp
int d1 = 0;
int d2 = 0;

for(int i = 0; i < n; i++) {

    d1 += a[i][i];

    d2 += a[i][n - 1 - i];
}

cout << abs(d1 - d2);
```

This is exactly the kind of basic matrix logic you should be comfortable with.

---

# 17. Matrix Transpose ⭐⭐⭐

This is **very important**.

Original:

```text
1 2 3
4 5 6
```

Transpose:

```text
1 4
2 5
3 6
```

Rows become columns.

Mathematically:

```text
transpose[i][j] = matrix[j][i]
```

Code:

```cpp
for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {

        transpose[j][i] = a[i][j];

    }
}
```

Notice:

```cpp
[j][i]
```

instead of:

```cpp
[i][j]
```

---

# 18. Transpose of a Square Matrix In-Place

For:

```text
1 2 3
4 5 6
7 8 9
```

we can transpose without another matrix.

```cpp
for(int i = 0; i < n; i++) {

    for(int j = i + 1; j < n; j++) {

        swap(a[i][j], a[j][i]);

    }
}
```

Why `j = i + 1`?

Because we only need to swap one side of the diagonal.

---

# 19. Matrix Addition

Given:

```text
A:

1 2
3 4
```

and:

```text
B:

5 6
7 8
```

Result:

```text
6  8
10 12
```

Formula:

```text
C[i][j] = A[i][j] + B[i][j]
```

Code:

```cpp
for(int i = 0; i < r; i++) {

    for(int j = 0; j < c; j++) {

        C[i][j] = A[i][j] + B[i][j];

    }
}
```

---

# 20. Matrix Subtraction

Same thing:

```cpp
C[i][j] = A[i][j] - B[i][j];
```

---

# 21. Matrix Multiplication ⭐⭐⭐

This is slightly more difficult.

Suppose:

```text
A = 2 × 3
B = 3 × 2
```

You **can multiply** them.

General rule:

```text
A = m × n
B = n × p
```

Result:

```text
C = m × p
```

### The important rule:

> **Inside dimensions must be equal.**

```text
(m × n) × (n × p)

      ↑     ↑
      same
```

---

# 22. Matrix Multiplication Formula

This is the formula:

```text
C[i][j] += A[i][k] * B[k][j]
```

Code:

```cpp
for(int i = 0; i < r1; i++) {

    for(int j = 0; j < c2; j++) {

        C[i][j] = 0;

        for(int k = 0; k < c1; k++) {

            C[i][j] += A[i][k] * B[k][j];

        }
    }
}
```

This gives **O(n³)** for square matrices.

---

# 23. Understand Matrix Multiplication Visually

Suppose:

```text
A:

1 2
3 4
```

and:

```text
B:

5 6
7 8
```

To calculate:

```text
C[0][0]
```

take:

```text
A row 0:

1 2
```

and:

```text
B column 0:

5
7
```

Multiply:

```text
1×5 + 2×7
```

= 19.

So:

```text
C[0][0] = 19
```

This is what:

```cpp
C[i][j] += A[i][k] * B[k][j];
```

is doing.

---

# 24. Matrix Rotation ⭐⭐⭐

This is **very important for coding exams**.

Suppose:

```text
1 2 3
4 5 6
7 8 9
```

Rotate 90° clockwise:

```text
7 4 1
8 5 2
9 6 3
```

The easiest method:

### Step 1 — Transpose

```text
1 4 7
2 5 8
3 6 9
```

### Step 2 — Reverse every row

```text
7 4 1
8 5 2
9 6 3
```

So:

> **90° clockwise = transpose + reverse each row**

---

# 25. C++ Code for 90° Clockwise Rotation

```cpp
// transpose
for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
        swap(a[i][j], a[j][i]);
    }
}

// reverse every row
for(int i = 0; i < n; i++) {
    reverse(a[i], a[i] + n);
}
```

This is a **must-practice pattern**.

---

# 26. 90° Anti-Clockwise Rotation

For:

```text
1 2 3
4 5 6
7 8 9
```

becomes:

```text
3 6 9
2 5 8
1 4 7
```

Easy method:

### Transpose

```text
1 4 7
2 5 8
3 6 9
```

### Reverse the order of rows

```text
3 6 9
2 5 8
1 4 7
```

---

# 27. Spiral Traversal ⭐⭐⭐⭐

This is one of the **most important matrix patterns**.

Given:

```text
1  2  3  4
5  6  7  8
9 10 11 12
13 14 15 16
```

Spiral order:

```text
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
```

You need four boundaries:

```cpp
top
bottom
left
right
```

Initially:

```cpp
top = 0;
bottom = r - 1;
left = 0;
right = c - 1;
```

Then:

### 1. Left → Right

```cpp
for(int j = left; j <= right; j++)
    cout << a[top][j];
```

Then:

```cpp
top++;
```

### 2. Top → Bottom

```cpp
for(int i = top; i <= bottom; i++)
    cout << a[i][right];
```

Then:

```cpp
right--;
```

### 3. Right → Left

```cpp
for(int j = right; j >= left; j--)
    cout << a[bottom][j];
```

Then:

```cpp
bottom--;
```

### 4. Bottom → Top

```cpp
for(int i = bottom; i >= top; i--)
    cout << a[i][left];
```

Then:

```cpp
left++;
```

And repeat while:

```cpp
top <= bottom && left <= right
```

Full code:

```cpp
int top = 0;
int bottom = r - 1;
int left = 0;
int right = c - 1;

while(top <= bottom && left <= right) {

    // left -> right
    for(int j = left; j <= right; j++)
        cout << a[top][j] << " ";

    top++;

    // top -> bottom
    for(int i = top; i <= bottom; i++)
        cout << a[i][right] << " ";

    right--;

    // right -> left
    if(top <= bottom) {
        for(int j = right; j >= left; j--)
            cout << a[bottom][j] << " ";

        bottom--;
    }

    // bottom -> top
    if(left <= right) {
        for(int i = bottom; i >= top; i--)
            cout << a[i][left] << " ";

        left++;
    }
}
```

For TCS, **understand this rather than memorizing blindly**.

---

# 28. Boundary Traversal

Another common problem.

Given:

```text
1 2 3
4 5 6
7 8 9
```

Boundary:

```text
1 2 3 6 9 8 7 4
```

You basically travel around the outside.

This is related to spiral traversal.

---

# 29. Search for an Element

The simplest:

```cpp
int target;
cin >> target;

bool found = false;

for(int i = 0; i < r; i++) {

    for(int j = 0; j < c; j++) {

        if(a[i][j] == target) {
            found = true;
        }

    }
}
```

Or stop immediately:

```cpp
for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {

        if(a[i][j] == target) {
            cout << "Found";
            return 0;
        }

    }
}

cout << "Not Found";
```

---

# 30. Count Frequency in Matrix

Suppose:

```text
1 2 2
3 2 4
5 1 2
```

Count how many times `2` occurs.

```cpp
int count = 0;

for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {

        if(a[i][j] == 2)
            count++;

    }
}
```

You can also use:

```cpp
unordered_map<int,int> freq;
```

for all elements.

---

# 31. Upper Triangle ⭐⭐⭐

For:

```text
1 2 3
4 5 6
7 8 9
```

Upper triangular portion:

```text
1 2 3
  5 6
    9
```

Condition:

```cpp
j >= i
```

Code:

```cpp
for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
        cout << a[i][j] << " ";
    }
}
```

---

# 32. Lower Triangle

```text
1
4 5
7 8 9
```

Condition:

```cpp
i >= j
```

Code:

```cpp
for(int i = 0; i < n; i++) {
    for(int j = 0; j <= i; j++) {
        cout << a[i][j] << " ";
    }
}
```

---

# 33. Diagonal Matrix Thinking

You should memorize these conditions:

| Part                     | Condition      |
| ------------------------ | -------------- |
| Main diagonal            | `i == j`       |
| Above main diagonal      | `j > i`        |
| Below main diagonal      | `i > j`        |
| Secondary diagonal       | `i + j == n-1` |
| Above secondary diagonal | `i + j < n-1`  |
| Below secondary diagonal | `i + j > n-1`  |

This is **extremely useful**.

---

# 34. Identity Matrix ⭐⭐

An identity matrix looks like:

```text
1 0 0
0 1 0
0 0 1
```

Condition:

```cpp
if(i == j)
    cout << 1;
else
    cout << 0;
```

---

# 35. Diagonal Matrix

Example:

```text
5 0 0
0 8 0
0 0 3
```

Only diagonal elements can be non-zero.

So to check whether a matrix is diagonal:

```cpp
bool diagonal = true;

for(int i = 0; i < n; i++) {

    for(int j = 0; j < n; j++) {

        if(i != j && a[i][j] != 0) {
            diagonal = false;
        }

    }
}
```

---

# 36. Symmetric Matrix ⭐⭐⭐

A matrix is symmetric if:

```text
A[i][j] == A[j][i]
```

Example:

```text
1 2 3
2 4 5
3 5 6
```

Notice:

```text
a[0][1] = 2
a[1][0] = 2
```

and so on.

Code:

```cpp
bool symmetric = true;

for(int i = 0; i < n; i++) {

    for(int j = 0; j < n; j++) {

        if(a[i][j] != a[j][i]) {
            symmetric = false;
        }

    }
}
```

---

# 37. Row with Maximum Sum

Suppose:

```text
1 2 3     → 6
9 1 2     → 12
3 4 5     → 12
```

You can track:

```cpp
int maxSum = INT_MIN;
int rowIndex = -1;

for(int i = 0; i < r; i++) {

    int sum = 0;

    for(int j = 0; j < c; j++) {
        sum += a[i][j];
    }

    if(sum > maxSum) {
        maxSum = sum;
        rowIndex = i;
    }
}
```

Very useful pattern.

---

# 38. Column with Maximum Sum

Same idea, just reverse the loops:

```cpp
int maxSum = INT_MIN;
int colIndex = -1;

for(int j = 0; j < c; j++) {

    int sum = 0;

    for(int i = 0; i < r; i++) {
        sum += a[i][j];
    }

    if(sum > maxSum) {
        maxSum = sum;
        colIndex = j;
    }
}
```

---

# 39. Matrix + Direction Movement

This becomes important when questions say:

> Move up/down/left/right.

For an element:

```text
a[i][j]
```

its four neighbors are:

```text
       i-1,j
          ↑
i,j-1 ← a[i][j] → i,j+1
          ↓
       i+1,j
```

So:

```cpp
up    = a[i-1][j];
down  = a[i+1][j];
left  = a[i][j-1];
right = a[i][j+1];
```

But you **must check boundaries**.

For example:

```cpp
if(i > 0)
```

means up exists.

```cpp
if(i < r - 1)
```

means down exists.

```cpp
if(j > 0)
```

means left exists.

```cpp
if(j < c - 1)
```

means right exists.

This is the foundation for more advanced matrix problems.

---

# 40. The Boundary Formula You MUST Know

For matrix:

```text
r × c
```

valid indices are:

```text
row:    0 → r-1
column: 0 → c-1
```

This is incredibly important.

### First row

```cpp
i == 0
```

### Last row

```cpp
i == r - 1
```

### First column

```cpp
j == 0
```

### Last column

```cpp
j == c - 1
```

Memorize these.

---

# 41. Matrix Rotation — Formula Way

For a square matrix, 90° clockwise:

```text
new[i][j] = old[n-1-j][i]
```

90° anti-clockwise:

```text
new[i][j] = old[j][n-1-i]
```

You don't necessarily need to memorize these if you know the transpose method, but understanding them helps.

---

# 42. What Matrix Topics Should YOU Prioritize?

For **TCS Ignite**, I'd rank them like this:

### 🔥 Tier 1 — MUST KNOW

1. 2D array input/output
2. Nested loops
3. Row sum
4. Column sum
5. Maximum/minimum
6. Search element
7. Main diagonal
8. Secondary diagonal
9. Diagonal sum
10. Transpose

### 🔥 Tier 2 — VERY IMPORTANT

11. Matrix addition
12. Matrix subtraction
13. Matrix rotation
14. Boundary traversal
15. Spiral traversal
16. Upper/lower triangle
17. Identity matrix
18. Symmetric matrix
19. Row/column maximum
20. Frequency/counting

### 🟡 Tier 3 — Know the concept

21. Matrix multiplication
22. Neighbor traversal
23. Direction movement
24. Basic grid problems

### 🟢 Tier 4 — Don't spend much time right now

25. DFS/BFS on grids
26. Flood fill
27. Number of islands
28. Shortest path in grid
29. DP on matrices
30. Advanced graph/grid algorithms

Those last topics are useful for advanced coding, but **I would not let them steal your preparation time for the Ignite exam**.

---

# 🧠 The 10 Matrix Patterns I Want You to Memorize

If you're short on time, make these automatic:

```cpp
// 1. Visit every element
for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
```

```cpp
// 2. Main diagonal
a[i][i]
```

```cpp
// 3. Secondary diagonal
a[i][n-1-i]
```

```cpp
// 4. Row sum
sum += a[i][j]
```

```cpp
// 5. Column sum
sum += a[i][j]    // j fixed, i changes
```

```cpp
// 6. Transpose
transpose[j][i] = a[i][j]
```

```cpp
// 7. Upper triangle
j >= i
```

```cpp
// 8. Lower triangle
j <= i
```

```cpp
// 9. Matrix multiplication
C[i][j] += A[i][k] * B[k][j]
```

```cpp
// 10. Rotation
transpose + reverse rows
```

---

# 🚨 The Most Important Concept

Don't think of matrix questions as **30 different topics**.

Almost all beginner/intermediate matrix problems are variations of:

```text
          MATRIX
             │
       ┌─────┴─────┐
       ↓           ↓
    ROWS        COLUMNS
       │           │
       └─────┬─────┘
             ↓
        a[i][j]
             │
    ┌────────┼─────────┐
    ↓        ↓         ↓
 diagonal  boundary  traversal
    │        │         │
    ↓        ↓         ↓
 i==j    i==0       spiral
 i+j=n-1 i=r-1       boundary
          j=0
          j=c-1
```

Once you understand **what `i` and `j` are doing**, matrix questions become much less scary.

And this is especially relevant to your TCS preparation because current TCS Ignite information confirms that the coding component is part of the 120-minute assessment, while TCS's broader coding preparation material repeatedly emphasizes arrays, strings, matrices, loops, searching and sorting. ([Tata Consultancy Services][1])

### Your best order now

Since you're preparing under time pressure, I'd do:

**Arrays → Strings → Matrix → Sorting → Searching → Hashing → Stack/Queue → Recursion → basic DP**

And for **Matrix specifically**, don't just read this. Solve around **15–20 problems**, starting with row/column/diagonal questions and ending with spiral + rotation + matrix multiplication. That will make the patterns stick much faster.

[1]: https://www.tcs.com/careers/india/tcs-bsc-ignite-Hiring?utm_source=chatgpt.com "TCS BSC Ignite Hiring 2026"
[2]: https://www.scribd.com/document/1010490688/TCS-NQT-2026-Complete-Topic-List?utm_source=chatgpt.com "TCS NQT 2026 - Complete Topic List | PDF | Discrete Mathematics | Theoretical Computer Science"
