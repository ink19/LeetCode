#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> relist;
    int depthsearch(int n, int goal,int k) {
        if (k == 0 && n == goal) return 1;
        if (k == 0) return 0;
        k -= 1;
        const int relist_len = relist[n].size();
        int result = 0;
        for (int loop_i = 0; loop_i < relist_len; ++loop_i) {
            result += depthsearch(relist[n][loop_i], goal, k);
        }
        return result;
    }
    int numWays(int n, vector<vector<int>>& relation, int k) {
        relist = vector<vector<int>>(n, vector<int>());
        for (auto relationi : relation) {
            relist[relationi[0]].push_back(relationi[1]);
        }
        return depthsearch(0, n - 1, k);
    }
};