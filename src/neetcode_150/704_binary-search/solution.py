from typing import List


"""
-- Binary search solution
    -- Time complexity: O(log(n))
        - cut in half candidate numbers as the algorithm progresses
    -- Space complexity: O(1) 
        - no variable used grows with the input

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 20.48 MB
        Beats: 75.17%
"""


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums)-1
        while l <= r:
            m = l + ((r-l)// 2)
            num = nums[m]
            if num == target:
                return m
            elif num > target:
                r = m-1
            elif num < target:
                l = m+1
        return -1
