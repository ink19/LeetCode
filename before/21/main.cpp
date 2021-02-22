#include <iostream>
#include <string>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode null_node;
    ListNode *head = &null_node, *tail = &null_node;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        ListNode *temp_node = l1;
        l1 = l1->next;
        temp_node->next = nullptr;
        
        tail->next = temp_node;
        tail = temp_node;
      } else {
        ListNode *temp_node = l2;
        l2 = l2->next;
        temp_node->next = nullptr;
        
        tail->next = temp_node;
        tail = temp_node;
      }
    }

    if (l1 == nullptr) {
      tail->next = l2;
    } else {
      tail->next = l1;
    }
    return head->next;
  }
};