#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode l1_head(0);
    ListNode l2_head(0);
    l1_head.next = l1;
    l2_head.next = l2;
    ListNode merge_head(0);
    ListNode *merge_tail = &merge_head;
    while (l1_head.next != NULL && l2_head.next != NULL) {
      ListNode *temp;
      if (l1_head.next->val > l2_head.next->val) {
        temp = l2_head.next;
        l2_head.next = temp->next;
      } else {
        temp = l1_head.next;
        l1_head.next = temp->next;        
      }

      temp->next = merge_tail->next;
      merge_tail->next = temp;
      merge_tail = temp;
    }
    if (l1_head.next == NULL) {
      merge_tail->next = l2_head.next;
    } else {
      merge_tail->next = l1_head.next;
    }
    return merge_head.next;
  }
};