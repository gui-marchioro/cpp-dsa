from typing import List


"""
-- Array iteration + set solution
    The idea here is to:
    - create a set to keep track of seen items
    - loop through the array adding new elements to the set
    - if the element is already there, then we found the duplicate

    -- Time complexity: O(n)
        - 1 loop
    -- Space complexity: O(n)
        - In the worst case the duplicate is in the end of the list, and all items are already added to the set

    -- Leet Code submission results:
        Runtime: 16 ms
        Beats: 43.99%

        Memory: 32.18 MB
        Beats: 64.34%
"""


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        seen = set()
        for num in nums:
            if num in seen:
                return True
            else:
                seen.add(num)
        return False
