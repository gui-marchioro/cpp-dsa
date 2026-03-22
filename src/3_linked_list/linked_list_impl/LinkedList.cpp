#include "LinkedList.hpp"

LinkedList::LinkedList(): m_head(nullptr), m_tail(nullptr) {

}

LinkedList::LinkedList(int headValue) : m_head(nullptr), m_tail(nullptr) {
    ListNode* node = new ListNode(headValue);
    m_head = node;
    m_tail = node;
}

LinkedList::LinkedList(const std::vector<int>& values)
    : m_head(nullptr), m_tail(nullptr) {
    for (int value : values) {
        Append(value);
    }
}

LinkedList::LinkedList(const LinkedList& other) : m_head(nullptr), m_tail(nullptr) {
    CopyFrom(other);
}

LinkedList::~LinkedList() {
    Clear();
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this == &other) {
        return *this;
    }

    Clear();
    CopyFrom(other);
    return *this;
}

void LinkedList::Clear() {
    ListNode* current = m_head;
    while (current) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    m_head = nullptr;
    m_tail = nullptr;
}

void LinkedList::CopyFrom(const LinkedList& other) {
    for (ListNode* current = other.m_head; current; current = current->next) {
        Append(current->val);
    }
}

std::string LinkedList::ToString() const {
    std::string result;
    auto auxHead = m_head;
    while (auxHead) {
        result += std::to_string(auxHead->val);
        auxHead = auxHead->next;
        if (auxHead) {
            result += " -> ";
        }
    }
    return result;
}

void LinkedList::Append(int value) {
    ListNode* node = new ListNode(value);
    if (!m_head) {
        m_head = node;
        m_tail = node;
        return;
    }
    m_tail->next = node;
    m_tail = node;
}

std::optional<int> LinkedList::Pop() {
    if (!m_head) {
        return std::nullopt;
    }

    if (m_head == m_tail) {
        ListNode* node = m_head;
        int value = node->val;
        m_head = nullptr;
        m_tail = nullptr;
        delete node;
        return value;
    }

    ListNode* newTail = m_head;
    while (newTail->next != m_tail) {
        newTail = newTail->next;
    }

    ListNode* popNode = m_tail;
    int value = popNode->val;
    m_tail = newTail;
    m_tail->next = nullptr;
    delete popNode;
    return value;
}
