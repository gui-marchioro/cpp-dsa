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
    LinkedList(const LinkedList& other);
    ~LinkedList();

    LinkedList& operator=(const LinkedList& other);

    std::string ToString() const;
    void Append(int value);
    std::optional<int> Pop();
private:
    void Clear();
    void CopyFrom(const LinkedList& other);

    ListNode* m_head = nullptr;
    ListNode* m_tail = nullptr;
};
