#include <iostream>
#include <vector>
#include <stack>
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
  vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> result;
    if (root == nullptr) return result;
    std::stack<TreeNode *> sk;
    sk.push(root);
    while (!sk.empty()) {
      auto tnode = sk.top();
      sk.pop();
      result.push_back(tnode->val);
      if (tnode->left != nullptr) sk.push(tnode->left);
      if (tnode->right != nullptr) sk.push(tnode->right);
    } 
    return std::vector<int>(result.rbegin(), result.rend());
  }
};