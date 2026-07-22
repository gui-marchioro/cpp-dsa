"""
-- Brute force solution
    The idea here is to check all possible substrings of the input string and determine if they are palindromes.
    We keep track of the longest palindrome found.

    -- Time complexity: O(n^3)
        - 1 loop for each substring O(n^2)
        - Checking if a substring is a palindrome using two pointers: O(n)
    -- Space complexity: O(1)
        - Uses some auxiliar variables

    -- Leet Code submission results:
        Runtime: 3622 ms
        Beats: 17.79%

        Memory: 19.19 MB
        Beats: 91.25%
"""


class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            # edge case of an empty string
            return ""
        s_len = len(s)
        longest_pal = 1
        long_pal_idx = (0,1)
        for i in range(s_len):
            # loop each character
            # find palindromes, and save them if greater
            if s_len - i <= longest_pal:
                # optimization to stop checking if the remaining
                # string is smaller than the already found palindrome
                break
            lo = i
            hi = s_len - 1
            old_hi = hi
            local_longest = 0
            local_long_idx = (0,1)
            while lo < hi:
                if s[lo] == s[hi]:
                    # possible palindrome found
                    if hi+1 - lo > local_longest:
                        old_hi = hi
                        local_longest = hi+1 - lo
                        local_long_idx = (lo, hi+1)
                    lo += 1
                    hi -= 1
                else:
                    # definetely not a palindrome
                    old_hi -= 1
                    hi = old_hi
                    lo = i
                    local_longest = 0
                    local_long_idx = (0,1)
            if local_longest > longest_pal:
                longest_pal = local_longest
                long_pal_idx = local_long_idx

        return s[long_pal_idx[0]:long_pal_idx[1]]
