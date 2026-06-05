# Bubble Sort

- Time Complexity
    - Best case (array/list already sorted): O(n)
        - e.g. | 1 | 2 | 3 | 4 | 5 |
    - Worst case (array/list in the inverse intended order): O(n^2)
        - e.g. | 5 | 4 | 3 | 2 | 1 |
- Space Complexity: O(1)
- Simplest sorting algorithm regarding its implementation and easeness of understanding
- Regarding time complexity it is probably the worst one
- It basically consists of two pointers traversing a list/array and swapping elements based in their intended order
- The greater elements are placed at the end of the list on each pass
- e.g. for a list | 5 | 4 | 3 | 2 | 1 |, having `l` and `r` as left and right pointer respectively
    ~~~
    1st pass
    | 5 | 4 | 3 | 2 | 1 |  
      l   r
    | 4 | 5 | 3 | 2 | 1 |  
          l   r
    | 4 | 3 | 5 | 2 | 1 |  
              l   r
    | 4 | 3 | 2 | 5 | 1 |  
                  l   r
    2nd pass
    | 4 | 3 | 2 | 1 | 5 |  
      l   r
    | 3 | 4 | 2 | 1 | 5 |  
          l   r
    | 3 | 2 | 4 | 1 | 5 |  
              l   r
    | 3 | 2 | 1 | 4 | 5 |  
                  l   r
    3d pass
    | 3 | 2 | 1 | 4 | 5 |  
      l   r
    ...
    ~~~

## Implementation

~~~python
def bubble_sort(arr):
    n = len(arr)
    is_sorted = True
    # traverse the entire list
    for i in range(n):
        # traverse the list considering the greater
        # elementis always placed in the end
        # (that's why it goes to (n - i))
        for j in range(0, n - i - 1):
            # swap elements when the order is incorrect
            if arr[j] > arr[j + 1]:
                is_sorted = False
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
        # optimization to not keep iterating if already sorted
        if is_sorted:
            return
~~~
