#include <vector>
#include <iostream>

using namespace std;

/*  -- Linked list inversion + Fast and Slow pointer
    The idea here is to:
    - go throgh the list and store node values inside a vector
    - use two pointers traversing the vector to check if it is a palindrome or not

    -- Time complexity: O(n)
        - 2 sequentials loop
    -- Space complexity: O(n)
        - vector to store node values

    -- Leet Code submission results:
        Runtime: 3 ms
        Beats: 59.62%

        Memory: 131.99 MB
        Beats: 17.90%
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
        // go throgh the list and store node values inside a vector
        std::vector<int> values;
        ListNode* current = head;
        while (current) {
            values.push_back(current->val);
            current = current->next;
        }

        // use two pointers traversing the vector to check if it is a palindrome or not
        int left = 0;
        int right = values.size() - 1;
        while (left < right) {
            if (values[left] != values[right]) {
                return false;
            }
            left++;
            right--;
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
