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
