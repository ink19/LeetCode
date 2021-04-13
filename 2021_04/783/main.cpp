#include <vector>
#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int min_diff_value = 9999999;
  std::vector<int> tree_data;
  int min_find(TreeNode *root) {
    if (root->left != nullptr) {
      min_find(root->left);
    } 
    tree_data.push_back(root->val);
    if (root->right != nullptr) {
      min_find(root->right);
    }
    return 0;
  }
  int minDiffInBST(TreeNode *root) {
    min_find(root);
    for (int loop_i = 0; loop_i < tree_data.size() - 1; ++loop_i) {
      if (min_diff_value > tree_data[loop_i + 1] - tree_data[loop_i]) {
        min_diff_value = tree_data[loop_i + 1] - tree_data[loop_i];
      }
    }
    return min_diff_value;
  }
};