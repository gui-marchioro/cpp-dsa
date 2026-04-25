
/*  -- Merge sort solution
    -- Time complexity: O(n log n)
        - recursive loops, divide and conquer
    -- Space complexity: O(n)
        - all the nodes are kept in memory

    -- Leet Code submission results:
        Runtime: 14 ms
        Beats: 65.71%

        Memory: 57.10 MB
        Beats: 82.00%
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
    // Find middle
    ListNode* FindMiddle(ListNode* head) {
        ListNode* s = head;
        ListNode* f = head->next;
        while (f->next && f->next->next) {
            s = s->next;
            f = f->next->next;
        }
        return s;
    }

    // Merge two lists
    ListNode* MergeTwoLists(ListNode* l1, ListNode* l2) {
        auto result = ListNode{0};
        auto head = &result;
        auto tail = &result;
        // order lists based in ascending order
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        // assign remaining list to the result
        if (l1) {
            tail->next = l1;
        }
        else {
            tail->next = l2;
        }

        return head->next;
    }

    // Merge sort
    ListNode* MergeSort(ListNode* head) {
        if (!head || !head->next) {
            // stop recursion condition
            return head;
        }
    
        // split list in two halfs
        auto middle = FindMiddle(head);
        auto rightList = middle->next;
        middle->next = nullptr;
        // apply merge sort in both sides
        head = MergeSort(head);
        rightList = MergeSort(rightList);
        // merge two lists
        return MergeTwoLists(head, rightList);
    }

    ListNode* sortList(ListNode* head) {
        return MergeSort(head);
    }
};

int main() {
    auto n4 = ListNode{3};
    auto n3 = ListNode{1, &n4};
    auto n2 = ListNode{2, &n3};
    auto n1 = ListNode{4, &n2};

    auto sol = Solution{};
    auto result = sol.sortList(&n1);
    return 0;
}
