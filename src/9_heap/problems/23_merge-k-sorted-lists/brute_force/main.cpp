#include <vector>
#include <iostream>
#include <climits>

using namespace std;

/*  -- selection sort solution
        - traverse each list to find the smaller number
        - fill the new linked list based in the smaller number found
    -- Time complexity O(n * m):
        - traverse all items (n), times number of lists provided (m)
    -- Space complexity: O(1)
        - some auxiliar variables needed

    -- Leet Code submission results:
        Runtime: 165 ms
        Beats: 5.93%

        Memory: 18.05 MB
        Beats: 98.41%
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