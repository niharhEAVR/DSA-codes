Let’s break down **“Best Time to Buy and Sell Stock”** —
and why it’s considered a **DP (Dynamic Programming) on Stocks** problem.

---

## 🧩 The Problem (in plain words)

You’re given an array `prices[]` where
`prices[i]` = the price of a stock on day `i`.

You can:

* **Buy** the stock once (on one day)
* **Sell** it later (on another day after you buy)

Your goal: **maximize your profit**

So you want to find the best days `buyDay` and `sellDay` such that
`profit = prices[sellDay] - prices[buyDay]` is maximum
(and `sellDay > buyDay`).

---

## 💡 What makes it a *Dynamic Programming* idea?

Dynamic Programming (DP) is about:

> **Breaking a problem into subproblems**, solving each once, and reusing previous results to build the next.

Even though this problem can be solved in one pass, the idea is **fundamentally DP** —
because at every day, you’re making a decision based on **previous optimal information**.

Let’s understand this step by step.

---

## 🧠 The Core Thinking Process

You move through the days one by one:

### 🏦 You want to know two things at each day `i`:

1. **The minimum price so far** (best day to buy till now)
2. **The best profit if I sell today**

Then you update your answer.

---

### 💬 Day-by-day reasoning

Imagine walking through the prices one by one.

Let’s say prices = `[7, 1, 5, 3, 6, 4]`.

* On Day 0: price = 7 → you can’t sell yet → minPrice = 7
* On Day 1: price = 1 → cheaper → update minPrice = 1
* On Day 2: price = 5 → profit = 5 - 1 = 4
* On Day 3: price = 3 → profit = 3 - 1 = 2
* On Day 4: price = 6 → profit = 6 - 1 = 5
* On Day 5: price = 4 → profit = 4 - 1 = 3

So best profit = 5 (buy at 1, sell at 6).

---

## 🔹 Where’s the DP idea here?

Let’s map it to the DP concept:

| DP Concept         | Meaning in this problem                                                       |
| ------------------ | ----------------------------------------------------------------------------- |
| **State**          | “Best profit up to this day”                                                  |
| **Transition**     | Either continue with old best profit, or sell today using the best buy so far |
| **Recurrence**     | `profit[i] = max(profit[i-1], prices[i] - minPriceSoFar)`                     |
| **Initialization** | `minPriceSoFar = prices[0]`, `profit[0] = 0`                                  |

Even though we don’t explicitly use a DP table,
we’re doing **state updates** based on **previous results** — that’s DP in disguise.

---

## 🧩 Why it’s part of “DP on Stocks” series

In DSA, the “DP on Stocks” family includes problems like:

* Buy and sell **once** → (this one)
* Buy and sell **multiple times**
* At most **two transactions**
* At most **k transactions**
* With **cooldown**
* With **transaction fee**

All of these are built on the same DP principle:

> “At each day, choose whether to **buy**, **sell**, or **do nothing**, based on your previous best state.”

So this basic one (buy-sell once) is the **foundation** for all advanced DP stock problems.

---

## 🧩 Summary Table

| Concept              | Meaning                                              |
| -------------------- | ---------------------------------------------------- |
| **Goal**             | Maximize profit by choosing best buy & sell days     |
| **Approach**         | Track min price so far & update profit dynamically   |
| **Why DP?**          | Each day’s decision depends on previous optimal info |
| **Transition**       | `maxProfit = max(maxProfit, price - minPriceSoFar)`  |
| **Time complexity**  | O(n)                                                 |
| **Space complexity** | O(1)                                                 |



---
---
---


## 🧩 Step 1: Restating the problem in your own words

We have an array `prices[i]` → stock price on day `i`.

We need to **buy once** and **sell once later** (can’t sell before buying).
We must find the **maximum possible profit**.

Example:

```cpp
prices = [7, 1, 5, 3, 6, 4]
```

We can buy at **1** (Day 1) and sell at **6** (Day 4),
Profit = `6 - 1 = 5` → that’s the answer.

---

