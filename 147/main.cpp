#include <iostream>
#include <string>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *insertionSortList(ListNode *head) {
    ListNode shead(0);
    ListNode *temp = head;
    while (temp != NULL) {
      ListNode *temp_node = temp;
      temp = temp->next;
      ListNode *iter = &shead;
      while (iter->next != NULL) {
        if (iter->next->val > temp_node->val) {
          break;
        }
        iter = iter->next;
      }
      temp_node->next = iter->next;
      iter->next = temp_node;
    }
    return shead.next;
  }
};