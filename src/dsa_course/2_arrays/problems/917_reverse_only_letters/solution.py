"""
-- Two pointers
    The idea here is to:
    - use two pointers, one in the start and other in the end
    - finish the iterations when they find each other
    - check if the letter can be exchanged directly, if not increase left or decrease right pointer

    -- Time complexity: O(n)
        - 1 loop to create char array
        - 1 loop to invert string
    -- Space complexity: O(n)
        - basically two pointers and other aux char vars
        - array of n chars provenient from the str

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 19.27 MB
        Beats: 74.83%
"""


class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        s_list = list(s)
        l, r = 0, len(s)-1
        while l < r:
            if not s_list[l].isalpha():
                l += 1
                continue
            if not s_list[r].isalpha():
                r -= 1
                continue
            s_list[l], s_list[r] = s_list[r], s_list[l]
            l += 1
            r -= 1
            
        return "".join(c for c in s_list)
