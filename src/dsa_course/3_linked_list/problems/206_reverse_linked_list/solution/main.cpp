#include <iostream>

using namespace std;

/*  -- Linked list traversal
    The idea here is to:
    - loop through list nodes while they exist and invert their ->next references

    -- Time complexity: O(n)
        - 1 loop
    -- Space complexity: O(1)
        - basically some some fixed aux variables while the algorithm runs

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 13.23 MB
        Beats: 92.63%
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
    ListNode* reverseList(ListNode* head) {
        if (!head)
        {
            return head;
        }

        // loop through list nodes while they exist and invert the references
        auto nextNode = head->next;
        head->next = nullptr;
        while (nextNode)
        {
            auto previous = head;
            head = nextNode;
            nextNode = head->next;
            head->next = previous;
        }
        
        return head;
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
    // Create list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list:" << endl;
    printList(head);

    Solution sol;
    head = sol.reverseList(head);

    cout << "Reversed list:" << endl;
    printList(head);

    return 0;
}
