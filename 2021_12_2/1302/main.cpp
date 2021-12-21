#include <iostream>
#include <vector>

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
  int max_depth = -1;
  int sum = 0;
  int dfs(TreeNode *root, int now_depth) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) {
      if (now_depth > max_depth) {
        max_depth = now_depth;
        sum = root->val;
      } else if (now_depth == max_depth) {
        sum += root->val;
      }
      return 0;
    }
    dfs(root->right, now_depth + 1);
    dfs(root->left, now_depth + 1);
    return 0;
  }
  int deepestLeavesSum(TreeNode *root) {
    dfs(root, 0);
    return this->sum;
  }
};