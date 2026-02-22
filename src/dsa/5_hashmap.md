# Hashmap

- Best analogy is to think of a Hashmap as being a **dictionary** where **values** are mapped to specific **keys**
- e.g. in Python
    ~~~python
    hashmap = {
        "key1": "val1"
        "key2": "val2"
        ...
    }
    ~~~
- Data access, addition, update and removal are done **O(1)** time complexity
- As a counter effect of such good quality, space complexity is **O(n)**. (almost) All elements should be kept in memory
- The magic of such efficiency resides in the **hash function** which ideally assign an unique number to a given key
- The calculated number under the hood becomes the index from an array where the value is stored
- When the hashmap is instantiated the programming language normally creates a big array to store all the possible values
- Because it is not always possible to make sure an unique number will be assigned to a given key or that there are space in the current array, a collision might occur
- To deal with it the array slot where the number will point will not only contain a simple value but a linked list containing all key values mapped to that index number
- This way it is possible to think of a linked list being mapped in memory to an array of linked lists

- e.g.

    | 0 |

    | 1 |

    | 2 | -> | 2.1 | -> | 2.2 |

    | 3 |

## Hash function

- Can be implemented using cryptography algorithms like SHA or MD5

## Load Factor

- The load factor measures how full a hash table is
The load factor directly affects performance.
- Low load factor (e.g., 0.5)
    - Fewer collisions
    - Faster lookups
    - More memory used
- High load factor (e.g., 1.5)
    - More collisions
    - Slower lookups
    - Better memory usage
- Most language implementations resize when load factor~= 0.7. It’s a practical balance between speed and memory.

## Collisions

- A collision happens when two different keys produce the same array/bucket index
- Collisions are inevitable because, even though the number of possible keys is huge, the number of buckets is limited.
