#pragma once

#include <string>
#include <vector>
#include "ListNode.hpp"

class LinkedList {
public:
    LinkedList();
    LinkedList(ListNode* head);
    LinkedList(std::vector<int> listVals);
    ~LinkedList();

    std::string ToString();
    void Append(ListNode* node);
    ListNode* Pop();
private:
    ListNode* m_head;
    ListNode* m_tail;
};
