#include <vector>
#include <algorithm>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  int get_vec(const std::vector<int> &data, int index) {
    if (data.size() <= index) return 0;
    return data[index];
  }
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    std::vector<int> l1_v;
    std::vector<int> l2_v;
    ListNode *temp_node = l1;
    while (temp_node != nullptr) {
      l1_v.push_back(temp_node->val);
      temp_node = temp_node->next;
    }
    temp_node = l2;
    while (temp_node != nullptr) {
      l2_v.push_back(temp_node->val);
      temp_node = temp_node->next;
    }
    std::reverse(l1_v.begin(), l1_v.end());
    std::reverse(l2_v.begin(), l2_v.end());
    std::vector<int> result;
    int flow = 0;
    for (int loop_i = 0; loop_i < std::max(l1_v.size(), l2_v.size()); ++loop_i) {
      result.push_back(flow + get_vec(l1_v, loop_i) + get_vec(l2_v, loop_i));
      flow = result.back() / 10;
      result.back() %= 10;
    }
    if (flow != 0) {
      result.push_back(flow);
    }
    // std::reverse(result.begin(), result.end());
    ListNode *result_link = nullptr;
    temp_node = nullptr;
    for (int loop_i = 0; loop_i < result.size(); ++loop_i) {
      temp_node = new ListNode(result[loop_i], result_link);
      result_link = temp_node;
    }
    return result_link;
  }
};
