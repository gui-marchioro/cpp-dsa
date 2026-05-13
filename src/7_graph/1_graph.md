# Graphs

Graphs are one of the most important data structures in coding interviews and LeetCode problems because many real-world relationships can be modeled as connections between objects.

Examples:

* Cities connected by roads
* People connected by friendships
* Courses connected by prerequisites
* Computers connected in a network
* Cells connected in a matrix (grid problems)

---

# What is a Graph?

A **graph** is a collection of:

* **Vertices (Nodes)** → the objects
* **Edges** → the connections between them

Example:

```text
A --- B
|     |
C --- D
```

Here:

* Nodes: A, B, C, D
* Edges: A-B, A-C, B-D, C-D

---

# Types of Graphs

---

## 1. Undirected Graph

Connections go both ways.

```text
A --- B
```

means:

```text
A ↔ B
```

Example:

* Friendships
* Roads between cities

---

## 2. Directed Graph (Digraph)

Connections have direction.

```text
A → B
```

means A points to B, but not necessarily the opposite.

Example:

* Course prerequisites
* Dependencies
* Twitter follows

---

## 3. Weighted Graph

Edges contain values (cost, distance, time).

```text
A --5--> B
```

Example:

* Shortest path problems

---

## 4. Cyclic vs Acyclic

### Cyclic

Contains loops.

```text
A → B → C → A
```

### Acyclic

No loops.

Important:
A Directed Acyclic Graph is called a **DAG**

Very common in:

* Topological Sort
* Course Schedule problems

---

# Graph Representation

---

## 1. Adjacency List (Most Common)

```python
graph = {
    "A": ["B", "C"],
    "B": ["A", "D"],
    "C": ["A"],
    "D": ["B"]
}

A - B
|   |
C   D
```

### Advantages

* Efficient
* Most common in interviews
* Best for sparse graphs

---

## 2. Adjacency Matrix

```python
[
 [0,1,1,0],
 [1,0,0,1],
 [1,0,0,0],
 [0,1,0,0]
]

A - B
|   |
C   D
```

### Advantages

* Easy edge lookup

### Disadvantages

* Uses more memory

---

# Core Graph Traversal Algorithms

---

# 1. DFS — Depth First Search

Explore as deep as possible first.

Usually implemented with:

* Recursion
* Stack

---

## DFS Template

```python
def dfs(node, visited):
    if node in visited:
        return

    visited.add(node)

    for neighbor in graph[node]:
        dfs(neighbor, visited)
```

---

## Used For

* Connected components
* Cycle detection
* Backtracking
* Topological sort
* Islands problems
* Clone Graph
* Path existence

---

# 2. BFS — Breadth First Search

Explore level by level.

Usually implemented with:

* Queue

---

## BFS Template

```python
from collections import deque

def bfs(start):
    queue = deque([start])
    visited = set([start])

    while queue:
        node = queue.popleft()

        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)
```

---

## Used For

* Shortest path in unweighted graphs
* Minimum number of steps
* Level-order traversal
* Word Ladder
* Rotting Oranges
* Binary Tree level traversal

---
