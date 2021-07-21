#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int result = 0;
        const int nums_len = nums.size();
        sort(nums.begin(), nums.end());

        for (int loop_i = 0; loop_i < nums_len/2; ++loop_i) {
            if (nums[loop_i] + nums[nums_len - loop_i - 1] > result) {
                result = nums[loop_i] + nums[nums_len - loop_i - 1];
            }
        }

        return result;
    }
};