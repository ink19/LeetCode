#include <vector>
#include <iostream>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector <int> mode;
    int max_number = 1;
    int now_number = 0;
    int now_max = 0;
    vector<int> findMode2(TreeNode* root) {
        if (root == NULL) return {};
        findMode2(root->left);
        if (now_number == root->val) {
            now_max++;
        } else {
            if (max_number == now_max) {
                mode.push_back(now_number);
            } else if(max_number < now_max){
                mode.clear();
                mode.push_back(now_number);
                max_number = now_max;
            }
            now_number = root->val;
            now_max = 1;
        }
        findMode2(root->right);
        return mode;
    }
    vector<int> findMode(TreeNode* root) {
        findMode2(root);
        if (max_number == now_max) {
                mode.push_back(now_number);
            } else if(max_number < now_max) {
                mode.clear();
                mode.push_back(now_number);
                max_number = now_max;
            }
        return mode;
    }
};