#include <vector>
#include <set>
using namespace std;

class Solution1 {
    set<vector<int>> result;
public:
    int dip_it(vector<int> temp_result, vector<int> &nums, int pos) {
        if (pos >= nums.size()) return 0;
        dip_it(temp_result, nums, pos + 1);
        if (temp_result.size() == 0 || temp_result.back() <= nums[pos]) {
            temp_result.push_back(nums[pos]);
            if (temp_result.size() >= 2) {
                result.insert(temp_result);
            }
            dip_it(temp_result, nums, pos + 1);
        }
        return 0;
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dip_it({}, nums, 0);
        vector<vector<int>> fresult(result.begin(), result.end());
        return fresult;
    }
};

class Solution {
public:
    set<vector<int>> result;
    int dfs(vector<int>& nums, vector<vector<int>> graph, int begin_index, vector<int> data) {
        data.push_back(nums[begin_index]);
        if (data.size() >= 2) result.insert(data);
        for (auto index : graph[begin_index]) {
            dfs(nums, graph, index, data);
        }
        return 0;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        const int nums_len = nums.size();
        vector<vector<int>> small_index(nums_len);
        
        for (int loop_i = 0; loop_i < nums_len; ++loop_i) {
            for (int loop_j = loop_i + 1; loop_j < nums_len; ++loop_j) {
                if (nums[loop_j] >= nums[loop_i]) {
                    small_index[loop_i].push_back(loop_j);
                }
            }
        }
        for (int loop_i = 0; loop_i < nums_len; ++loop_i) {
            dfs(nums, small_index, loop_i, {});
        }
        vector<vector<int>> fresult(result.begin(), result.end());
        return fresult;
    }
};