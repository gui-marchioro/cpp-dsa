# Big O Notation

Tells about scalability, but not necessarily performance.
Performance depends on an asymptotic analysis.

## Time Complexity

How much time or iterations are needed.

## Space Complexity

How much memory is needed.

# Notations

We always care for the worst case scenario when analyzing Big O.

## O(1)

- Constant time
- Constant memory
- e.g.
    - access an element via an index inside an array
    - access an element in a dictionary using a key

## O(log n)
- Complexity increases logaritimically as the input increases
- e.g.
    - binary search (time complexity)

## O(n)

- Complexity increases as the input increases
- e.g.
    - iterate over elements from an array

## O(nlog n)

- e.g.
    - Sorting (except bubble sort)
    - Divide and conquer algorithms

## O(n^2)

- e.g.
    - bubble sort
    - nested loop algorithm

# Rarely Covered Notations

## O(2^n)

## O(sqrt n)

- e.g.
    - exponential search

## O(N!)

- e.g.
    - a bad factorial algorithm
