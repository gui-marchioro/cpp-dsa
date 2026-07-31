from typing import Optional


"""
-- Linked list traversal
    The idea here is to:
    1. one pointer per list
    2. comparison between list nodes from each list
    3. the smaller should become the next node from the result ListNode pointer from the head to be returned
    4. the list that "lost" one node should advance its head

    -- Time complexity: O(n)
        - 1 loop that will traverse both linked lists one node at a time
    -- Space complexity: O(1)
        - basically 3 pointers looping the linked lists

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 19.12 MB
        Beats: 94.45%
"""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        sorted_list = ListNode()
        iterator = sorted_list
        while list1 and list2:
            if list1.val < list2.val:
                iterator.next = list1
                list1 = list1.next
            else:
                iterator.next = list2
                list2 = list2.next
            iterator = iterator.next
        iterator.next = list1 if list1 else list2
        return sorted_list.next
