


class TreeNode {
public:
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {};
private:
    int val;
    TreeNode* left;
    TreeNode* right;
};


class BinaryTree
{
private:
    TreeNode* root;
public:
    BinaryTree() : root(nullptr) {};
    BinaryTree(TreeNode* root) : root(root) {};
    ~BinaryTree() = default;

    // Could have, Search, Traverse, and other methods
};
