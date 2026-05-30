# Heap

- Can be called as "binary heap" or "priority queue" as well.
- Similar to a queue, but having ordering based in some rule.
- Even it is similar to a queue, implementation could be done by using a binary tree.
- Most common heaps are:
    - Min Heap: ordering is from smaller to greater
    - Max Heap: ordering is from greater to smaller

## Implementation

~~~python
class MinHeap:
    def __init__(self):
        self.heap = []

    def parent(self, index):
        return (index - 1) // 2

    def left_child(self, index):
        return 2 * index + 1

    def right_child(self, index):
        return 2 * index + 2

    def heapify_up(self, index):
        while index > 0 and self.heap[self.parent(index)] > self.heap[index]:
            self.heap[self.parent(index)], self.heap[index] = (
                self.heap[index],
                self.heap[self.parent(index)],
            )
            index = self.parent(index)

    def heapify_down(self, index):
        smallest = index
        left = self.left_child(index)
        right = self.right_child(index)

        if left < len(self.heap) and self.heap[left] < self.heap[smallest]:
            smallest = left

        if right < len(self.heap) and self.heap[right] < self.heap[smallest]:
            smallest = right

        if smallest != index:
            self.heap[index], self.heap[smallest] = (
                self.heap[smallest],
                self.heap[index],
            )
            self.heapify_down(smallest)

    def insert(self, value):
        self.heap.append(value)
        self.heapify_up(len(self.heap) - 1)

    def extract_min(self):
        if len(self.heap) == 0:
            raise IndexError("Heap is empty")
        if len(self.heap) == 1:
            return self.heap.pop()

        root = self.heap[0]
        self.heap[0] = self.heap.pop()
        self.heapify_down(0)

        return root

    def peek(self):
        if len(self.heap) == 0:
            raise IndexError("Heap is empty")
        return self.heap[0]

    def size(self):
        return len(self.heap)

    def is_empty(self):
        return len(self.heap) == 0
~~~
