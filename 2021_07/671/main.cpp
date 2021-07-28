#include <iostream>
#include <stack>
#include <vector>
#include <queue>

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
    int findSecondMinimumValue(TreeNode* root) {
        int result = -1;
        std::queue<TreeNode *> loop_stack;
        loop_stack.push(root);
        while (!loop_stack.empty()) {
            auto temp_node = loop_stack.front();
            loop_stack.pop();
            if (temp_node->left == nullptr) continue;
            if (temp_node->left->val > temp_node->val && (result == -1 || result > temp_node->left->val)) {
                result = temp_node->left->val;
            }
            if (temp_node->right->val > temp_node->val && (result == -1 || result > temp_node->right->val)) {
                result = temp_node->right->val;
            }
            loop_stack.push(temp_node->left);
            loop_stack.push(temp_node->right);
        }
        return result;
    }
};