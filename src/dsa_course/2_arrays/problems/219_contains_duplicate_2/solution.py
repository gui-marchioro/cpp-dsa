from typing import List


"""
-- array iteration + hash map solution
    The idea here is to:
    - create a hash map to keep track of the items seen and their last index
    - if a duplicate is found
        - evaluate if the distance from last item indexes are smaller than k

    -- Time complexity: O(n)
        - 1 loop

    -- Space complexity: O(n)
        - grows linearly as the input does

    -- Leet Code submission results:
        Runtime: 39 ms
        Beats: 36.64%

        Memory: 39.15 MB
        Beats: 15.76%
"""


class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        if len(nums) < 2:
            # edge case, in case of a small list
            return False
        seen: dict[int, int] = {}
        for i, num in enumerate(nums):
            if num in seen and (i - seen[num]) <= k:
                return True
            seen[num] = i

        return False
