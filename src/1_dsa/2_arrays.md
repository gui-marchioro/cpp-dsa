# Array

- Bytes queued in contiguous spaces in memory
- Size is defined upfront
- Type is defined upfront
- Elements are accessed using its index (position) inside the array
- Accessing and updating an element inside the array has **O(1)** complexity


## Memory

- Bytes are allocated queued in contiguous spaces in memory
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


## Arrays in higher abstraction languages

*The definition here does not apply for higher level abstraction languages (Python, Javascript).*

For example in Python you can have a list having multiple types inside, and it is possible to extend the array in runtime:

~~~python
arr = [1, 2, "ABC", [1, 2]]
arr.append(1)
~~~

In memory this kind of array the values are not allocated in a contiguous space. Instead, what is kept are pointers to the next space in memory where the next value is. 

It is possible to say that in those languages an array is closer to a linked list than to the classical definition of an array.
