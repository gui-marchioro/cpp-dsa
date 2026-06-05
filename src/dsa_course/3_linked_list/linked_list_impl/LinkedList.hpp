#pragma once

#include <memory>
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
    LinkedList(LinkedList&& other) noexcept = default;
    ~LinkedList() = default;

    LinkedList& operator=(const LinkedList& other);
    LinkedList& operator=(LinkedList&& other) noexcept = default;

    std::string ToString() const;
    void Append(int value);
    std::optional<int> Pop();
private:
    void Clear();
    void CopyFrom(const LinkedList& other);
    void Swap(LinkedList& other) noexcept;

    std::unique_ptr<ListNode> m_head;
    ListNode* m_tail = nullptr;
};
