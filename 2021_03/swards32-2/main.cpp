#include <iostream>
#include <vector>
#include <queue>
#include <utility>

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
    std::queue<std::pair<TreeNode*, int>> tree_node_queue;
    tree_node_queue.push({root, 0});
    while (!tree_node_queue.empty()) {
      auto temp = tree_node_queue.front();
      tree_node_queue.pop();
      if (temp.second >= result.size()) {
        result.push_back(vector<int>());
      }
      result[temp.second].push_back(temp.first->val);
      if (temp.first->left != NULL) {
        tree_node_queue.push({temp.first->left, temp.second + 1});
      }
      if (temp.first->right != NULL) {
        tree_node_queue.push({temp.first->right, temp.second + 1});
      }
    }
    return result;
  }
};