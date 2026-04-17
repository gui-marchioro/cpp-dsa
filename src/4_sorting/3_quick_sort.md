# Quick Sort

- Time complexity
    - Best and average: n log(n)
    - Worst: n^2
- Space complexity
    - Best and average: log(n)
    - Worst: n
- Divide and conquer algorithm

## How it works?

- Given an array
~~~
| 7 | 1 | 3 | 5 | 2 | 4 | 8 | 9 | 0 |
~~~
- 1st step is to choose a pivot
- This step is very important and directly influences how optimized in terms of time and space complexity the algorithm will perform
- In this example lets arbitrarily choose number `5` as our pivot
- The pivot is withdrawn from its original position and placed in the end of the array
~~~
| 7 | 1 | 3 | 2 | 4 | 8 | 9 | 0 |   | 5 |
~~~
-  The goal is to find the right place for the choosen number, having on its left all lower numbers, and in the right all the greater ones
- That is done by using two pointers, `l` and `r`
- In  the 2nd step the array is traversed from left to right
- If a greater number is in the left pointer, elements are swaped
- this continues while at least one of the elements is lower than the pivot
~~~
  l   r
| 7 | 1 | 3 | 2 | 4 | 8 | 9 | 0 |   | 5 |

      l   r
| 1 | 7 | 3 | 2 | 4 | 8 | 9 | 0 |   | 5 |

          l   r
| 1 | 3 | 7 | 2 | 4 | 8 | 9 | 0 |   | 5 |

              l   r
| 1 | 3 | 2 | 7 | 4 | 8 | 9 | 0 |   | 5 |

                  l   r
| 1 | 3 | 2 | 4 | 7 | 8 | 9 | 0 |   | 5 |
~~~  

- If two numbers greater than the pivot are found, than only the right pointer starts to move, and checks for any other number below the pivot

~~~
                  l       r
| 1 | 3 | 2 | 4 | 7 | 8 | 9 | 0 |   | 5 |

                  l           r
| 1 | 3 | 2 | 4 | 7 | 8 | 9 | 0 |   | 5 |
~~~
- If a smaller number is found, it is swaped, and left pointer moves to the right
~~~
                      l       r
| 1 | 3 | 2 | 4 | 0 | 8 | 9 | 7 |   | 5 |
~~~
- Right pointer continues moving until it reaches the pivot
~~~
                      l               r
| 1 | 3 | 2 | 4 | 0 | 8 | 9 | 7 |   | 5 |
~~~
- At this point the pivot is placed in the left side from the left pointer
~~~
| 1 | 3 | 2 | 4 | 0 |  | 5 |  | 8 | 9 | 7 |
~~~
- That done, everything on the left is smaller than the pivot, and the opposite is true for the right side elements
- After this step, the algorithm is reapplied in the two groups around the pivot, by choosing new pivots for the subarrays
- For example for the right subarray choosing `8` as the pivot (which is the best option in this case)
~~~
| 8 | 9 | 7 |

  l   r
| 9 | 7 |  | 8 |

      l      r
| 7 | 9 |  | 8 |

          l   r
| 7 | 8 | 9 |
~~~
- In this scenario, given the length of the subarray, the right side is already sorted
- For the left subarray, `3` is the pivot choosen (again the best option)
~~~
| 1 | 3 | 2 | 4 | 0 |

  l   r
| 1 | 2 | 4 | 0 |   | 3 |

      l   r
| 1 | 2 | 4 | 0 |   | 3 |

          l   r
| 1 | 2 | 4 | 0 |   | 3 |

              l       r
| 1 | 2 | 0 | 4 |   | 3 |

                        l   r
| 1 | 2 | 0 |  | 3 |  | 4 |
~~~
- Now just one subarray is left for sorting
- Let's say now `0` is picked (in this case not a good pivot option)
~~~
| 1 | 2 | 0 |

  l   r
| 1 | 2 |  | 0 |

  l          r
| 1 | 2 |  | 0 |

         l       r
| 0 |  | 1 | 2 |
~~~
- A last sort would be called in the `| 1 | 2 |` subarray
- To finish the algorithm the stack call is traversed back and all the subarrays are placed in their correct positions

## Sample Implementation

The explanation above uses a **two-pointer partition strategy** (similar to *Hoare partition scheme*), where:

* Two pointers (`l` and `r`) move toward each other
* Elements are swapped when they are on the wrong side of the pivot
* The pivot is placed after the pointers meet

However, the implementation below uses a different approach called the **Lomuto partition scheme**.

~~~ python
def quicksort(arr):
    def partition(low, high):
        pivot = arr[high]
        i = low - 1
        for j in range(low, high):
            if arr[j] <= pivot:
                i += 1
                arr[i], arr[j] = arr[j], arr[i]
        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        return i + 1

    def quicksort_recursive(low, high):
        if low < high:
            pi = partition(low, high)
            quicksort_recursive(low, pi - 1)
            quicksort_recursive(pi + 1, high)

    quicksort_recursive(0, len(arr) - 1)
    return arr


test_array = [10, 7, 8, 9, 1, 5]
print("Unsorted array:", test_array)
sorted_array = quicksort(test_array)
print("Sorted array:", sorted_array)
~~~

### Key differences:

* Instead of two pointers, it uses:

  * `j`: scans the array from left to right
  * `i`: marks the boundary of elements smaller than or equal to the pivot
* Elements are not swapped in pairs from both ends
* The array is partitioned in a **single pass**
* The pivot is always chosen as the **last element**
* At the end, the pivot is swapped into its correct position (`i + 1`)

### Intuition of this implementation:

* Everything from `low` to `i` is ≤ pivot
* Everything from `i+1` to `j` is > pivot
* As `j` moves, the "≤ pivot" region grows

### Why this matters

Both approaches are correct and widely used, but:

* **Lomuto** is simpler to understand and implement
* **Hoare-style** is usually more efficient (fewer swaps)
