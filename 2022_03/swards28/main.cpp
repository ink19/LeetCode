#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSame(TreeNode *one_tree, TreeNode *other_tree) {
      if (one_tree == NULL && other_tree == NULL) return true;
      if (one_tree == NULL || other_tree == NULL) return false;

      if (one_tree->val != other_tree->val) return false;

      if (!isSame(one_tree->left, other_tree->right)) return false;
      if (!isSame(one_tree->right, other_tree->left)) return false;
      return true;
    }
    bool isSymmetric(TreeNode* root) {
      if (root == NULL) return true;
      return isSame(root->right, root->left);
    }
};