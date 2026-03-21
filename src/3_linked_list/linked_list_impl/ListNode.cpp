#include "ListNode.hpp"

ListNode::ListNode() : val(0), next(nullptr) {

}

ListNode::ListNode(int value) : val(value), next(nullptr) {

}

ListNode::ListNode(int value, ListNode* nextNode) : val(value), next(nextNode) {

}
