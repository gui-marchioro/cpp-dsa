
/*  -- Used DFS algorithm
        - traverse entire tree comparing each node
        - returns false immeadiately if any node is different
        - returns true otherwise
    -- Time complexity: O(n)
        - all nodes are iterated
    -- Space complexity: O(n)
        - all tree elements need to be kept in the call stack in the worst case

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 12.98 MB

        Beats: 12.59%
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        else if (!p || !q) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
