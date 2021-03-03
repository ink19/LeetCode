#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *getKthFromEnd(ListNode *head, int k) {
    if (head == NULL) return NULL;
    auto quickly_node = head;
    auto slowly_node = head;
    k--;
    while (k--) {
      quickly_node = quickly_node->next;
    }
    while (quickly_node->next != NULL) {
      quickly_node = quickly_node->next;
      slowly_node = slowly_node->next;
    }
    return slowly_node;
  }
};