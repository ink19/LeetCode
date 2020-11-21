#include <iostream>
#include <string>
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
  ListNode *sortList(ListNode *head) {
    std::vector<ListNode *>temp_vec;
    ListNode temp(0);
    while (head != nullptr) {
      temp_vec.push_back(head);
      head = head->next;
    }
    std::sort(temp_vec.begin(), temp_vec.end(), [](ListNode *a, ListNode *b) {
      return a->val > b->val;
    });
    for (int loop_i = 0; loop_i < static_cast<int>(temp_vec.size()); ++loop_i) {
      temp_vec[loop_i]->next = temp.next;
      temp.next = temp_vec[loop_i];
    }
    return temp.next;
  }
};