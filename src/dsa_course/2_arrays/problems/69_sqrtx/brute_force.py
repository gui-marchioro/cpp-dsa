"""
-- Brute force solution
    -- Time complexity: O(sqrt(n))
        - increment numbers until the sqrt(x) is found
    -- Space complexity: O(1) 
        - no variable used grows with the input

    -- Leet Code submission results:
        Runtime: 1451 ms
        Beats: 7.35%

        Memory: 19.42 MB
        Beats: 6.30%
"""


class Solution:
    def mySqrt(self, x: int) -> int:
        for i in range(x+1):
            power = i*i
            if power == x:
                return i
            elif power > x:
                return i-1
        return 0


if __name__ == "__main__":
    sol = Solution()
    assert sol.mySqrt(1) == 1
    assert sol.mySqrt(4) == 2
    assert sol.mySqrt(8) == 2
