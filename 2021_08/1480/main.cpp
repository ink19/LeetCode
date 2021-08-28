#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        const int nums_len = nums.size();
        std::vector<int> sum_nums(nums_len, 0);
        sum_nums[0] = nums[0];
        for (int loop_i = 1; loop_i < nums_len; ++loop_i) {
            sum_nums[loop_i] = nums[loop_i] + sum_nums[loop_i - 1];
        }
        return sum_nums;
    }
};