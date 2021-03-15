#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int>> result;

  void pathSumM(TreeNode *root, int sum, vector<int> path) {
    path.push_back(root->val);
    if (root->left == NULL && root->right == NULL) {
      if (std::accumulate(path.begin(), path.end(), 0) == sum) {
        result.push_back(path);
      }
      return;
    }
    if (root->left != NULL) {
      pathSumM(root->left, sum, path);
    }
    if (root->right != NULL) {
      pathSumM(root->right, sum, path);
    }
  }

  vector<vector<int>> pathSum(TreeNode *root, int sum) {
    if (root == NULL) return result;
    pathSumM(root, sum, vector<int>());
    return result;
  }
};