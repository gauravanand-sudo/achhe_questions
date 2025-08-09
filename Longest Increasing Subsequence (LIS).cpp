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



✅ Both **LIS** and **Happy Number** covered Google-style.

Ready to return to:
👉 **Problem 2: Permutation in String** or
👉 **Problem 4: Find All Anagrams** in our sliding window series?

Let’s proceed whenever you're ready.
