#include <vector>
#include <iostream>
#include <limits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int min_depth = std::numeric_limits<int>::max();
    int minDepth(TreeNode* root, int depth) {
        if (depth >= min_depth) return 0;
        if (root->left == NULL && root->right == NULL) {
            if (depth < min_depth) min_depth = depth;
            return 0;
        }
        if (root->left != NULL) {
            minDepth(root->left, depth + 1);
        }
        if (root->right != NULL) {
            minDepth(root->right, depth + 1);
        }
        return 0;
    }
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        minDepth(root, 1);
        return min_depth;
    }
};