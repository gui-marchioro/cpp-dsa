# Array

- Bytes queued in contiguous spaces in memory
- **Size** and **Type** are defined upfront, at **compile time**
- Elements are accessed using its index (position) inside the array
- Accessing and updating an element inside the array has **O(1)** complexity


## Memory

- Bytes are allocated queued in contiguous spaces in memory in the **Stack region**
- To resize an array it is required to create a new one and move all bytes to the new memory location
- e.g.
    ~~~c++
    uint8_t arr[4] = {1, 2, 3, 4};
    ~~~
    This will create in memory something like:

    | 0x01 | 0x02 | 0x03 | 0x04 | xxxx | xxxx | xxxx | xxxx | ...
    
    Resizing is not so simple because it is not possible to guarantee that the next memory address available is not filled.
- A pointer is created to the first element in the array
- Thus, by defining the size it is straightforward to access elements via the index required.


## Practical Applications of Arrays

### Cache

Modern processors typically include three levels of cache memory: L1, L2, and L3. Moving from L1 to L3, there is generally:

- a decrease in data access speed
- an increase in storage capacity

Even though these caches are relatively small, usually measured in megabytes (MB), they are significantly faster than main memory (RAM).

The main purpose of cache memory is to store data that is expected to be accessed frequently and quickly, reducing the time the processor spends waiting for data from slower memory.

This concept relates closely to arrays. Arrays are often used to store cached data because they are memory-efficient and store elements in contiguous memory locations. This spatial locality allows the processor to load nearby elements efficiently, which aligns well with how cache systems operate. As a result, arrays often provide better cache performance compared to data structures like linked lists, whose elements are scattered across memory.

# Dynamic Arrays

Arrays in higher abstraction languages (like Python or Javascript) work differently than the ones from previous description given, which sometimes can be referred as *Static arrays*.

They are called dynamic because **Size** and **Type** don't need to be defined upfront.

For example in Python you can have a list having multiple types inside, and it is possible to extend the array in runtime:

~~~python
arr = [1, 2, "ABC", [1, 2]]
arr.append(1)
~~~

In memory the values are not allocated in a contiguous space in this kind of arrays. Instead, what is kept are pointers to the next space in memory where the next value is.

Also, the memory region is also different, in this case the allocation is in the **Heap region**.

It is possible to say that in those languages an array is closer to a linked list than to the classical definition of an array.

Putting **performance** in comparison (time comparison), Static arrays are the winners, but they loose in **flexibility** and easeness of usage. In security aspects, Static arrays can also be considered better, because the size is known upfront, they are less prone to memory leaks.
