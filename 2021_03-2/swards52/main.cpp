#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *temp_A = headA;
    ListNode *temp_B = headB;
    while (temp_A != temp_B) {
      temp_A = temp_A != NULL? temp_A->next: headB;
      temp_B = temp_B != NULL? temp_B->next: headA;
    }
    return temp_A;
  }
};