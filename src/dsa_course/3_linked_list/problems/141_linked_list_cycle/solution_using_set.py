from typing import Optional


"""
-- Linked list traversal
    The idea here is to:
    - add visited nodes in a set
    - if visited node already in the set, we have a cycle

    -- Time complexity: O(n)
        - 1 loop
    -- Space complexity: O(n)
        - set grows as n grows

    -- Leet Code submission results:
        Runtime: 46 ms
        Beats: 91.65%

        Memory: 22.96 MB
        Beats: 7.38%
"""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        seen = set()
        while head:
            if head in seen:
                return True
            seen.add(head)
            head = head.next
        return False