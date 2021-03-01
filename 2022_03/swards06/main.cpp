#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  vector<int> reversePrint(ListNode *head) {
    vector<int> result;
    while (head != NULL) {
      result.push_back(head->val);
      head = head->next;
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
};