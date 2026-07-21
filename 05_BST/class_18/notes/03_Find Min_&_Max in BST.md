# 🌳 Core Idea (Don’t memorize, understand this)

👉 In a **Binary Search Tree**:

* **Left = smaller values**
* **Right = larger values**

So:

👉 **Minimum = leftmost node**
👉 **Maximum = rightmost node**

---

# 🔽 Minimum in BST

![Image](https://images.openai.com/static-rsc-4/YrABdRM8PvWD-XlgcGH6m4X80uOzcvCa2IjtaMYko8PS-wKRL1iAB43l_TjybEHh0s44VC7sydIt60t9hipVhaSna3qnYXfeICzISD7jXgZV63cHD71h8Cq6bE6SICmDNyZKGb5ImMqsfx6T9MlyM_j08lNLLsGUx0zcSTJpbmFyEK-iLo0yslFtL3JBRp3r?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/gq8L8xu3S3EUAiWa-cqSYUSIx3Xhm-Ey74bMZruPoNPTvr5q6cXaNSrTfJWz8nJFTQzcj6QBS20DldJa3Ozcs4n8bQX3OngQimVQYlHl3jd058nrPR31csoSDIEB6Hp_ELNHTzYsH2Ni8oipRJYIdjvlA8gOsQvCwjP8DahoYiAZiiztpZJakS3azVZv1Iaf?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/Kl6f6DJ19pbufoemhh0FFMtUGQ4S2tNqLYIIubcX4kmSUKGK5QfUf_oLQ2UcidxlaOyxsVJuqZZPF_nK9QH0z795-MD94P83XyoZF4vYi8O41Sd8Igq1SHe1qrByx-3sMYvWzLjlekqYvXPGbbgD7D3JPR955ucZGwmgsn32ljJ-FE_qGI5GyDVYW0iJRQDY?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/WxeSoLDf8V2VDr-fDJn5OEyl63dVpf45knhHCSM7aOK64957gr2iqHFGb8uGU1QwvmFy6mqsLFYO0uh-OL6yNKLGdPIGMPb-cb0CRD-ToWbUafwhsEIeD4XMd154_NWN5b1Tg4AG-kT4vyHK0_o94U6akLCdxT7WQWZq-LcI5oRHOh1QHoz5tGcS_U2hmVvW?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/70t9XWpFVJsePtaDjdsZqUSA5BfZFfq5KEY2cDHnnsSYPBpwhu0fubchEmJoO2k5kWqKpQYtHU5Pu1M_YZ2Oq1fZOY808tTdwr_Y1GJQjhXxDrHvRbQflSzW4HdYqKbWpVoUAdbcw0LEDNE6M-jLP0mWJ5heIlWemEJpUzBh1khehTzqs7die2VxDjCWAj7-?purpose=fullsize)

### 🧠 Logic:

Keep going **LEFT** until you can’t go anymore.

---

### 💻 Iterative (Best way)

```cpp
TreeNode* findMin(TreeNode* root) {
    if(root == nullptr) return nullptr;

    while(root->left != nullptr) {
        root = root->left;
    }
    return root;
}
```

---

### 🔁 Recursive

```cpp
TreeNode* findMin(TreeNode* root) {
    if(root == nullptr || root->left == nullptr)
        return root;

    return findMin(root->left);
}
```

---

# 🔼 Maximum in BST

![Image](https://images.openai.com/static-rsc-4/PBBDkjMdpnvQzW-UXmr1DAlIUAw1_bNNoIQYsh4vqo_jhuMJE4JTPJfKUxmppJgPl1xcQesR0rCmLfjpdXEgDL_UFZEM6ZlpMTjrurmucVHdLNhx6xQoDOfPpO6bcrfTdjx6r94a0ZrUVJ4TwtyAsmu0-Tennb-7jbEC49Civb4a12a55_t_0COpl4lm_2WG?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/fh-pgOi-FPNH5P9Al0e1xN0-jvkJAbeMFv5VfYJLas3_ehcJgwKKjYX6sPwDpdhc1_w3DWSnyf13-FgUkk_acZ0prtCMeqnl4u2iCfbChpiYZK4s5JE2rOY3Z_xyZ3xYM5DjHWlaCMWbN5WUmtMDPhgLvXHQ2HyZDjTIk7baCP_QNgYpKtQyng5hoyTeqrhI?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/Fc13vj0q47-_aNNve6m1tqc0iX8tQMSf1Aau68F1giXMLmKIrCsI6oR5JUxtQc_MmCn8hUz-PjVodJt3fWZu5eOcvTpgs1r-ed-Hr3zwl7yBLIHXzDwF7gfX21bZqC8bMDE2mDpdJOJD2hwhMtpi-7XdZ6BXJM8Bv_P382WfaW9_TFz2Sw4vP6zFoLrRdEta?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/gq8L8xu3S3EUAiWa-cqSYUSIx3Xhm-Ey74bMZruPoNPTvr5q6cXaNSrTfJWz8nJFTQzcj6QBS20DldJa3Ozcs4n8bQX3OngQimVQYlHl3jd058nrPR31csoSDIEB6Hp_ELNHTzYsH2Ni8oipRJYIdjvlA8gOsQvCwjP8DahoYiAZiiztpZJakS3azVZv1Iaf?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/TyPO0zqAd-V-bWp1Oh7sXr0wM6b8VBpv64HU5GblbQXVOr1-Ugp3_pYV8IlOxL6qhzph_VxRY2IVAtAxd5Yr0bjDuc8-6SbDYY9XUZTDZ_iIKYFC5fNhBSpRvZpYiwry0dwAF8Vat-_NtXtJYPvZfP0cGv4iJJllU6fsDLkeQhqw3jH0Qx-vEjF6IF-zcR59?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/IyFB3TaP4FlGPT7aw4oziuQ6gIoOMkZTEA6wSt_z3NYeMLXffn7oCOBjiWSz8PQOgNir4sVOqzs_ud0saSXytpIkanHP5_Mk3XlDsaPkUuebiQPwUUZYKdvYfcNIqOAJcsRW6RlDNs8hAsA4rMgFU0tOW_SO8dFhXjEeSSs6GSpWPqEB06d6uNMEUbs0U6Ju?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/jI8r9BMz6RcCEFq1Izc1AWPlH58ML_EaYBfCX5JOoNZhg7XTQAxCLhTPTeizPbb86sxkrSZl1OaGWgVzaP6r2m_e0Ll4hPEq0TVi39NrL3cZrVMd0txglyFMnf6w34-4YKp-saCXU2BXq3qTwIj2ZUSGymSZhoGmw-kDG-_USkiArtc0w-s1wsw_L8G0gH3X?purpose=fullsize)

### 🧠 Logic:

Keep going **RIGHT** until you can’t go anymore.

---

### 💻 Iterative

```cpp
TreeNode* findMax(TreeNode* root) {
    if(root == nullptr) return nullptr;

    while(root->right != nullptr) {
        root = root->right;
    }
    return root;
}
```

---

### 🔁 Recursive

```cpp
TreeNode* findMax(TreeNode* root) {
    if(root == nullptr || root->right == nullptr)
        return root;

    return findMax(root->right);
}
```

---

# ⏱ Time Complexity

[
O(h)
]

* `h = height of tree`

### Cases:

* Balanced BST → **O(log n)** ✅
* Skewed BST → **O(n)** ❌

---

# 💾 Space Complexity

| Approach  | Space |
| --------- | ----- |
| Iterative | O(1)  |
| Recursive | O(h)  |

---

# ⚠️ Common Mistake

❌ Trying to traverse whole tree
👉 Not needed at all

BST already gives you a **shortcut path**

---

# 🧠 One-Line Intuition

> Minimum = “keep going left”
> Maximum = “keep going right”

---

# 🔥 Interview Twist (Important)

👉 These functions are heavily used in:

* **Deletion in BST**

  * Finding **inorder successor** (min in right subtree)
  * Finding **inorder predecessor** (max in left subtree)
