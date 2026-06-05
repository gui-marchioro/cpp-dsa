#include <vector>
#include <queue>

using namespace std;

/*  -- Used BFS algorithm
        - on each tree level an array is created containing node values
    -- Time complexity: O(n)
        - all nodes are iterated
    -- Space complexity: O(n)
        - all tree elements need to be kept in memory

    -- Leet Code submission results:
        Runtime: 1 ms
        Beats: 40.01%

        Memory: 17.12 MB

        Beats: 43.97%
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result = vector<vector<int>>{};
        if (!root) {
            return result;
        }

        auto q = queue<TreeNode*>{};
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            auto level = vector<int>{};
            for (int i = 0; i < levelSize; i++) {
                auto n = q.front();
                q.pop();

                level.push_back(n->val);

                if (n->left) {
                    q.push(n->left);
                }
                if (n->right) {
                    q.push(n->right);
                }
            }
            result.push_back(level);
        }
        return result;
    }
};


int main() {
    auto rrl = TreeNode{15};
    auto rrr = TreeNode{7};
    auto rr = TreeNode{20, &rrl, &rrr};
    auto rl = TreeNode{9};
    auto root = TreeNode{3, &rl, &rr};
    Solution sol;

    auto result = sol.levelOrder(&root);
}
