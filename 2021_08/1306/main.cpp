#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool bfs(vector<int> &arr, std::set<int>& viewed_index, int start) {
        if (arr[start] == 0) return true;
        bool result = false;
        int nnext = start - arr[start];
        int pnext = start + arr[start];
        if (nnext >= 0 && viewed_index.find(nnext) == viewed_index.end()) {
            viewed_index.insert(nnext);
            result = bfs(arr, viewed_index, nnext);
        }
        if (result) return true;
        if (pnext < arr.size() && viewed_index.find(pnext) == viewed_index.end()) {
            viewed_index.insert(pnext);
            result = bfs(arr, viewed_index, pnext);
        }
        return result;
    }
    bool canReach(vector<int>& arr, int start) {
        std::set<int> viewed_index;
        return bfs(arr, viewed_index, start);
    }
};