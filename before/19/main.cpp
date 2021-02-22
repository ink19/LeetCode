struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode temp_head;
        temp_head.next = head;
        ListNode *quickly = &temp_head;
        ListNode *slowly = &temp_head;
        
        while (n--) {
            quickly = quickly->next;
        }

        while (quickly->next != nullptr) {
            quickly = quickly->next;
            slowly = slowly->next;
        }
        slowly->next = slowly->next->next;
        return temp_head.next;
    }
};