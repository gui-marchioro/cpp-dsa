# Linked List

- Different than arrays the elements are not queued in memory
- Instead what is allocated is the value, and a pointer reference to the next node.

    | #0 | -> | #1 | -> | #2 |

- Normally a reference to the first and the last item are kept in memory, **head** and **tail**, respectively
- Classical linked lists only have pointers to the next item, but a pointer to the previous item can also be added to create what is called a **double linked list**
- **Finding an element** inside the linked list has **O(n)** complexity (disadvantage comparing to arrays)
- **Finding the FIRST or the LAST element** has **O(1)** complexity
- **Adding** or **removing** and element in the **beggining** or in the **end** has **O(1)** (advantage comparing to arrays)
- **Adding** or **removing** and element **inside** the list has **O(n)**
