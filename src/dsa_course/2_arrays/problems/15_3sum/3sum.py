"""
-- Solution using sorting and 2 pointers
    -- Time complexity: O(n^2)
        - the inner iterations are O(n^2) (loop inside another loop)
        - here sorting is not limiting the algorithm since it is O(n logn)
    -- Space complexity: O(1) 
        - just 3 pointers are used

    -- Leet Code submission results:
        Runtime: 374 ms
        Beats: 99.51%

        Memory: 22.47 MB
        Beats: 17.74%
"""


class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        # first sort the array
        nums.sort()
        result = []
        nums_len = len(nums)
        last_n = None
        # iterate each number
        for i, n in enumerate(nums):
            if n > 0 or (n < 0 and nums[-1] < 0):
                # optimization to instantly return if:
                # - number iterated is positive since it is not possible to sum up to zero anymore
                # - number is negative but there are no positives in the array
                return result
            if n == last_n:
                # skip duplicate numbers
                continue
            last_n = n
            target_sum = -n
            left = i+1
            right = nums_len-1
            while left < right:
                # try to find the target sum in the remaining sorted numbers
                curr_sum = nums[left] + nums[right]
                if curr_sum == target_sum:
                    # target sum found, add it to the array
                    result.append([n, nums[left], nums[right]])
                    # advance left pointer
                    left +=1
                    while left < right and nums[left] == nums[left-1]:
                        # skip duplicate numbers
                        left += 1
                elif curr_sum > target_sum:
                    # sum is greater, decrease right pointer
                    right -= 1
                else:
                    # sum is smaller, increase left pointer
                    left +=1

        return result
