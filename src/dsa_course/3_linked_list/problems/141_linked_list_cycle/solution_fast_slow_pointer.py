from typing import Optional


"""
-- Linked list traversal
    The idea here is to:
    - use a fast and slow pointer
    - fast pointer advances 2 steps while the slow only one
    - loop the linked list until they slow and fast pointers:
    - reach each other -> return true
    - fast reaches the end of the linked list -> return false

    -- Time complexity: O(n)
        - 1 loop
    -- Space complexity: O(1)
        - basically some 2 pointers looping the linked list

    -- Leet Code submission results:
        Runtime: 52 ms
        Beats: 68.37%

        Memory: 22.34 MB
        Beats: 97.95%
"""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head or not head.next:
            return False
        slow = head
        fast = head.next
        while slow and fast and fast.next:
            if slow is fast:
                return True
            slow = slow.next
            fast = fast.next.next
        return False