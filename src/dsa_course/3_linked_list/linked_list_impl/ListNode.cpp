#include "ListNode.hpp"

ListNode::ListNode(int value) : val(value), next(nullptr) {

}

ListNode::ListNode(int value, std::unique_ptr<ListNode> nextNode)
    : val(value), next(std::move(nextNode)) {

}
