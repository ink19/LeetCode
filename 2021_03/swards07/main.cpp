#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (inorder.size() == 0) return NULL;
    int mid = preorder.at(0);
    auto mid_in = std::find(inorder.begin(), inorder.end(), mid);
    
    vector<int> left_preorder = vector<int>(preorder.begin() + 1, preorder.begin() + 1 + (mid_in - inorder.begin()));

    

    vector<int> right_preorder = vector<int>(preorder.begin() + 1 + (mid_in - inorder.begin()), preorder.end());

    auto left_inorder = vector<int>(inorder.begin(), mid_in);
    auto right_inorder = vector<int>(mid_in + 1, inorder.end());
    auto head = new TreeNode(mid);
    head->left = buildTree(left_preorder, left_inorder);
    head->right = buildTree(right_preorder, right_inorder);
    return head;
  }
};

int main() {
  vector<int> data1 = {1, 2};
  vector<int> data2 = {1, 2};

  Solution s;
  std::cout << s.buildTree(data1, data2) << std::endl;
}