## 🧩 Step 2: Brute Force (start with naive thinking)

Let’s think like a beginner first:

Try all possible pairs `(buyDay, sellDay)` where `sellDay > buyDay`.

For every pair:

```cpp
profit = prices[sellDay] - prices[buyDay]
```

Keep track of the maximum profit.

### 🧠 Why this idea works:

It checks **all combinations**, so it guarantees the correct answer.

### ⚠️ But:

Time complexity = O(n²)
For n = 10⁵ → 10¹⁰ operations ❌ too slow.

So we need something better.

---

## 🧩 Step 3: Observe a pattern for optimization

We notice:

* To find the best profit **on day i**, we need the **lowest price before day i**.
* Because the profit formula is:

  ```
  profit_if_sold_today = prices[i] - min_price_before_today
  ```

That means we can solve it in **one pass** if we just keep track of:

1. **Minimum price so far** → best day to buy till now
2. **Maximum profit so far** → best profit seen so far

---

## 🧩 Step 4: Build the step-by-step logic

We’ll walk through the array **from left to right** (day by day).

Let’s take:

```cpp
prices = [7, 1, 5, 3, 6, 4]
```

### Initialize:

```
minPrice = prices[0] = 7
maxProfit = 0
```

Now process each day 👇

| Day | Price | minPrice so far | Profit if sold today | maxProfit |
| --- | ----- | --------------- | -------------------- | --------- |
| 0   | 7     | 7               | 0                    | 0         |
| 1   | 1     | min(7,1)=1      | 1-1=0                | 0         |
| 2   | 5     | 1               | 5-1=4                | 4         |
| 3   | 3     | 1               | 3-1=2                | 4         |
| 4   | 6     | 1               | 6-1=5                | 5         |
| 5   | 4     | 1               | 4-1=3                | 5         |

✅ Final Answer = **5**

---

## 🧩 Step 5: Understanding why this works

### 🧠 Insight 1: Only one pass needed

We never need to “look back” —
at each step, we already know:

* The best (lowest) buy price so far
* The best profit possible if we sell today

So every day’s decision is made using previous optimal results → **Dynamic Programming logic**

---

### 🧠 Insight 2: Why we update minPrice first

We always update `minPrice` first because:

* Before selling today, we should know the **cheapest possible earlier price**.
* If today’s price is lower than all previous, it’s a **better buy option**.

---

### 🧠 Insight 3: Why we update profit after that

Once we know `minPrice`,
today’s possible profit is simply:

```
todayProfit = prices[i] - minPrice
```

If `todayProfit` > `maxProfit`, update it.

---

## 🧩 Step 6: Write the code

```cpp
int maxProfit(vector<int>& prices) {
    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); i++) {
        // update minPrice if today’s price is cheaper
        if (prices[i] < minPrice)
            minPrice = prices[i];

        // calculate today’s profit if we sell now
        int profit = prices[i] - minPrice;

        // update maxProfit if this is better
        if (profit > maxProfit)
            maxProfit = profit;
    }

    return maxProfit;
}
```

---

## 🧩 Step 7: Analyze the complexity

| Metric    | Explanation          | Value |
| --------- | -------------------- | ----- |
| **Time**  | One scan of array    | O(n)  |
| **Space** | Only a few variables | O(1)  |

---

## 🧩 Step 8: Why this is the *chosen solution*

We picked this over brute force because:

| Reason            | Brute Force | Optimized                  |
| ----------------- | ----------- | -------------------------- |
| Checks every pair | ✅           | ❌ (we skip useless checks) |
| Speed             | O(n²)       | ✅ O(n)                     |
| Space             | O(1)        | O(1)                       |
| Logic simplicity  | Medium      | ✅ Very clean and DP-based  |

---

## 🧩 Step 9: Final takeaway

**This problem teaches you 3 powerful DSA ideas:**

1. How to convert brute-force → linear-time using prefix info (minPrice).
2. The foundation of **DP on Stocks** — state-based decision making.
3. Real-world reasoning: “Buy low, sell high — but know your lowest so far.”