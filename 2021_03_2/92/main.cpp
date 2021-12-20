#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (left == right) return head;
    ListNode thead(0, head);
    ListNode* left_node = &thead;
    right -= left;
    left--;
    while (left--) left_node = left_node->next;
    ListNode *temp_node1 = left_node->next;
    ListNode *temp_node2 = temp_node1->next;
    ListNode *temp_node3 = temp_node2->next;
    while (right--) {
      temp_node2->next = temp_node1;

      temp_node1 = temp_node2;
      temp_node2 = temp_node3;
      if(temp_node3!=nullptr) temp_node3 = temp_node3->next;
    }
    left_node->next->next = temp_node2;
    left_node->next = temp_node1;
    return thead.next;
  }
};