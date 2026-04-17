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