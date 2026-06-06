/*  -- Dynamic Programming
    - Divide and conquer algorithm
    - Calculate fibbonaci formula

    -- Time complexity: O(n)

    -- Space complexity: O(1)

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 7.77 MB
        Beats: 83.39%
*/

/* Intuition
- n = 0
    out = 0
- n = 1
    out = 1
    1. 1 step
- n = 2
    out = 2
    1. 1 + 1
    2. 2
- n = 3
    out = 3
    1. 1+1+1
    2. 1+2
    3. 2+1
- n = 4
    out = 5
    1. 1+1+1+1
    2. 1+1+2
    3. 1+2+1
    4. 2+1+1
    5. 2+2
- n = 5
    out = 8
    1. 1+1+1+1+1
    2. 1+1+1+2
    3. 1+1+2+1
    4. 1+2+1+1
    5. 2+1+1+1
    6. 2+1+2
    7. 2+2+1
    8. 1+2+2
- n = x
    out = out(n-2) + out(n-1) -> fibbonacci formula
*/

class Solution {
public:
    int climbStairs(int n) {
        int fib_2 = 0;
        int fib_1 = 1;
        int currFib = 0;
        for (int i = 0; i < n; i++) {
            currFib = fib_2 + fib_1;
            fib_2 = fib_1;
            fib_1 = currFib;
        }
        return currFib;
    }
};