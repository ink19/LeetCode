#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp_nodeA = headA;
        ListNode *temp_nodeB = headB;
        while (temp_nodeA != temp_nodeB) {
            if (temp_nodeA == NULL) temp_nodeA = headB;
            else temp_nodeA = temp_nodeA->next;
            if (temp_nodeB == NULL) temp_nodeB = headA;
            else temp_nodeB = temp_nodeB->next;
        }
        return temp_nodeA;
    }
};