from typing import List

"""
-- Two pointers 
- numbers array is alrady sorted
- uses a left pointer in the begining and a right pointer in the end
- traverse the array checking if the sum is equal to the target
- if greater, right pointer is reduced
- if smaller, left pointer grows

-- Time complexity: O(n)
    - 1 loop

-- Space complexity: O(1)
    - two pointers

-- Leet Code submission results:
    Runtime: 0 ms
    Beats: 100.00%

    Memory: 20.52 MB
    Beats: 35.74%
"""

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l = 0
        r = len(numbers) - 1
        while l < r:
            # print(f"r: {r}, l: {l}")
            if numbers[r] + numbers[l] > target:
                r -= 1
            elif numbers[r] + numbers[l] < target:
                l += 1
            else:
                return [l+1, r+1]
        return []
