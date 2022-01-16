#include <vector>
#include <iostream>
#include <random>


struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  std::mt19937 random_gen = std::mt19937(std::random_device()());
  std::vector<int> data;
  Solution(ListNode *head) {
    ListNode *temp_node = head;
    while (temp_node != nullptr) {
      data.push_back(temp_node->val);
      temp_node = temp_node->next;
    }
  }

  int getRandom() {
    return data[random_gen()%(data.size())];
  }
};