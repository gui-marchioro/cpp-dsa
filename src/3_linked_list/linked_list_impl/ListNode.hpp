#pragma once

#include <memory>

class ListNode {
public:
    explicit ListNode(int value);
    ListNode(int value, std::unique_ptr<ListNode> nextNode);
    ~ListNode() = default;

    int val;
    std::unique_ptr<ListNode> next;
};
