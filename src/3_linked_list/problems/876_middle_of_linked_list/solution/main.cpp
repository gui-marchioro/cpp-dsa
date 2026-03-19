#include <iostream>

using namespace std;

/*  -- Linked list traversal
    The idea here is to:
    - use a fast and slow pointer
    - fast pointer advances 2 steps while the slow only one
    - loop the linked list until the fast pointer reaches its end
    - when this happens we have found the middle through the slow pointer

    -- Time complexity: O(n)
        - 1 loop
    -- Space complexity: O(1)
        - basically some 2 pointers looping the linked list

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 10.07 MB
        Beats: 25.84%
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        auto slow = head;
        auto fast = head;

        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
            // to prevent crash on even linked lists
            if (fast->next != nullptr)
            {
                fast = fast->next;
            }
        }

        return slow;
    }
};

void printList(ListNode* head)
{
    while (head)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "null" << endl;
}

int main()
{
    // Create list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    cout << "list:" << endl;
    printList(head);

    Solution sol;

    auto result = sol.middleNode(head);
    cout << "Result: " << result->val << endl;

    return 0;
}
