#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


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
    std::vector<int> data;
    TreeNode* toBST(int begin, int end) {
        if (begin > end) return nullptr;
        int mid = (begin + end) >> 1;
        TreeNode * root = new TreeNode(data[mid]);
        root->left = toBST(begin, mid - 1);
        root->right = toBST(mid + 1, end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        while (head != nullptr) {
            data.push_back(head->val);
            head = head->next;
        }
        if (data.size() == 0) return nullptr;
        return toBST(0, data.size() - 1);
    }
};