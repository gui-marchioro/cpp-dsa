from collections import deque


"""  -- Graph BFS traversal
        - given a root node
        - have a hashmap containing val as a key and Node instance
        - traverse nodes using BFS
            - add unvisited nodes to a queue
            - traverse neighbors, cloning if not yet, and linking clones
    -- Time complexity: O(n)
        - all nodes are visited at least once
    -- Space complexity: O(n)
        - all nodes are saved in memory

    -- Leet Code submission results:
        Runtime: 44 ms
        Beats: 88.09%

        Memory: 19.86 MB
        Beats: 18.13%
"""


# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        clones = {}
        q = deque()
        # bfs
        q.append(node)
        while(q):
            curr_node = q.pop()
            if not curr_node.val in clones:
                clone = Node(curr_node.val)
                clones[curr_node.val] = clone
            else:
                clone = clones[curr_node.val]
            for n in curr_node.neighbors:
                if not n.val in clones:
                    neigh_clone = Node(n.val)
                    clones[n.val] = neigh_clone
                    q.append(n)
                else:
                    neigh_clone = clones[n.val]
                clone.neighbors.append(neigh_clone)
        return clones[1]
