#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        std::queue<TreeNode*> *qu1 = new std::queue<TreeNode*>();
        std::queue<TreeNode*> *qu2 = new std::queue<TreeNode*>();
        qu1->push(root);
        vector<int> temp_result;
        while (!(qu1->empty() && qu2->empty())) {
            if (qu1->empty()) {
                auto temp_qu = qu1;
                qu1 = qu2;
                qu2 = temp_qu;
                result.push_back(temp_result);
                temp_result = vector<int>();
            }
            TreeNode* temp_node = qu1->front();
            qu1->pop();
            temp_result.push_back(temp_node->val);
            if (temp_node->left != nullptr) qu2->push(temp_node->left);
            if (temp_node->right != nullptr) qu2->push(temp_node->right);
        }
        if (temp_result.size() != 0) result.push_back(temp_result);
        return result;
    }
};