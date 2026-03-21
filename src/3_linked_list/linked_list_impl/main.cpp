#include <iostream>
#include "ListNode.hpp"
#include "LinkedList.hpp"

int main() {
    auto ll = new LinkedList({1, 2, 3, 4});
    std::cout << ll->ToString() << std::endl;

    auto ln = new ListNode(5);
    ll->Append(ln);
    std::cout << ll->ToString() << std::endl;
    ll->Pop();
    std::cout << ll->ToString() << std::endl;
    return 0;
}
