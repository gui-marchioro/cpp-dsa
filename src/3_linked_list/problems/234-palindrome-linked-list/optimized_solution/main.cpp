#include <iostream>

using namespace std;

/*  -- Linked list inversion + Fast and Slow pointer
    The idea here is to:
    - use fast and slow pointer
    - slow goes inverting the linked list
    - when the fast reaches the end then we are in the middle
    - then we can compare inverted list with the remaining list nodes

    -- Time complexity: O(n)
        - 2 sequentials loop
    -- Space complexity: O(1)
        - some pointer variables traversing the linked list

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 114.13 MB
        Beats: 99.01%
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        // Reverse first half while finding middle
        while (fast && fast->next) {
            fast = fast->next->next;

            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        // Handle odd length (skip middle)
        if (fast != nullptr) {
            slow = slow->next;
        }

        // Compare both halves
        ListNode* first = prev;
        ListNode* second = slow;

        while (first && second) {
            if (first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }

        return true;
    }
};

int main () {
    // Create list: 1 -> 2 -> 2 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    //head->next->next->next = new ListNode(1);

    Solution sol;
    auto result = sol.isPalindrome(head);

    cout << to_string(result) << endl;
}
