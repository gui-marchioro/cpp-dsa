#include <vector>
#include <iostream>
#include <climits>

using namespace std;

/*  -- sort solution
        - traverse each list and its inner items to create a vector containing all elements
        - sort the vector
        - create the result list based in the built vector
    -- Time complexity O(n log n):
        - sort operation is the dominant one
    -- Space complexity: O(n)
        - a vector containing all items is needed

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 19.19 MB
        Beats: 13.55%
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int listsSize = lists.size();
        if (listsSize == 0) {
            return nullptr;
        }
        if (listsSize == 1) {
            return lists[0];
        }

        ListNode* head = new ListNode();
        ListNode* node = head;
        int minVal = INT_MAX;
        int minIdx = 0;
        bool listsEnded = true;
        do {
            listsEnded = true;
            for (int i = 0; i < listsSize; i++) {
                if (lists[i] == nullptr) {
                    continue;
                }
                listsEnded = false;
                if (lists[i]->val < minVal) {
                    minVal = lists[i]->val;
                    minIdx = i;
                }
            }
            
            node->next = lists[minIdx];
            node = node->next;
            if (lists[minIdx]) {
                // cout << lists[minIdx]->val << endl;
                lists[minIdx] = lists[minIdx]->next;
            }
            minVal = INT_MAX;
        } while (!listsEnded);
        return head->next;
    }
};