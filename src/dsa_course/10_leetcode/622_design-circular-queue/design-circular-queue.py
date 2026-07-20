""" 
    -- Time complexity: O(n) in all methods
        - queue is always traversed

    -- Space complexity: O(n)
        - queue is n sized

    -- Leet Code submission results:
        Runtime: 31 ms
        Beats: 6.35%

        Memory: 20.16 MB
        Beats: 13.83%
"""


class MyCircularQueue:

    def __init__(self, k: int):
        self.q: list[int] = []
        self.max_len = k
        self.head = 0
        self.tail = -1
        # fill the queue with initial values
        for i in range(k):
            self.q.append(-1)

    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False
        self.tail += 1
        if self.tail == self.max_len:
            self.tail = 0
        self.q[self.tail] = value
        return True

    def deQueue(self) -> bool:
        if self.isEmpty():
            return False
        self.q[self.head] = -1
        self.head += 1
        if self.head == self.max_len:
            self.head = 0
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
        # return True if all elements are empty (== -1)
        return all(elem == -1 for elem in self.q)

    def isFull(self) -> bool:
        # return True if all elements are filled (!= -1)
        return all(elem != -1 for elem in self.q)


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()