#include "ListNode.hpp"


ListNode* FindMiddle(ListNode* node)
{
    if (!node || !node->GetNext())
    {
        return node;
    }

    auto slow = node;
    auto fast = node->GetNext();
    while (fast && fast->GetNext())
    {
        slow = slow->GetNext();
        fast = fast->GetNext()->GetNext();
    }

    return slow;
}


ListNode* MergeTwoLists(ListNode* l1, ListNode* l2)
{
    auto head = ListNode();
    ListNode* tail = &head;

    // Order lists node by node by their value
    while (l1 && l2)
    {
        if (l1->GetVal() < l2->GetVal())
        {
            tail->SetNext(l1);
            l1 = l1->GetNext();
        }
        else
        {
            tail->SetNext(l2);
            l2 = l2->GetNext();
        }

        tail = tail->GetNext();
    }

    // Concatenate end of list from remaining side
    if (l1)
    {
        tail->SetNext(l1);
    }
    else
    {
        tail->SetNext(l2);
    }
    
    return head.GetNext();
}


ListNode* MergeSort(ListNode* node)
{
    if (!node || !node->GetNext())
    {
        // End of recursion
        return node;
    }
    // Find middle of list and divide in two
    auto middleNode = FindMiddle(node);
    auto rightList = middleNode->GetNext();
    middleNode->SetNext(nullptr);
    // Sort both sides recursively
    auto leftSort = MergeSort(node);
    auto rightSort = MergeSort(rightList);
    // Deliver final merge sort of both sides
    return MergeTwoLists(leftSort, rightSort);
}

int main()
{
    auto n1 = ListNode{5};
    auto n2 = ListNode{1, &n1};
    auto n3 = ListNode{1, &n2};
    auto n4 = ListNode{9, &n3};
    auto n5 = ListNode{5, &n4};
    auto n6 = ListNode{2, &n5};

    auto result = MergeSort(&n6);
    return 0;
}
