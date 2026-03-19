# Fast and Slow Pointer Technique

The fast and slow pointer technique (also called the two-pointer technique) is a very common pattern in algorithms—especially for linked lists and arrays. It involves moving two pointers through a data structure at different speeds to solve problems efficiently (usually in O(n) time and O(1) space).

## Core Concept

* Use **two pointers**:

  * **Slow** → moves 1 step
  * **Fast** → moves 2 steps
* The speed difference helps detect structure patterns efficiently.

---

## Main Use Cases

* **Cycle detection** (fast catches slow)
* **Find middle of list** (fast reaches end)
* **Find start of cycle**
* **Remove N-th node from end** (maintain gap)
* **Check palindrome** (split list)

---

## Key Patterns

* Fast pointer:

  * Reaches end → slow is at **middle**
  * Meets slow → **cycle exists**
  * Stays ahead → maintains **distance gap**

---

## When to Use

* Problems involving **linked lists**
* Need **O(1) space**
* Looking for **relative positioning** instead of extra memory

---

## Intuition

* Like a race:

  * Loop → fast laps slow → **cycle**
  * Straight path → fast finishes → slow at **middle**
