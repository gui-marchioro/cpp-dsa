"""
-- array hashmap + set solution
    The idea here is to:
    - traverse characters
    - fill seen set
    - fill hashmap of possible unique chars
    - if already seen, remove from hashmap
    - in the end traverse the hashmap to find the minimal index

    -- Time complexity: O(n)
        - 2 sequential loops
    -- Space complexity: O(n)
        - Set of numbers grows linearly as the input grows

    -- Leet Code submission results:
        Runtime: 47 ms
        Beats: 87.96%

        Memory: 19.79 MB
        Beats: 21.77%
*/
"""


class Solution:
    def firstUniqChar(self, s: str) -> int:
        seen = set()
        unique_chars = {}
        for i, c in enumerate(s):
            if not c in seen:
                seen.add(c)
                unique_chars[c] = i
            else:
                if c in unique_chars:
                    unique_chars.pop(c)

        first_unique_idx = float("inf")
        for c, i in unique_chars.items():
            if i < first_unique_idx:
                first_unique_idx = i

        return first_unique_idx if first_unique_idx != float("inf") else -1
