#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::map <TreeNode *, TreeNode *> parent;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (root == NULL) return vector<int>();
        queue<std::tuple<TreeNode *, TreeNode *, int>> loop_stack;
        loop_stack.push({root, NULL, 0});
        parent[root] = NULL;
        while (!loop_stack.empty()) {
            auto temp_node = std::get<0>(loop_stack.front());
            loop_stack.pop();
            if (temp_node->left != NULL) {
                parent[temp_node->left] = temp_node;
                loop_stack.push({temp_node->left, NULL, 0});
            }
            if (temp_node->right != NULL) {
                parent[temp_node->right] = temp_node;
                loop_stack.push({temp_node->right, NULL, 0});
            }
        }
        
        loop_stack.push({target, NULL, 0});
        vector<int> result;
        while (!loop_stack.empty()) {
            auto temp_pair = loop_stack.front();
            loop_stack.pop();
            if (std::get<2>(temp_pair) > k) continue;
            auto temp_node = std::get<0>(temp_pair);
            if (std::get<2>(temp_pair) == k) {
                result.push_back(temp_node->val);
                continue;
            }
            auto last_node = std::get<1>(temp_pair);
            if (temp_node->left != NULL && temp_node->left != last_node) {
                loop_stack.push({temp_node->left, temp_node, std::get<2>(temp_pair) + 1});
            }
            if (temp_node->right != NULL && temp_node->right != last_node) {
                loop_stack.push({temp_node->right, temp_node, std::get<2>(temp_pair) + 1});
            }
            if (parent[temp_node] != NULL && parent[temp_node] != last_node) {
                loop_stack.push({parent[temp_node], temp_node, std::get<2>(temp_pair) + 1});
            }
        }
        return result;
    }
};