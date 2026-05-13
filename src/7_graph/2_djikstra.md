# Dijkstra’s Algorithm

Dijkstra’s Algorithm is used to find the **shortest path from one source node to all other nodes** in a **weighted graph with non-negative weights**.

It is one of the most important graph algorithms for LeetCode and coding interviews.

---

# When to Use It

Use Dijkstra when:

* The graph is **weighted**
* You need the **minimum cost / shortest distance**
* Edge weights are **non-negative**

Examples:

* shortest travel time
* minimum network delay
* cheapest route (without negative costs)

---

# Key Idea

Instead of exploring level-by-level like BFS:

```text id="j3znf4"
BFS → shortest path in unweighted graph
```

Dijkstra always expands:

```text id="b86g9g"
the node with the smallest known distance first
```

This guarantees correctness when weights are non-negative.

---

# Example

```text id="m7c9k8"
A --1--> B
A --4--> C
B --2--> C
B --5--> D
C --1--> D
```

Goal:
Find shortest path from A to all nodes.

---

# Step-by-Step

Start:

```text id="h9w2pl"
distance[A] = 0
distance[others] = infinity
```

Priority Queue (Min Heap):

```text id="9x0rqs"
[(0, A)]
```

---

## Process A

From A:

* B = 1
* C = 4

Update:

```text id="f1v7ne"
dist[B] = 1
dist[C] = 4
```

Heap:

```text id="w5u3ka"
[(1, B), (4, C)]
```

---

## Process B

From B:

* C = min(4, 1+2) = 3
* D = 1+5 = 6

Update:

```text id="n2d8zo"
dist[C] = 3
dist[D] = 6
```

Heap:

```text id="c6l1rm"
[(3, C), (4, C), (6, D)]
```

---

## Process C

From C:

* D = min(6, 3+1) = 4

Update:

```text id="g4s8yt"
dist[D] = 4
```

Final:

```text id="gx3hfv"
A = 0
B = 1
C = 3
D = 4
```

---

# Visual Formula

~~~
dist[v] = min(dist[v], dist[u] + weight(u,v))
~~~

This is called **relaxation**.

Meaning:

> If going through `u` gives a shorter path to `v`,
> update it.

---

# Python Template (Heap)

```python id="3k2hdf"
import heapq

def dijkstra(graph, start):
    # graph = {
    #   node: [(neighbor, weight)]
    # }

    minHeap = [(0, start)]  # (distance, node)
    distances = {node: float("inf") for node in graph}
    distances[start] = 0

    while minHeap:
        currentDist, node = heapq.heappop(minHeap)

        # Skip outdated entries
        if currentDist > distances[node]:
            continue

        for neighbor, weight in graph[node]:
            newDist = currentDist + weight

            if newDist < distances[neighbor]:
                distances[neighbor] = newDist
                heapq.heappush(minHeap, (newDist, neighbor))

    return distances
```

---

# Why Priority Queue?

Because we always need:

```text id="bfr6qe"
the node with minimum distance
```

Efficiently.

Using:

```python id="j9m4cx"
heapq
```

makes this:

```text id="rl1zqf"
O(log V)
```

per operation.

---

# Time Complexity

Using Min Heap:

```text id="k8t5vm"
O((V + E) log V)
```

Where:

* V = vertices
* E = edges

Very efficient for sparse graphs.

---

# Important Limitation

## Dijkstra DOES NOT work with:

# Negative weights

Example:

```text id="v3e6ah"
A → B = 5
A → C = 2
B → C = -10
```

This breaks Dijkstra’s guarantee.

For negative weights use:

# Bellman-Ford

instead.

---

# Common LeetCode Pattern Recognition

If problem says:

* minimum cost
* shortest time
* least effort
* minimum delay
* weighted graph

Think:

# Dijkstra

especially if weights are positive.

---

# Dijkstra vs BFS

| BFS              | Dijkstra             |
| ---------------- | -------------------- |
| Unweighted graph | Weighted graph       |
| Queue            | Min Heap             |
| Equal step cost  | Different edge costs |
| O(V + E)         | O((V+E) log V)       |

---
