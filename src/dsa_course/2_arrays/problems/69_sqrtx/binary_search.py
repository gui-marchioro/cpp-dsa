"""
-- Brute force solution
    -- Time complexity: O(log(n))
        - start evaluating x // 2 as the sqrt(x)
        - cut in half candidate numbers as the algorithm progresses
    -- Space complexity: O(1) 
        - no variable used grows with the input

    -- Leet Code submission results:
        Runtime: 5 ms
        Beats: 35.08%

        Memory: 19.20 MB
        Beats: 87.47%
"""

class Solution:
    def mySqrt(self, x: int) -> int:
        l, r = 0, x
        res = 0
        while l <= r:
            m = l + ((r-l)//2)
            power = m * m
            if power == x:
                return m
            elif power > x:
                r = m - 1
            elif power < x:
                l = m + 1
                res = m
        return res
