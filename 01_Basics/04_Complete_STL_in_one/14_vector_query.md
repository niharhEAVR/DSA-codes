This is one of the most common misconceptions about `emplace_back()`. The answer is:

> **`emplace_back()` does NOT always avoid copying.** It only avoids creating a temporary object **when you construct the object directly inside the vector**.

Let's understand this deeply.

---

# Case 1: Primitive types (`int`, `char`, `double`)

```cpp
std::vector<int> v;

v.push_back(10);
v.emplace_back(10);
```

Both do almost exactly the same thing.

There is essentially **no performance difference**.

So for primitive types, most people simply use `push_back()`.

---

# Case 2: User-defined class

Suppose

```cpp
class Student {
public:
    std::string name;
    int age;

    Student(std::string n, int a)
        : name(n), age(a)
    {
        std::cout << "Constructor\n";
    }

    Student(const Student&) {
        std::cout << "Copy Constructor\n";
    }

    Student(Student&&) {
        std::cout << "Move Constructor\n";
    }
};
```

---

## Using push_back()

```cpp
v.push_back(Student("Nihar", 21));
```

What happens?

### Step 1

Creates a temporary object

```
Student("Nihar",21)
```

↓

```
Temporary Student
```

### Step 2

Moves it into the vector

```
Vector
```

So

```
Constructor
Move Constructor
```

---

## Using emplace_back()

```cpp
v.emplace_back("Nihar",21);
```

Now there is **no temporary Student**.

The vector directly calls

```cpp
Student("Nihar",21);
```

inside its memory.

So output is

```
Constructor
```

No copy.

No move.

---

# But what if you already have an object?

```cpp
Student s("Nihar",21);

v.push_back(s);
```

Copy.

Now

```cpp
v.emplace_back(s);
```

Still copy!

Why?

Because `s` already exists.

The vector has to copy it.

So

```
push_back(s)
```

and

```
emplace_back(s)
```

behave almost the same.

---

# Similarly

```cpp
Student s("Nihar",21);

v.push_back(std::move(s));
```

Move.

```cpp
v.emplace_back(std::move(s));
```

Also move.

Again, no difference.

---

# So when is emplace_back() actually useful?

Only when you're passing **constructor arguments**, not an already-created object.

Good:

```cpp
v.emplace_back("Nihar",21);
```

Not useful:

```cpp
Student s("Nihar",21);

v.emplace_back(s);
```

---

# Then why do people still use push_back()?

Because it expresses the intent more clearly.

Suppose you already have an object.

```cpp
Student s("Nihar",21);

v.push_back(s);
```

This clearly says:

> "Push this object."

Whereas

```cpp
v.emplace_back(s);
```

looks like you are constructing something, but you're not. You're just copying `s`.

Many C++ programmers prefer `push_back()` here because it's more readable.

---

# Is there any drawback to emplace_back()?

Yes.

### 1. It can accidentally call the wrong constructor.

Suppose

```cpp
class Test {
public:
    Test(int);
    Test(int, int);
};
```

Now

```cpp
v.emplace_back(5, 6);
```

calls the two-argument constructor.

Someone reading the code must know which constructor matches those arguments.

With

```cpp
v.push_back(Test(5,6));
```

it's much more explicit that you're creating a `Test` object first and then inserting it.

---

### 2. It isn't always faster.

Many beginners think:

```
emplace_back() = always faster
```

This is **false**.

If the object already exists:

```cpp
Student s("Nihar",21);

v.emplace_back(s);
```

there is no performance benefit.

---

### 3. Reallocation still happens.

Even with `emplace_back()`:

```cpp
v.emplace_back(...);
```

if

```cpp
size == capacity
```

the vector must allocate new memory and move (or copy) all existing elements.

`emplace_back()` only avoids creating a temporary for the **new element**. It does **not** prevent the vector from relocating its existing elements when it grows.

---

# Rule of thumb (used by many C++ developers)

| Situation                                    | Preferred                                          |
| -------------------------------------------- | -------------------------------------------------- |
| You already have an object                   | ✅ `push_back(obj)`                                 |
| You already have an rvalue                   | ✅ `push_back(std::move(obj))`                      |
| You want to construct directly in the vector | ✅ `emplace_back(args...)`                          |
| Primitive types (`int`, `double`)            | Either; `push_back()` is often used for simplicity |

### The simple way to remember it

* **`push_back()`** → *"I already have an object. Please insert it."*
* **`emplace_back()`** → *"I don't have the object yet. Here are the constructor arguments—build it directly inside the vector."*

That's why you'll still see `push_back()` used very frequently in professional C++ code. `emplace_back()` is a powerful optimization, but it's only beneficial in the specific case where it can construct the object in place.
