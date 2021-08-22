#include <iostream>
#include <vector>

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
    int result = 0;
    int dfs(TreeNode *node, bool is_left) {
        if (node->left == nullptr && node->right == nullptr && is_left) {
            result += node->val;
        }
        if (node->left != nullptr) {
            dfs(node->left, true);
        }
        if (node->right != nullptr) {
            dfs(node->right, false);
        }
        return 0;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root, false);
        return result;
    }
};