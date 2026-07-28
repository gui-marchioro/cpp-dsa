from typing import List


"""
-- set solution
    The idea here is to:
    - create sets for each array of integers
    - use set intersection to find the unique common numbers

    -- Time complexity: O(n)
        - 3 sequential loops
    -- Space complexity: O(n)
        - Set of numbers grows linearly as the input grows

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.0%

        Memory: 19.40 MB
        Beats: 11.65%
*/
"""


class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1_set = set(nums1)
        nums2_set = set(nums2)
        isection = list(nums1_set.intersection(nums2_set))
        return isection
