from typing import List


""" 
- two pointers sliding window
    - iterate all elements
    - for each element create a sliding window
      - left pointer stays at the element
      - right pointer moves until the end of the array
      - account the sum inner the window
          - if equals to the target k, add 1 to the result

    -- Time complexity: O(n^2)
        - 1 nested loop

    -- Space complexity: O(1)
        - some auxiliar variables created

    -- Leet Code submission results:
        Time Limit Exceeded
"""


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        nums_len = len(nums)
        result = 0
        for i in range(nums_len):
            left = i
            curr_sum = nums[left]
            right = i+1
            if curr_sum == k:
                result += 1
            while right < nums_len:
                curr_sum += nums[right]
                if curr_sum == k:
                    result += 1
                right += 1
        return result
