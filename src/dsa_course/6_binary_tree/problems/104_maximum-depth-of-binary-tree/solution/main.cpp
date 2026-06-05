#include <queue>

using namespace std;

/*  -- Used BFS algorithm
        - traverse entire tree level by level
        - each level increses tree depth by 1
    -- Time complexity: O(n)
        - all nodes are iterated
    -- Space complexity: O(n)
        - all tree elements need to be kept in the call stack in the worst case

    -- Leet Code submission results:
        Runtime: 8 ms
        Beats: 0.29%

        Memory: 19.18 MB
        Beats: 13.23%
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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int depth = 0;
        auto q = queue<TreeNode*>{};
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            depth++;
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        return depth;
    }
};


int main() {
    Solution sol;
    /* auto rll = TreeNode{4};
    auto rlr = TreeNode{5};
    auto rl = TreeNode{2, &rll, &rlr};
    auto rr = TreeNode{3};
    auto root = TreeNode{1, &rl, &rr};
    auto result = sol.maxDepth(&root); */
    auto rll = TreeNode{4};
    auto rl = TreeNode{2, &rll, nullptr};
    auto rrr = TreeNode{5};
    auto rr = TreeNode{3, nullptr, &rrr};
    auto root = TreeNode{1, &rl, &rr};
    auto result = sol.maxDepth(&root);
    return 0;
}
