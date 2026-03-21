#pragma once

#include <optional>
#include <string>
#include <vector>
#include "ListNode.hpp"

class LinkedList {
public:
    LinkedList();
    LinkedList(int headValue);
    LinkedList(const std::vector<int>& values);
    ~LinkedList();

    std::string ToString() const;
    void Append(int value);
    std::optional<int> Pop();
private:
    ListNode* m_head = nullptr;
    ListNode* m_tail = nullptr;
};
