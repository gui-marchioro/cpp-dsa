

using namespace std;


/*  -- Used DFS strategy to find leaf nodes on a binary tree
        - when leaft is found, compare the targetSum to the current one
    -- Time complexity: O(n)
        - could lead to check all nodes to see if the sum is found
    -- Space complexity: O(n)
        - all tree elements could be kept in memory

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 21.37 MB
        Beats: 95.12%
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasPathSumRecursive(root, targetSum, 0);
    }
private:
    bool hasPathSumRecursive(TreeNode* node, int targetSum, int currentSum) {
        if (!node) {
            return false;
        }
        currentSum += node->val;
        if (!node->left && !node->right) {
            // leaf node found
            if (targetSum == currentSum) {
                return true;
            }
        }
        // base case
        return (hasPathSumRecursive(node->left, targetSum, currentSum) || 
                hasPathSumRecursive(node->right, targetSum, currentSum));
    }
};


int main() {
    Solution sol;
    auto rl = TreeNode{2};
    auto root = TreeNode{1, &rl, nullptr};
    bool result = sol.hasPathSum(&root, 1);
}