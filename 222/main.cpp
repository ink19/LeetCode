#include <string>
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        int result = 0;
        if (root != nullptr) result += 1;
        else return result;

        result += countNodes(root->left);
        result += countNodes(root->right);
        return result; 
    }
};