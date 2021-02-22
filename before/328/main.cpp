#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// class Solution {
// public:

//   void link_swap(ListNode *&a, ListNode *&b) {
//     ListNode *temp_a = a->next;
//     ListNode *temp_b = b->next;
//     if (temp_b->next == temp_a) {
//       connect_link_swap(b, a);
//     } else if (temp_a->next == temp_b) {
//       connect_link_swap(a, b);
//     } else {
//       auto temp_a = a->next;
//       auto temp_a_next = temp_a->next;

//       temp_a->next = temp_b->next;
//       temp_b->next = temp_a_next;
//       a->next = b->next;
//       b->next = temp_a;
//     }
//     ListNode *temp_a1 = a;
//     a = b;
//     b = temp_a1;
//   }

//   void connect_link_swap(ListNode *&a, ListNode *&b) {
//     ListNode *A = a->next;
//     ListNode *B = b->next;

//     A->next = B->next;
//     B->next = A;
//     a->next = B;
//   }

//   ListNode *oddEvenList(ListNode *head) {
//     ListNode temp_head;
//     temp_head.next = head;
//     ListNode *ou = &temp_head;
//     ListNode *ji = temp_head.next;
//     while (true) {
//       if (ou->next == nullptr || ji->next == nullptr) break;
//       if (ji->next->val % 2 == 0) {
//         link_swap(ou, ji);
//         ou = ou->next;
//         if (ou != nullptr) {
//           ou = ou->next;
//         } else {
//           break;
//         }
//       } else {
//         ji = ji->next;
//         if (ji != nullptr) {
//           ji = ji->next;
//         } else {
//           break;
//         }
//       }
//     }
//     return temp_head.next;
//   }
// };
class Solution {
public:
  ListNode *oddEvenList(ListNode *head) {
    ListNode *odd_tail = head;
    if (head == nullptr) return head;
    ListNode *even_tail = head->next;
    if (even_tail == nullptr) return head;
    
    int loop_index = 3;

    while (even_tail->next != nullptr) {
      if (loop_index%2 == 0) {
        even_tail = even_tail->next;
      } else {
        ListNode *temp = even_tail->next;
        even_tail->next = temp->next;
        temp->next = odd_tail->next;
        odd_tail->next = temp;
        odd_tail = odd_tail->next;
      }
      loop_index++;
    }
    return head;
  }
};
int main() {}