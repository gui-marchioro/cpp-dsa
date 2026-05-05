# Binary Tree

A binary tree is a hierarchical data structure where each node has at most two children:

* **Left child**
* **Right child**

Each node stores:

* A value
* A reference to the left child
* A reference to the right child

When the tree follows the rule:

* values smaller than the current node go to the left
* values greater than or equal to the current node go to the right

it is specifically called a **Binary Search Tree (BST)**, which is what the implementation below represents.

---

## Time complexity

### Average case (balanced tree)

* Insert: **O(log n)**
* Search: **O(log n)**
* Delete: **O(log n)**

### Worst case (unbalanced tree)

* Insert: **O(n)**
* Search: **O(n)**
* Delete: **O(n)**

This happens when the tree becomes similar to a linked list.

---

## Space complexity

* Recursive operations: **O(log n)** average
* Worst case recursion depth: **O(n)**

---

## Common operations

### Insert

Traverse the tree comparing values:

* go left if the new value is smaller
* go right if the new value is greater or equal

Repeat until an empty position is found.

### Search

Start from the root:

* if value matches → found
* if smaller → search left
* if greater → search right

This avoids checking every node.

### Traversal

Common traversal strategies:

* **In-order** → Left → Root → Right
* **Pre-order** → Root → Left → Right
* **Post-order** → Left → Right → Root
* **Level-order** → Breadth-first traversal

For BSTs, **in-order traversal returns sorted values**.

---

## When to use

Binary trees are useful when:

* frequent searching is required
* sorted data access is important
* hierarchical relationships must be represented
* dynamic insertion and deletion are needed

Examples:

* file systems
* decision trees
* expression trees
* database indexing concepts
* search-heavy problems

---

## Sample implementation

~~~python
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self, val):
        if not self.root:
            self.root = TreeNode(val)
        else:
            self._insert_recursive(self.root, val)

    def _insert_recursive(self, node, val):
        if val < node.val:
            if node.left:
                self._insert_recursive(node.left, val)
            else:
                node.left = TreeNode(val)
        else:
            if node.right:
                self._insert_recursive(node.right, val)
            else:
                node.right = TreeNode(val)

    def search(self, val):
        return self._search_recursive(self.root, val)

    def _search_recursive(self, node, val):
        if not node:
            return False
        if node.val == val:
            return True
        if val < node.val:
            return self._search_recursive(node.left, val)
        return self._search_recursive(node.right, val)
~~~

# Tree Traversal

Tree traversal means visiting all nodes of the tree in a specific order.

In binary trees, the most common traversal strategies are:

* **Pre-order**
* **In-order**
* **Post-order**

These are depth-first traversal methods implemented recursively.

---

## Pre-order Traversal

### Order

**Root → Left → Right**

### How it works

1. Visit the current node
2. Traverse the left subtree
3. Traverse the right subtree

### Example

For this tree:

```text
       10
      /  \
     5    15
    / \     \
   2   7     20
```

Pre-order result:

```text
[10, 5, 2, 7, 15, 20]
```

### Common use cases

* Copying a tree
* Expression tree evaluation
* Serialization of tree structure

---

## In-order Traversal

### Order

**Left → Root → Right**

### How it works

1. Traverse the left subtree
2. Visit the current node
3. Traverse the right subtree

### Example

Using the same tree:

```text
[2, 5, 7, 10, 15, 20]
```

### Important note

In a **Binary Search Tree (BST)**, in-order traversal always returns values in **sorted order**.

This is one of the main advantages of BSTs.

### Common use cases

* Retrieving sorted values
* Validating BST structure

---

## Post-order Traversal

### Order

**Left → Right → Root**

### How it works

1. Traverse the left subtree
2. Traverse the right subtree
3. Visit the current node

### Example

```text
[2, 7, 5, 20, 15, 10]
```

### Common use cases

* Deleting a tree
* Releasing memory safely
* Evaluating dependency-based structures

---

## Time Complexity

For all traversal methods:

* Time complexity: **O(n)**

because every node is visited exactly once.

---

## Space Complexity

Recursive traversal uses the call stack:

* Average: **O(log n)**
* Worst case: **O(n)**

Worst case happens when the tree is completely unbalanced.

---

## Why recursion works well

Each subtree is itself a binary tree.

This makes traversal naturally recursive:

* solve left subtree
* solve right subtree
* combine according to traversal order

This is a classic recursive problem.

## Traversal Sample Implementation

~~~python
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


