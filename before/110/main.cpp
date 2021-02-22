#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced2(TreeNode *root, int &height) {
        int left = 0, right = 0;
        if (root->left == NULL) {
            left = 0;
        } else {
            if (!isBalanced2(root->left, left)) {
                return false;
            } 
        }

        if (root->right == NULL) {
            right = 0;
        } else {
            if (!isBalanced2(root->right, right)) {
                return false;
            } 
        }
        height = std::max(left, right) + 1;
        if (std::abs(right - left) <= 1) return true;
        else return false;
    }
    
    bool isBalanced(TreeNode *root) {
        if (root == NULL) return true;
        int t;
        return isBalanced2(root, t);
    }
};