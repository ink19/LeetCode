#include <vector>

class Node {
public:
  int val;
  Node *left;
  Node *right;

  Node() {}

  Node(int _val) {
    val = _val;
    left = NULL;
    right = NULL;
  }

  Node(int _val, Node *_left, Node *_right) {
    val = _val;
    left = _left;
    right = _right;
  }
};

class Solution {
public:
  std::vector<Node*> beresult;

  void treemid(Node *root) {
    if (root == NULL) return;
    treemid(root->left);
    beresult.push_back(root);
    treemid(root->right);
  }

  Node *treeToDoublyList(Node *root) {
    if (root == NULL) return NULL;
    treemid(root);
    const int node_len = beresult.size();
    for (int loop_i = 0; loop_i < node_len; ++loop_i) {
      beresult[loop_i]->right = beresult[(loop_i + 1)%node_len];
      beresult[loop_i]->left = beresult[(loop_i - 1 + node_len)%node_len];
    }
    return beresult[0];
  }
};