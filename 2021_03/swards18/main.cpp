#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *deleteNode(ListNode *head, int val) {
    ListNode temp_head(0);
    temp_head.next = head;
    ListNode *temp_node = &temp_head;
    while (temp_node->next != NULL) {
      if (temp_node->next->val == val) {
        temp_node->next = temp_node->next->next;
        break;
      }
      temp_node = temp_node->next;
    }
    return temp_head.next;
  }
};