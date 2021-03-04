#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  
  vector<int> levelOrder(TreeNode *root) {
    if (root == NULL) return vector<int>();
    std::queue<TreeNode*> tree_node_queue;
    std::vector<int> result;
    tree_node_queue.push(root);
    while (!tree_node_queue.empty()) {
      auto temp_node = tree_node_queue.front();
      tree_node_queue.pop();
      result.push_back(temp_node->val);
      if (temp_node->left != NULL) {
        tree_node_queue.push(temp_node->left);
      }
      if (temp_node->right != NULL) {
        tree_node_queue.push(temp_node->right);
      }
      
    }
    return result;
  }
};