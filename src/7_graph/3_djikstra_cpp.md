# Dijkstra’s Algorithm in C++

Dijkstra is used to find the **shortest path from one source node to all other nodes** in a **weighted graph with non-negative edge weights**.

The most common implementation in C++ uses:

* **Adjacency List** → to store the graph
* **Priority Queue (Min Heap)** → to always process the node with the smallest current distance

---

# Graph Representation

We usually store the graph like this:

```cpp
vector<vector<pair<int, int>>> graph;
```

Where:

```text
graph[u] = { {v, weight}, {v2, weight2} }
```

Meaning:

* `u → v` with cost `weight`

Example:

```cpp
graph[0] = { {1, 4}, {2, 1} };
```

means:

```text
0 → 1 (cost 4)
0 → 2 (cost 1)
```

---

# Relaxation Formula

dist[v] = \min(dist[v],\ dist[u] + w(u,v))

This is the heart of Dijkstra.

If going through node `u` gives a shorter path to `v`,
we update `dist[v]`.

---

# Full C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> dijkstra(int n, vector<vector<pair<int, int>>>& graph, int start) {
    // Distance array
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;

    // Min Heap: {distance, node}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > minHeap;

    minHeap.push({0, start});

    while (!minHeap.empty()) {
        int currentDist = minHeap.top().first;
        int node = minHeap.top().second;
        minHeap.pop();

        // Skip outdated entries
        if (currentDist > dist[node]) {
            continue;
        }

        // Explore neighbors
        for (auto& neighbor : graph[node]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;

            int newDist = currentDist + weight;

            if (newDist < dist[nextNode]) {
                dist[nextNode] = newDist;
                minHeap.push({newDist, nextNode});
            }
        }
    }

    return dist;
}

int main() {
    int n = 5; // number of nodes

    vector<vector<pair<int, int>>> graph(n);

    // Example graph:
    // 0 → 1 (4)
    // 0 → 2 (1)
    // 2 → 1 (2)
    // 1 → 3 (1)
    // 2 → 3 (5)
    // 3 → 4 (3)

    graph[0].push_back({1, 4});
    graph[0].push_back({2, 1});
    graph[2].push_back({1, 2});
    graph[1].push_back({3, 1});
    graph[2].push_back({3, 5});
    graph[3].push_back({4, 3});

    int start = 0;

    vector<int> shortest = dijkstra(n, graph, start);

    cout << "Shortest distances from node " << start << ":\n";

    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": " << shortest[i] << endl;
    }

    return 0;
}
```

---

# Why `greater<pair<int, int>>`?

Normally:

```cpp
priority_queue<int>
```

is a **max heap**

but Dijkstra needs:

# Min Heap

So we use:

```cpp
greater<pair<int, int>>
```

to make the smallest distance come first.

---

# Important Optimization

This line is very important:

```cpp
if (currentDist > dist[node]) continue;
```

Why?

Because the same node may enter the heap multiple times.

We only process the most recent shortest one.

This avoids unnecessary work.

---

# Time Complexity

```text
O((V + E) log V)
```

Where:

* `V` = number of vertices
* `E` = number of edges

Very efficient for sparse graphs.

---
