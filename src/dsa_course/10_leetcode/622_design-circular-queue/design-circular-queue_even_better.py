""" 
    -- Time complexity: 
        - O(n) in constructor
        - O(1) in other methods

    -- Space complexity: O(n)
        - queue is n sized

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 20.10 MB
        Beats: 24.53%
"""


class MyCircularQueue:

    def __init__(self, k: int):
        self.q = [-1]*k
        self.max_len = k
        self.head = 0
        self.tail = -1
        self.count = 0
        self.is_full = False
        self.is_empty = True

    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False
        self.tail += 1
        self.count += 1
        if self.tail == self.max_len:
            self.tail = 0
        self.q[self.tail] = value
        self.is_full = self.count == self.max_len
        self.is_empty = False
        return True

    def deQueue(self) -> bool:
        if self.isEmpty():
            return False
        self.q[self.head] = -1
        self.head += 1
        self.count -= 1
        if self.head == self.max_len:
            self.head = 0
        self.is_empty = self.count == 0
        self.is_full = False
        return True

    def Front(self) -> int:
        if self.isEmpty():
            return -1
        return self.q[self.head]

    def Rear(self) -> int:
        if self.isEmpty():
            return -1
        return self.q[self.tail]

    def isEmpty(self) -> bool:
        return self.is_empty

    def isFull(self) -> bool:
        return self.is_full


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()