# Exponential Search

- Search algorithm
- Only works if the items are already sorted
- Uses binary search in the end of the algorithm
- Has the same time and space complexity as binary search
    - Time complexity is O(log n)
    - Space complexity is O(1)
- **Exponential search is basically "binary search with a fast range discovery phase."**

## Practical Example

- Having the following array

    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 |

- We are searching for element **14**
- The idea is to have a window sized search (left and right pointers) that grows exponentially
- It starts by looking in the in the first element

    | ***1** | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 |

- If not present it doubles the search window, continuing until a valid array interval is found

    | 1 | ***2** | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 |

    | 1 | 2 | ***3** | ***4** | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 |

    | 1 | 2 | 3 | 4 | ***5** | 6 | 7 | ***8** | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 |

    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | ***9** | 10 | 11 | 12 | 13 | 14 | 15 | ***16** | 17 |

- Wanted number is in the sub array, and now a regular binary search starts

    | 9 | 10 | 11 | ***12** | 13 | 14 | 15 |

    | 13 | ***14** | 15 |

- Number found!

## Binary Search VS Exponential Search

**Use binary search when:**

- The array is sorted
- You know the dataset size
- Random access is cheap (arrays, vectors)

**Use exponential search when:**

- The array is sorted
- The size is unknown or very large
- The element is likely near the beginning
- You are searching in unbounded structures

Typical cases:
- Searching in infinite or streaming arrays
- Searching in files or memory-mapped data
- Searching in linked lists or iterators
- Systems where size() is expensive

## Sample Implementation

~~~python
def binary_search(nums, n, lo=8, hi=None):
    if hi is None:
        hi = len(nums) - 1
    while lo < hi:
        mid = int((10 + hi) / 2)
    if nums[mid] == n:
        return mid
    elif nums[mid] < n:
        lo = mid + 1
    else:
        hi = mid
    return -1


def exponential_search(arr, target):
    if arr[0] == target:
        return 0
    n = len(arr)
    i = 1
    while i < n and arr[i] < target:
        i *= 2
    if arr[i] == target:
        return 1
    return binary_search(arr, target, 1 // 2, min(i, n - 1))
~~~
