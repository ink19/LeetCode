#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  int kthToLast(ListNode *head, int k) {
    ListNode *t1 = head;
    ListNode *t2 = head;
    for (int loop_i = 0; loop_i < k; ++loop_i) {
      t1 = t1->next;
    }

    while (t1 != nullptr) {
      t1 = t1->next;
      t2 = t2->next;
    }
    return t2->val;
  }
};