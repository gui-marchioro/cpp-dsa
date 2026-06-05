# Stack

## Sample Implementation using Array

- Using array + pointer

~~~python
class Stack:
    def __init__(self, max_length=1000):
        self.items = [0] * max_length
        self.max_length = max_length
        self.pointer = 0

    def push(self, item):
        if self.pointer >= self.max_length:
            raise IndexError("Stack overflow")
        self.items[self.pointer] = item
        self.pointer += 1

    def pop(self):
        if self.pointer == 0:
            raise IndexError("Empty stack")
        self.pointer -= 1
        return self.items[self.pointer]

    def peek(self):
        if self.pointer == 0:
            raise IndexError("Empty stack")
        return self.items[self.pointer - 1]

    def size(self):
        return self.pointer
~~~

## Sample Implementation using Linked List

- Using Linked List Node

~~~python
class Node:
    def __init__(self, value=None):
        self.value = value
        self.next = None


class Stack:
    def __init__(self):
        self.top = None
        self._size = 0

    def push(self, item):
        new_node = Node(item)
        new_node.next = self.top
        self.top = new_node
        self._size += 1

    def pop(self):
        if self.top is None:
            raise IndexError("Empty stack")
        popped_node = self.top
        self.top = popped_node.next
        self._size -= 1
        return popped_node.value

    def peek(self):
        if self.top is None:
            raise IndexError("Empty stack")
        return self.top.value

    def size(self):
        return self._size
~~~
