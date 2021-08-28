#include <iostream>

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
    bool isSame(TreeNode *root, int a) {
        if (root == nullptr) return true;
        if (root->val != a) return false;
        if (isSame(root->left, a) == false) return false;
        if (isSame(root->right, a) == false) return false;
        return true;
    }
    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr) return true;
        return isSame(root, root->val);
    }
};