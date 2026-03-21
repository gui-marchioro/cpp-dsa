#include <iostream>
#include "ListNode.hpp"
#include "LinkedList.hpp"

int main() {
    LinkedList ll({1, 2, 3, 4});
    std::cout << ll.ToString() << '\n';

    ll.Append(5);
    std::cout << ll.ToString() << '\n';

    ll.Pop();

    std::cout << ll.ToString() << '\n';
}
