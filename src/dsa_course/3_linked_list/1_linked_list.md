# Linked List

- Conceptual doubly linked list

~~~
     head                  tail  
       *                    *  
    | #0 | <-> | #1 | <-> | #2 |
~~~

-  Each Node inside the linked list have a **value**, a pointer to the **next** and to the **previous** linked items

- When adding an item to the front, the **head pointer** should be updated, whereas the pointers from the Nodes involved (new item **next** is the old head, old head **previous** is the new item)

~~~
     head                             tail  
       *                                *  
    | #3 | <-> | #0 | <-> | #1 | <-> | #2 |
~~~

- When adding an item to the end the operation is quite similar

~~~
     head                                        tail  
       *                                          *  
    | #3 | <-> | #0 | <-> | #1 | <-> | #2 | <-> | #4 |
~~~

- Item removals should also update the pointers accordingly. Normally the item removed is returned as an object from the function call.
- Removing the first item

~~~
     head                              tail  
       *                                *  
    | #0 | <-> | #1 | <-> | #2 | <-> | #4 |
~~~

- Removing the last item

~~~
     head                  tail  
       *                    *  
    | #0 | <-> | #1 | <-> | #2 |
~~~

## Sample implementation

~~~python
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def add_to_front(self, value):
        new_node = Node(value)
        if not self.head:
            self.head = self.tail = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node

    def add_to_end(self, value):
        new_node = Node(value)
        if not self.tail:
            self.head = self.tail = new_node
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node

    def remove_from_front(self):
        if not self.head:
            return None
        removed_value = self.head.value
        if self.head == self.tail:
            self.head = self.tail = None
        else:
            self.head = self.head.next
            self.head.prev = None
        return removed_value

    def remove_from_end(self):
        if not self.tail:
            return None
        removed_value = self.tail.value
        if self.head == self.tail:
            self.head = self.tail = None
        else:
            self.tail = self.tail.prev
            self.tail.next = None
        return removed_value
~~~