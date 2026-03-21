#include "LinkedList.hpp"

LinkedList::LinkedList(): m_head(nullptr) {

}

LinkedList::LinkedList(ListNode* head): m_head(head) {
    auto auxHead = head;
    auto prevHead = head;
    while (auxHead) {
        prevHead = auxHead;
        auxHead = auxHead->next;
    }
    m_tail = prevHead;
}

LinkedList::LinkedList(std::vector<int> listVals) {
    ListNode* auxHead = nullptr;
    for (int i = 0; i < listVals.size(); i++) {
        if (i == 0) {
            m_head = new ListNode(listVals[i]);
            auxHead = m_head;
        }
        if (i == listVals.size() - 1) {
            m_tail = new ListNode(listVals[i]);
            auxHead->next = m_tail;
        }
        if (i > 0 && i < listVals.size() - 1) {
            auxHead->next = new ListNode(listVals[i]);
            auxHead = auxHead->next;
        }
    }
}

LinkedList::~LinkedList() {

}

std::string LinkedList::ToString() {
    std::string result = "";
    auto auxHead = m_head;
    while (auxHead) {
        result = result + std::to_string(auxHead->val) + " -> ";
        auxHead = auxHead->next;
    }
    return result;
}

void LinkedList::Append(ListNode* node) {
    m_tail->next = node;
    m_tail = node;
}

ListNode* LinkedList::Pop() {
    auto newTail = m_head;
    auto popNode = m_tail;
    while (newTail->next != m_tail) {
        newTail = newTail->next;
    }

    m_tail = newTail;
    newTail->next = nullptr;
    return popNode;
}
