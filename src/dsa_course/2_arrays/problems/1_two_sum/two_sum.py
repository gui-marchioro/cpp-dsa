from typing import List


"""
-- Optimized solution
    - traverse nums array
    - evaluate reciprocate number that results the target
    - if the number iterated is in the reciprocal map, return indexes
    - if not add the reciprocate and index to the map

    -- Time complexity: O(n) to traverse nums array
    -- Space complexity: O(n) to save map of reciprocal numbers

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 20.77 MB
        Beats: 6.95%
"""


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        reciprocal_map: dict[int, int] = {}
        for i, n in enumerate(nums):
            reciprocal = target-n
            if n in reciprocal_map:
                return [reciprocal_map[n], i]
            else:
                reciprocal_map[reciprocal] = i
        return []
