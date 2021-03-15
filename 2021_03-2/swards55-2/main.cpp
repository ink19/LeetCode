#include <vector>
#include <algorithm>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool result = true;
  int MmaxDepth(TreeNode *root, int depth) {
    if (!result) return 0;
    if (root == NULL) {
      return depth;
    }
    result = std::abs(MmaxDepth(root->right, depth + 1) - MmaxDepth(root->left, depth + 1)) <= 1;
    return std::max(MmaxDepth(root->right, depth + 1) , MmaxDepth(root->left, depth + 1));
  }

  bool isBalanced(TreeNode *root) {
    if (root == NULL) return true;
    MmaxDepth(root, 1);
    return result;
  }
};