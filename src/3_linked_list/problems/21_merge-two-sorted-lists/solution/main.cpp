/*  -- Linked list traversal
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
        Runtime: 2 ms
        Beats: 4.30%

        Memory: 19.51 MB
        Beats: 26.70%
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* loopNode = nullptr;
        ListNode* nextNode = nullptr;
        // 1. one pointer per list
        // 2. comparison between list nodes from each list
        // 3. the smaller should become the next node from the head to be returned
        // 4. the list that "lost" one node should advance its head

        while (list1 || list2) {
            if (list1 && list2) {
                if (list1->val <= list2->val) {
                    nextNode = list1;
                    list1 = list1->next;
                }
                else {
                    nextNode = list2;
                    list2 = list2->next;
                }
            }
            else if (list1) {
                nextNode = list1;
                list1 = list1->next;
            }
            else {
                nextNode = list2;
                list2 = list2->next;
            }

            if (!head) {
                head = nextNode;
                loopNode = head;
            }
            else {
                loopNode->next = nextNode;
                loopNode = loopNode->next;
            }
        }

        return head;
    }
};