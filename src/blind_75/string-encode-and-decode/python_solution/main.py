from typing import List


"""  -- String manipulation
        - encode list of string using non-ascii char as a separator
        - decode string into a list using the same ascii char to split
    -- Time complexity: O(n)
        - all characters must be iterated either to encode or decode
    -- Space complexity: O(n)
        - characters saved in memory grow as the input grow

    -- Leet Code submission results:
        Runtime: 29 ms
        Beats: 99.90%

        Memory: 8.00 MB
        Beats: 98.86%
"""


class Solution:
    is_empty_list = False

    def encode(self, strs: List[str]) -> str:
        if not strs:
            self.is_empty_list = True
            return ""
        self.is_empty_list = False
        encoded = "ç".join(strs)
        return encoded

    def decode(self, s: str) -> List[str]:
        if not s and self.is_empty_list:
            return []
        decoded = s.split("ç")
        return decoded
