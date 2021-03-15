#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <deque>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> result;
    if (root == NULL) return result;
    std::stack<std::pair<TreeNode*, int>> tree_node_queue;
    std::stack<std::pair<TreeNode*, int>> tree_node_stack;
    int right = 0;
    tree_node_queue.push({root, 0});
    while (!(tree_node_queue.empty() && tree_node_stack.empty())) {
      std::pair<TreeNode*, int> temp;
      if (right == 0) {
        if (tree_node_queue.empty()) {
          right = 1;
          continue;
        }
        temp = tree_node_queue.top();
        tree_node_queue.pop();
      } else {
        if (tree_node_stack.empty()) {
          right = 0;
          continue;
        }
        temp = tree_node_stack.top();
        tree_node_stack.pop();
      }

      if (temp.second >= result.size()) {
        result.push_back(vector<int>());
      }
      result[temp.second].push_back(temp.first->val);
      if (right == 0) {
        if (temp.first->left != NULL) {
          tree_node_stack.push({temp.first->left, temp.second + 1});
        }
        if (temp.first->right != NULL) {
          tree_node_stack.push({temp.first->right, temp.second + 1});
        }
      } else {
        if (temp.first->right != NULL) {
          tree_node_queue.push({temp.first->right, temp.second + 1});
        }
        if (temp.first->left != NULL) {
          tree_node_queue.push({temp.first->left, temp.second + 1});
        }
      }
    }
    return result;
  }
};