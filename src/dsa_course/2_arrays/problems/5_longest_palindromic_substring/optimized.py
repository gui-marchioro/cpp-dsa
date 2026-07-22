"""
-- Optimized solution
    Iterate characters and try to find odd or even palidromes
    starting from the character index outwards

    -- Time complexity: O(n^2)
        - 1 loop for each character O(n)
        - Checking if a substring is a palindrome using two pointers: O(n)
    -- Space complexity: O(1)
        - Uses some auxiliar variables

    -- Leet Code submission results:
        Runtime: 330 ms
        Beats: 39.61%

        Memory: 19.26 MB
        Beats: 68.79%
"""


class Solution:
    def longestPalindrome(self, s: str) -> str:
        s_len = len(s)
        longest_pal = 1
        long_pal_idx = (0,1)
        for i in range(s_len):
            local_long = 1
            local_idx = (0,1)
            # odd
            l, r = i, i
            while l >= 0 and r < s_len and s[l] == s[r]:
                if (r+1-l) > local_long:
                    local_long = r+1-l
                    local_idx = (l,r+1)
                l -= 1
                r += 1
            # even
            l, r = i, i+1
            while l >= 0 and r < s_len and s[l] == s[r]:
                if (r+1-l) > local_long:
                    local_long = r+1-l
                    local_idx = (l,r+1)
                l -= 1
                r += 1

            if local_long > longest_pal:
                longest_pal = local_long
                long_pal_idx = local_idx
        return s[long_pal_idx[0]:long_pal_idx[1]]