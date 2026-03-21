#pragma once

class ListNode {
public:
    ListNode();
    ListNode(int value);
    ListNode(int value, ListNode* nextNode);
    ~ListNode() = default;

    int val;
    ListNode* next;
};
