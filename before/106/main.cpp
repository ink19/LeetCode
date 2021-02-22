#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) return NULL;
        TreeNode *now_node = new TreeNode(postorder.back());
        
        auto iter = std::find(inorder.begin(), inorder.end(), now_node->val);
        postorder.pop_back();
        vector<int> left_inorder(inorder.begin(), iter);
        vector<int> right_inorder(iter + 1, inorder.end());
        
        now_node->right = buildTree(right_inorder, postorder);
        now_node->left = buildTree(left_inorder, postorder);
        return now_node;
    }
};

int main() {
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    Solution s;
    s.buildTree(inorder, postorder);
}