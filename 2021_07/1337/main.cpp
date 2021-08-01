#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        const int mat_len = mat.size();
        std::priority_queue<std::pair<int, int>> data;
        for (int loop_i = 0; loop_i < mat_len; ++loop_i) {
            data.push({std::accumulate(mat[loop_i].begin(), mat[loop_i].end(), 0), loop_i});
            if (data.size() > k) {
                data.pop();
            }
        }
        vector<int> result = vector<int>(data.size(), 0);
        for (int loop_i = 0; loop_i < result.size(); ++loop_i) {
            result[data.size() - 1] = data.top().second;
            data.pop();
        }
        return result;
    }
};