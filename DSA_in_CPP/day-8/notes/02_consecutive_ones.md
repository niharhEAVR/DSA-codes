## ✅ Problem

> Given a binary array (only 0s and 1s), find the **maximum number of consecutive 1’s**.

Example:

```
nums = {1,0,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0}
```

Expected output:
`6` (because the longest chain of 1s is of length 6)

---

## 🧩 Solution 1 — `conscutiveOnes()` (Your first logic)

### Code

```cpp
void conscutiveOnes(std::vector<int> &nums)
{
    std::vector<int> flags;
    int flag{};
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 1){
            flag++;
        }else{
            flags.push_back(flag);
            flag=0;
        }
        if (i == nums.size()-1)
        {
            flags.push_back(flag);
        }
    }
    std::sort(flags.begin(), flags.end());
    std::cout<<flags[flags.size()-1]<<std::endl;
}
```

---

### 🧠 How it works

1. `flag` counts consecutive 1’s.
2. When a `0` appears → store that count in `flags` vector and reset `flag`.
3. At the end of loop → push the last sequence of 1’s.
4. Then you sort `flags` and print the largest element.

---

### ✅ Output

It will correctly print:

```
6
```

So — **it’s correct.**

---

### ⚠️ But here are the inefficiencies:

| Problem                  | Explanation                                                         |
| ------------------------ | ------------------------------------------------------------------- |
| **Extra vector storage** | You store all run lengths of 1’s in a `flags` vector (unnecessary). |
| **Sorting overhead**     | You sort `flags` just to find the maximum — which is overkill.      |
| **Unnecessary pushes**   | You push `flag` every time you hit a 0 and again at the end.        |

You don’t really need to store or sort anything — you only care about the *maximum count so far*.

---

### ⏱️ Time Complexity

* Counting loop → O(n)
* Sorting the `flags` vector → O(k log k)
  (where `k` = number of 0-blocks + 1)
  In the **worst case** (like all 1s → only one big run),
  O(k log k) ≈ O(n log n)

So total:

> **O(n log n)** (because of sorting)

### 💾 Space Complexity

* Extra vector `flags` storing run lengths

> **O(k)** → in worst case O(n)

---

## ✅ Solution 2 — `conscutiveOnes2()` (Slightly optimal version)

### Code

```cpp
void conscutiveOnes2(std::vector<int> &nums)
{
    int flag{}, maxi{};
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 1){
            flag++;
            maxi = std::max(maxi, flag);
        }else{
            flag=0;
        }
    }
    std::cout<<maxi<<std::endl;
}
```

---

### 🧠 How it works

* You traverse the array once.
* `flag` counts how many 1’s are currently in a row.
* Each time you find a 1, you update `maxi = max(maxi, flag)`.
* When a 0 appears, you reset `flag` to 0.
* At the end, `maxi` holds the longest run.

---

### ✅ Output

For your input:

```
6 ✅
```

---

### ⚙️ Complexity

| Type                 | Value    | Reason                                      |
| -------------------- | -------- | ------------------------------------------- |
| **Time Complexity**  | **O(n)** | Single traversal, constant work per element |
| **Space Complexity** | **O(1)** | Only two integers used                      |

---

### ⚡ Efficiency Comparison

| Aspect           | `conscutiveOnes()`            | `conscutiveOnes2()` |
| ---------------- | ----------------------------- | ------------------- |
| Correctness      | ✅ Correct                     | ✅ Correct           |
| Time Complexity  | ❌ O(n log n) (due to sorting) | ✅ O(n)              |
| Space Complexity | ❌ O(n)                        | ✅ O(1)              |
| Readability      | Moderate                      | Clean & elegant     |
| Efficiency       | Slower                        | **Best possible**   |

---

## 🏆 Final Verdict

| Winner                    | Reason                                                                                                            |
| ------------------------- | ----------------------------------------------------------------------------------------------------------------- |
| ✅ **`conscutiveOnes2()`** | Because it’s a single-pass, O(n)-time, O(1)-space solution. It does not require extra data structures or sorting. |

---

### 💡 Key takeaway

> The most optimal logic in problems like “maximum consecutive 1’s” is usually **single-pass tracking** of the current streak and the maximum streak.
