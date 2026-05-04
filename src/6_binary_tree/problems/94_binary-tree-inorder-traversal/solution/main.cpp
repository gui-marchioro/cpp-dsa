#include <vector>

using namespace std;


/*  -- Binary Tree In Order Traversal
        - given a root node
        - traverse the tree using In Order strategy
    -- Time complexity: O(n)
        - all TreeNodes are visited at least once
    -- Space complexity: average O(log n), worst O(n)
        - In a completely unbalanced tree all nodes would be kept in memory

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 10.89 MB
        Beats: 65.39%
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
    void inorderTravRecursive(TreeNode* node, vector<int> &traversal) {
        if (!node) {
            return;
        }

        inorderTravRecursive(node->left, traversal);
        traversal.push_back(node->val);
        inorderTravRecursive(node->right, traversal);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        auto result = vector<int>{};
        inorderTravRecursive(root, result);
        return result;
    }
};



int main() {
    Solution sol;
    auto C1L = TreeNode{3};
    auto rootR = TreeNode{0, &C1L, nullptr};
    auto root = TreeNode{1, nullptr, &rootR};
    auto result = sol.inorderTraversal(&root);

    return 0;
}
