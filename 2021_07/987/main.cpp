#include <vector>
#include <iostream>
#include <map>
#include <set>

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
    std::map<int, std::map<int, std::multiset<int>>> out_data;

    void dsp(TreeNode *node, std::pair<int, int> position){
        if (node == NULL) return;
        if (out_data.count(position.second) == 0) {
            out_data[position.second] = std::map<int, std::multiset<int>>();
            out_data[position.second][position.first] = std::multiset<int>({node->val});
        } else {
            if (out_data[position.second].count(position.first) == 0) {
                out_data[position.second][position.first] = std::multiset<int>({node->val});
            } else {
                out_data[position.second][position.first].insert(node->val);
            }
        }
        dsp(node->left, {position.first + 1, position.second - 1});
        dsp(node->right, {position.first + 1, position.second + 1});
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        dsp(root, {0, 0});
        for (auto idata : out_data) {
            vector<int> result_i;
            for (auto iidata : idata.second) {
                for (auto iiidata : iidata.second) {
                    result_i.push_back(iiidata);
                }
            }
            result.push_back(result_i);
        }
        return result;
    }
};