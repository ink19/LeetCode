#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int max_dep = 0;
  int MmaxDepth(TreeNode *root, int depth) {
    if (root == NULL) {
      if (max_dep < depth) {
        max_dep = depth;
      }
      return 0;
    }
    MmaxDepth(root->right, depth + 1);
    MmaxDepth(root->left, depth + 1);
    return 0;
  }
  int maxDepth(TreeNode *root) {
    MmaxDepth(root, 1);
    return max_dep - 1;
  }
};