#include <iostream>
#include <string>

using namespace std;

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
  string tree2str(TreeNode *root) {
    if (root == nullptr) return "";
    string result = "";
    result += std::to_string(root->val);
    if (root->left == nullptr && root->right == nullptr) return result;
    result += "(";
    result += tree2str(root->left);
    result += ")";
    if (root->right != nullptr) {
      result += "(";
      result += tree2str(root->right);
      result += ")";
    }
    return result;
  }
};