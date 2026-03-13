# Binary Search

- Search algorithm
- Only works if the items are already sorted
- Time complexity is O(log n)
- Space complexity is O(1)

## Practical Example

- Having the following array

    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 |

- We are searching for element **3**
- The idea is to start by looking in the middle of the list, and based in what number we get, eliminate one half of the list.

    | 1 | 2 | 3 | 4 | 5 | **6*** | 7 | 8 | 9 | 10 | 11 |

- 6 is greater than 3, then the right half can be discarded

    | 1 | 2 | 3 | 4 | 5 |

- Then we move the pointer to the middle of the new sublist, and do the same process until we find the item we are searching for

    | 1 | 2 | **3*** | 4 | 5 | 6 |

- When the desired item is found, we reach the end of the algorithm

## Aspects of performance

- The practical effect of O(log n) time complexity is that **every time we double the array size, we need just one more step to find the element**
- By using 3 pointers, one in the start of the array, one in the end, and one in the middle of those two we can move through the array without creating copies of the subarrays, this way optimizing memory efficiency

## Sample implementation

~~~python
def binary_search(nums, n):
    lo = 0
    hi = len(nums)
    steps = 0
    while lo < hi:
        steps += 1
    mid = int((lo + hi) / 2)

    if nums(mid) == n:
        print("step: ", steps)
        return mid
    elif nums(mid) < n:
        lo = mid + 1
    else:
        hi = mid
    return -1
~~~
