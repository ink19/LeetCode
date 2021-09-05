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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        return hasPathSum1(root, targetSum);
    }

    bool hasPathSum1(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        } 

        targetSum = targetSum - root->val;
        if (root->right == nullptr && root->left == nullptr) {
            if (targetSum == 0) return true;
            return false;
        }

        if (hasPathSum1(root->right, targetSum)) {
            return true;
        }

        if (hasPathSum1(root->left, targetSum)) {
            return true;
        }

        return false;
    }
};