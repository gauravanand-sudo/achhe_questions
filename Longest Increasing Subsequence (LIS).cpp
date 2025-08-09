Great! Let's take a quick detour and cover both your questions in **Google-level depth** — then we’ll return to the sliding window track.

---

## ✅ Question 1: **Longest Increasing Subsequence (LIS)**

**Classic DP Problem | Leetcode #300 | Medium-Hard**

---

### 🔍 Problem Statement:

Given an integer array `nums`, return the **length** of the **longest strictly increasing subsequence**.

> Example:
> Input: `[10,9,2,5,3,7,101,18]`
> Output: `4` → The LIS is `[2,3,7,101]`

---

### 🧠 Google Thinking:

* LIS is a **subsequence**, not subarray → you can skip elements
* It's a **classic DP + Binary Search** optimization problem
* Used in real-world scheduling, versioning, and constraint-based problems

---

### ✅ Brute Force (Exponential):

Try all subsequences → O(2^n) — too slow.

---

### ✅ DP Solution (O(n²)):

```cpp
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1); // dp[i] = LIS ending at i
    int maxLen = 1;

    for (int i = 1; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);

    return *max_element(dp.begin(), dp.end());
}
```

---

### ✅ Optimized Using Binary Search (O(n log n)):

This is what Google expects.

* Use a `tails` array where `tails[i]` = minimum ending element of LIS of length `i+1`

```cpp
int lengthOfLIS(vector<int>& nums) {
    vector<int> tails;

    for (int num : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end()) tails.push_back(num);
        else *it = num;
    }

    return tails.size();
}
```

---

### 📌 Key Insight:

* This does **not** give the subsequence, only length.
* But it maintains smallest tails for each possible LIS length.
* Can be modified to track path if needed.

---

## ✅ Question 2: **Happy Number**

**Leetcode #202 | Easy-Medium | Google Tag**

---

### 🔍 Problem Statement:

A **happy number** is defined by the process:

1. Take the number, square each digit and sum.
2. Repeat the process.
3. If it ends in `1`, it's happy.
4. If it loops endlessly, it's not.

> Example:
> 19 → 1² + 9² = 82 → 8² + 2² = 68 → ... → 1 ✅

---

### 🧠 Google Thinking:

* Detect if a cycle happens → Use **Floyd's cycle detection** (fast and slow pointer)
* Or use **hash set** to record visited states

---

### ✅ Clean Code (Using Set):

```cpp
int getNext(int n) {
    int sum = 0;
    while (n) {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    unordered_set<int> seen;
    while (n != 1 && !seen.count(n)) {
        seen.insert(n);
        n = getNext(n);
    }
    return n == 1;
}
```

---

### ✅ Code (Using Fast & Slow Pointers):

```cpp
bool isHappy(int n) {
    auto getNext = [](int x) {
        int sum = 0;
        while (x) {
            int d = x % 10;
            sum += d * d;
            x /= 10;
        }
        return sum;
    };

    int slow = n, fast = getNext(n);
    while (fast != 1 && slow != fast) {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }

    return fast == 1;
}
```

---

### 🔁 Follow-ups:

* Why does it always fall into a loop if not happy? (Proof: Finite space)
* Can you optimize space? (Yes, use fast & slow)
* What's the max sum for a number with N digits? (Constraint-based pruning)

---

✅ Both **LIS** and **Happy Number** covered Google-style.

Ready to return to:
👉 **Problem 2: Permutation in String** or
👉 **Problem 4: Find All Anagrams** in our sliding window series?

Let’s proceed whenever you're ready.
