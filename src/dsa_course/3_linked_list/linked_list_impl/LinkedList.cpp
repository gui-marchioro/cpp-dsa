#include "LinkedList.hpp"

LinkedList::LinkedList() {

}

LinkedList::LinkedList(int headValue) {
    Append(headValue);
}

LinkedList::LinkedList(const std::vector<int>& values) {
    for (int value : values) {
        Append(value);
    }
}

LinkedList::LinkedList(const LinkedList& other) {
    CopyFrom(other);
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this == &other) {
        return *this;
    }

    LinkedList copy(other);
    Swap(copy);
    return *this;
}

void LinkedList::Clear() {
    m_head.reset();
    m_tail = nullptr;
}

void LinkedList::CopyFrom(const LinkedList& other) {
    for (ListNode* current = other.m_head.get(); current; current = current->next.get()) {
        Append(current->val);
    }
}

void LinkedList::Swap(LinkedList& other) noexcept {
    std::swap(m_head, other.m_head);
    std::swap(m_tail, other.m_tail);
}

std::string LinkedList::ToString() const {
    std::string result;
    auto* auxHead = m_head.get();
    while (auxHead) {
        result += std::to_string(auxHead->val);
        auxHead = auxHead->next.get();
        if (auxHead) {
            result += " -> ";
        }
    }
    return result;
}

void LinkedList::Append(int value) {
    auto node = std::make_unique<ListNode>(value);
    ListNode* nodePtr = node.get();
    if (!m_head) {
        m_head = std::move(node);
        m_tail = nodePtr;
        return;
    }

    m_tail->next = std::move(node);
    m_tail = nodePtr;
}

std::optional<int> LinkedList::Pop() {
    if (!m_head) {
        return std::nullopt;
    }

    if (m_head.get() == m_tail) {
        int value = m_head->val;
        m_head.reset();
        m_tail = nullptr;
        return value;
    }

    ListNode* newTail = m_head.get();
    while (newTail->next.get() != m_tail) {
        newTail = newTail->next.get();
    }

    int value = m_tail->val;
    newTail->next.reset();
    m_tail = newTail;
    return value;
}
