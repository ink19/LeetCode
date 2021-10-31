#include <algorithm>
#include <cmath>
#include <iostream>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return bool布尔型
     */
    bool getDep(TreeNode *root, int &dep) {
        if (root == nullptr) {
            dep = 0;
            return true;
        }
        int left_dep = 0;
        if (!getDep(root->left, left_dep)) {
            return false;
        }

        int right_dep = 0;
        if (!getDep(root->right, right_dep)) {
            return false;
        }

        dep = std::max({right_dep, left_dep}) + 1;
        if (std::abs(right_dep - left_dep) <= 1) {
            return true;
        }
        return false;
    }

    bool isBalanced(TreeNode* root) {
        int dep = 0;
        return getDep(root, dep);
    }
};

int main() {
    TreeNode *a = new TreeNode();
    a->val = 1;
    a->right = new TreeNode();
    a->right->val = 2;
    a->right->right = new TreeNode();
    a->right->right->val = 2;
    std::cout << Solution().isBalanced(a) << std::endl;
}