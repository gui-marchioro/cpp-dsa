from collections import deque


"""  -- Graph DFS traversal
        - given a root node
        - have a hashmap containing val as a key and Node instance
        - traverse nodes using DFS
            - returning cloned node if exists
            - or creating new clone if not
    -- Time complexity: O(n)
        - all nodes are visited at least once
    -- Space complexity: O(n)
        - all nodes are saved in memory

    -- Leet Code submission results:
        Runtime: 50 ms
        Beats: 54.85%

        Memory: 19.66 MB
        Beats: 85.76%
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
        def dfs(node):
            if node.val in clones:
                return clones[node.val]
            clone = Node(node.val)
            clones[node.val] = clone
            for n in node.neighbors:
                clone.neighbors.append(dfs(n))
            return clone

        return dfs(node)
