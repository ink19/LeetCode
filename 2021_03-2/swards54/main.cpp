#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool mKthLargest(TreeNode *root, int &k, int &out) {
    if (root == NULL) return false;
    if (mKthLargest(root->left, k, out)) {
      return true;
    }
    if (k == 1) {
      out = root->val;
      return true;
    }
    k--;
    return mKthLargest(root->right, k, out);
  }
  int kthLargest(TreeNode *root, int k) {
    int out_data = 0;
    mKthLargest(root, k, out_data);
    return out_data;
  }
};