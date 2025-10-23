```cpp

#include <bits/stdc++.h>

#include <iostream>

void traverse(std::vector<int> &arr)
{
    std::cout << "[ ";
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << (i + 1 == arr.size() ? "" : ", ");
    std::cout << " ]";
}

// optimal approach (we have to sort it first)
std::vector<int> intersecF(std::vector<int> &nums, std::vector<int> &nums2)
{
    std::sort(nums.begin(), nums.end());
    std::sort(nums2.begin(), nums2.end());
    int i{}, j{};
    std::vector<int> vis[nums2.size()]{};

    std::vector<int> ans;

    for (size_t i = 0; i < nums.size(); i++)
    {
        for (size_t j = 0; j < nums2.size(); j++)
        {
            if (nums[i] == nums2[j] && vis[j] == 0)
            {

                ans.add(nums[i]);
                vis[j] = 1;
                break;
            }
            if (nums2[j] > nums[i])
                break;
        }
    }

    traverse(ans, ans.size());
    return ans;
}

int main()
{

    std::vector<int> nums = {0, 1, 0, 3, 12};
    std::vector<int> nums2 = {0, 5, 6, 2, 3, 1, 18};

    intersecF(nums, nums2);
    return 0;
}
```


## 🧩 Issues in Your Code

1. ❌ `std::vector<int> vis[nums2.size()]{};`
   → This creates an **array of vectors**, not a vector of integers.
   ✅ Should be:

   ```cpp
   std::vector<int> vis(nums2.size(), 0);
   ```

2. ❌ `ans.add(nums[i]);`
   → `std::vector` doesn’t have `add()`.
   ✅ Use `ans.push_back(nums[i]);`

3. ❌ The **double `for` loop** (nested) is O(n × m) —
   → That’s **not optimal**.
   ✅ Use **two pointers** instead for O(n + m).

---

## ✅ Fixed & Optimal Code (for Intersection)

```cpp
#include <bits/stdc++.h>
using namespace std;

void traverse(vector<int> &arr)
{
    cout << "[ ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << (i + 1 == arr.size() ? "" : ", ");
    cout << " ]";
}

vector<int> intersecF(vector<int> &nums, vector<int> &nums2)
{
    sort(nums.begin(), nums.end());
    sort(nums2.begin(), nums2.end());

    int i = 0, j = 0;
    vector<int> ans;

    while (i < nums.size() && j < nums2.size())
    {
        if (nums[i] == nums2[j])
        {
            // Avoid duplicates in answer
            if (ans.empty() || ans.back() != nums[i])
                ans.push_back(nums[i]);
            i++;
            j++;
        }
        else if (nums[i] < nums2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    traverse(ans);
    return ans;
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    vector<int> nums2 = {0, 5, 6, 2, 3, 1, 18};

    intersecF(nums, nums2);
    return 0;
}
```

---

## 🧠 Explanation

### Step 1 — Sort both arrays

Sorting helps align elements, so we can move in a single pass.

### Step 2 — Use two pointers (`i` and `j`)

* If `nums[i] < nums2[j]` → increment `i`
* If `nums[i] > nums2[j]` → increment `j`
* If equal → push to `ans`, and move both

### Step 3 — Skip duplicates in `ans`

By checking `if (ans.empty() || ans.back() != nums[i])`

---

## 🧮 Time and Space Complexity

| Type       | Complexity                    | Explanation                |
| ---------- | ----------------------------- | -------------------------- |
| **Time**   | O(n log n + m log m)          | Sorting both arrays        |
|            | + O(n + m)                    | Merging (two-pointer scan) |
| **Total:** | **O(n log n + m log m)**      | ✅                          |
| **Space**  | O(1) extra (excluding output) | ✅ No extra containers      |

---

## 🧪 Example Output

For:

```cpp
nums = {0, 1, 0, 3, 12}
nums2 = {0, 5, 6, 2, 3, 1, 18}
```

After sorting:

```
nums  = [0, 0, 1, 3, 12]
nums2 = [0, 1, 2, 3, 5, 6, 18]
```

✅ Intersection → `[0, 1, 3]`
