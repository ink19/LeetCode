#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        std::vector<ListNode *> list;
        ListNode *temp_head = head;
        while (temp_head != nullptr) {
            list.push_back(temp_head);
            temp_head = temp_head->next;
            list.back()->next = nullptr;
        }
        int begin, end = 0;
        if (list.size()%2) {
            begin = end = list.size()/ 2;
            temp_head = list[begin];
        } else {
            begin = list.size()/2 - 1;
            end = begin + 1;
            temp_head = list[begin];
            temp_head->next = list[end];
        }
        begin--; end ++;
        while (begin >= 0) {
            list[end]->next = temp_head;
            temp_head = list[end];

            list[begin]->next = temp_head;
            temp_head = list[begin];

            begin--; end++;
        }
    }
};