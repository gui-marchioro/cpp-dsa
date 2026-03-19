#include <iostream>

using namespace std;

/*  -- Linked list traversal
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
        Runtime: 12 ms
        Beats: 43.03%

        Memory: 11.76 MB
        Beats: 80.53%
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto slow = head;
        auto fast = head;
        // increment slow and fast pointers until they:
        //  - reach each other -> return true
        //  - fast reaches the end of the linked list -> return false
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                return true;
            }
        }

        return false;
    }
};
