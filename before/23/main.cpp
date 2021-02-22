#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        std::priority_queue<std::pair<int, int>, vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > data;
        const int lists_len = lists.size();
        if (lists_len == 0) return NULL;
        for (int loop_i = 0;loop_i < lists_len; ++loop_i) {
            if (lists[loop_i] == NULL) {
                data.push(std::make_pair(10e5, loop_i));
            } else {
                data.push(std::make_pair(lists[loop_i]->val, loop_i));
                lists[loop_i] = lists[loop_i]->next;
            }
        }
        ListNode *result = NULL;
        ListNode *final = NULL;
        while (data.top().first != 10e5) {
            auto tdata = data.top();
            data.pop();
            auto ldata = new ListNode(tdata.first, NULL);
            if (final == NULL) {
                final = ldata;
                result = ldata;
            } else {
                final->next = ldata;
                final = ldata;
            }
            if (lists[tdata.second] == NULL) {
                data.push(std::make_pair(10e5, tdata.second));
            } else {
                data.push(std::make_pair(lists[tdata.second]->val, tdata.second));
                lists[tdata.second] = lists[tdata.second]->next;
            }
        }
        return result;
    }
};