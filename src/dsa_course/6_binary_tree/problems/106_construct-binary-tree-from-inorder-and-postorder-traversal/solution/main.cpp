#include <vector>

using namespace std;

/*  -- Used properties from postorder and inorder binary trees traversal
        - last elemenent from postorder is the root node
        - popping that element reveal information from a subtree
        - aplying this technique recursively to create the tree
    -- Time complexity: O(n log n)
        - divide and conquer
    -- Space complexity: O(n)
        - all tree elements need to be kept in memory

    -- Leet Code submission results:
        Runtime: 31 ms
        Beats: 5.10%

        Memory: 51.33 MB
        Beats: 5.05%
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty()) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder.back());
        postorder.pop_back();

        int rootIdx = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder.at(i) == root->val) {
                rootIdx = i;
                break;
            }
        }

        vector<int> inorderSubRight(inorder.begin() + rootIdx + 1, inorder.end());
        root->right = buildTree(inorderSubRight, postorder);
        vector<int> inorderSubLeft(inorder.begin(), inorder.begin() + rootIdx);
        root->left = buildTree(inorderSubLeft, postorder);
        return root;
    }
};


int main() {
    auto inorder = vector<int>{9,3,15,20,7};
    auto postorder = vector<int>{9,15,7,20,3};
    Solution sol;
    auto result = sol.buildTree(inorder, postorder);
    return 0;
}