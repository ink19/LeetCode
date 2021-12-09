#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
public:
  vector<int> preorder(Node *root) {
    std::vector<int> result;
    if (root == nullptr) return result;
    std::stack<Node *> sk;
    sk.push(root);
    while (!sk.empty()) {
      auto tnode = sk.top();
      sk.pop();
      result.push_back(tnode->val);
      for (auto bi = tnode->children.rbegin(); bi != tnode->children.rend(); ++bi) {
        sk.push(*bi);
      }
    }
    return result;
  }
};