class BinaryTree:
    def __init__(self):
        self.root = None
    
    ...

    def preorder_traversal(self):
        result = []
        self._preorder_traversal(self.root, result)
        return result

    def _preorder_traversal(self, node, result):
        if node:
            result.append(node.val)
            self._preorder_traversal(node.left, result)
            self._preorder_traversal(node.right, result)

    def postorder_traversal(self):
        result = []
        self._postorder_traversal(self.root, result)
        return result

    def _postorder_traversal(self, node, result):
        if node:
            self._postorder_traversal(node.left, result)
            self._postorder_traversal(node.right, result)
            result.append(node.val)

    def inorder_traversal(self):
        result = []
        self._inorder_traversal(self.root, result)
        return result

    def _inorder_traversal(self, node, result):
        if node:
            self._inorder_traversal(node.left, result)
            result.append(node.val)
            self._inorder_traversal(node.right, result)
~~~

# Depth-First Search (DFS)

Depth-First Search (DFS) is a traversal and search technique where we explore one branch of the tree as deep as possible before backtracking.

Instead of visiting nodes level by level, DFS follows a path down to a leaf first, then returns to explore other branches.

The recursive implementation below performs a DFS search for a target value.

~~~python
    def dfs(self, data):
        return self._dfs_recursive(self.root, data)

    def _dfs_recursive(self, node, data):
        if node:
            print(node.val)
        if node is None:
            return False
        if node.val == data:
            return True
        if self._dfs_recursive(node.left, data):
            return True
        if self._dfs_recursive(node.right, data):
            return True
~~~

---

## How it works

Starting from the root:

1. Visit the current node
2. Check if the current value matches the target
3. Search recursively in the left subtree
4. If not found, search recursively in the right subtree

This follows a **Root → Left → Right** pattern, which is equivalent to **Pre-order DFS**.

---

## Example

For this tree:

```text id="4k8f2j"
       10
      /  \
     5    15
    / \     \
   2   7     20
```

Searching for:

```text id="s6m2n8"
dfs(7)
```

Visited order:

```text id="t9x4p1"
10 → 5 → 2 → 7
```

The search stops as soon as the value is found.

---

## Time Complexity

### Worst case

* **O(n)**

In the worst case, every node must be visited.

### Best case

* **O(1)**

If the target is found at the root.

---

## Space Complexity

Because the implementation is recursive:

* Average: **O(log n)**
* Worst case: **O(n)**

This depends on the height of the tree.

---

## DFS vs Tree Traversal

Traversal methods like:

* pre-order
* in-order
* post-order

are all forms of DFS because they go deep into one subtree before moving to another.

The difference is:

* traversal visits all nodes
* DFS search may stop early when the target is found

---

## When DFS is useful

DFS is commonly used for:

* searching values in trees
* path finding
* solving recursive tree problems
* checking connectivity in graphs
* backtracking problems

Examples:

* maze solving
* folder structure search
* dependency resolution
* graph traversal problems

## Breadth-First Search (BFS)

Breadth-First Search (BFS) is a traversal and search technique where nodes are explored level by level.

Instead of going deep into one branch first like DFS, BFS visits all nodes at the current depth before moving to the next level.

This is also called **Level-Order Traversal**.

The implementation below uses a **queue** to keep track of which nodes should be visited next.

~~~python
    def bfs(self, data):
        if self.root is None:
            return False
        queue = deque()
        queue.append(self.root)

        while queue:
            node = queue.popleft()
            print(node.val)
            if node.val == data:
                return True
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        return False
~~~

---

## How it works

Starting from the root:

1. Add the root node to the queue
2. Remove the first node from the queue
3. Check if it matches the target value
4. Add its left child to the queue
5. Add its right child to the queue
6. Repeat until the queue is empty or the value is found

Because a queue follows **First In, First Out (FIFO)** order, nodes are processed level by level.

---

## Example

For this tree:

```text id="w4m7k2"
       10
      /  \
     5    15
    / \     \
   2   7     20
```

Searching for:

```text id="n8p3c1"
bfs(7)
```

Visited order:

```text id="r5x2v9"
10 → 5 → 15 → 2 → 7
```

The search stops as soon as the value is found.

---

## Time Complexity

### Worst case

* **O(n)**

In the worst case, every node must be visited.

### Best case

* **O(1)**

If the target is found at the root.

---

## Space Complexity

BFS stores nodes in a queue:

* Average: **O(w)**

where **w** is the maximum width of the tree.

### Worst case

* **O(n)**

This happens when the last level contains many nodes.

This is often larger than DFS, which usually depends on tree height instead of width.

---

## BFS vs DFS

### BFS

* explores level by level
* uses a queue
* better for finding the shortest path in unweighted graphs
* useful when the target is likely close to the root

### DFS

* explores one branch deeply first
* usually uses recursion or a stack
* useful for recursive structure problems
* often uses less memory in wide trees

---

## When BFS is useful

BFS is commonly used for:

* shortest path problems (unweighted graphs)
* level-order traversal
* finding the closest matching node
* network broadcasting problems
* minimum-step problems

Examples:

* social network connections
* shortest moves in a puzzle
* nearest file or folder search
* tree level analysis

