#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode head_node(0);
    head_node.next = head;
    ListNode rehead_node(0);
    while (head_node.next != NULL) {
      ListNode *temp = head_node.next;
      head_node.next = temp->next;
      temp->next = rehead_node.next;
      rehead_node.next = temp; 
    }
    return rehead_node.next;
  }
};