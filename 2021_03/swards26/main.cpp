#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool isSubStructure2(TreeNode *A, TreeNode *B) {
    if (B == NULL) return true;
    if (A == NULL) return false;

    if (A->val != B->val) return false;

    if (!isSubStructure2(A->left, B->left)) return false;
    if (!isSubStructure2(A->right, B->right)) return false;
    return true;
  }
  bool isSubStructure(TreeNode *A, TreeNode *B) {
    if (B == NULL || A == NULL) return false;
    if (A->val == B->val && isSubStructure2(A, B)) return true;
    if (isSubStructure(A->left, B)) return true;
    if (isSubStructure(A->right, B)) return true;
    return false;
  }
};