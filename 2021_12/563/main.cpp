#include <iostream>
#include <vector>
#include <tuple>

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
  std::tuple<int, int> dfs(TreeNode *root) {
    if (root == nullptr) return {0, 0};
    int left_sum = 0, left_diff = 0;
    int right_sum = 0, right_diff = 0;
    std::tie(left_sum, left_diff) = dfs(root->left);
    std::tie(right_sum, right_diff) = dfs(root->right);
    return {left_sum + right_sum + root->val, right_diff + left_diff + std::abs(right_sum - left_sum)};
  }
  int findTilt(TreeNode *root) {
    auto re = dfs(root);
    return std::get<1>(re);
  }
};