#pragma once

class ListNode {
public:
    ListNode();
    ListNode(int val);
    ListNode(int val, ListNode* next);
    ~ListNode();

    int val;
    ListNode* next;
};
