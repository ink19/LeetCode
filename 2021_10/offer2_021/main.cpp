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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode mhead(0, head);
    ListNode *temp_node1 = &mhead, *temp_node2 = &mhead;

    for (int loop_i = 0; loop_i < n; ++loop_i) {
      temp_node1 = temp_node1->next;
    }

    while (temp_node1->next != nullptr) {
      temp_node1 = temp_node1->next;
      temp_node2 = temp_node2->next;
    }
    temp_node2->next = temp_node2->next->next;
    return mhead.next;
  }
};