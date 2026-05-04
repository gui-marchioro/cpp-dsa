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

## Tree Traversal

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

