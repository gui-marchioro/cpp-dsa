from typing import List


""" 
- hashmap prefix sum solution
    - iterate all elements summing them each by each
    - save and count prefix sums for each element in the array
    - reduce target k from the current sum, the result is a subarray prefix sum
      which when removed from the current sum results in the target k
    - look past prefix accounted to see if the number calculated is found
      If so, sum up the final result of possible subarrays that the sum == k

    -- Time complexity: O(n)
        - 1 loop

    -- Space complexity: O(n)
        - prefix sums are kept in memory and can increase within n

    -- Leet Code submission results:
        Runtime: 23 ms
        Beats: 98.24%

        Memory: 21.88 MB
        Beats: 56.48%
"""


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefix_sum = 0
        result = 0
        prefix_count = {0: 1}
        for n in nums:
            prefix_sum += n
            needed_prefix = prefix_sum - k
            # print(f"{prefix_count=}, {prefix_sum=}, {n=}, {needed_prefix=}")
            if needed_prefix in prefix_count:
                result += prefix_count[needed_prefix]
            if not prefix_sum in prefix_count:
                prefix_count[prefix_sum] = 1
            else:
                prefix_count[prefix_sum] += 1
        return result
