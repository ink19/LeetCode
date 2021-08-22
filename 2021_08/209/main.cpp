#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = std::numeric_limits<int>::max();
        int begin = 0;
        int sum = 0;
        const int nums_len = nums.size();
        for (int loop_i = 0; loop_i < nums_len; ++loop_i) {
            sum += nums[loop_i];
            while (sum - nums[begin] >= target) {
                sum -= nums[begin];
                begin++;
            }
            if (sum >= target && loop_i - begin + 1 < result) {
                result = loop_i - begin + 1;
            }
        }
        if (result == std::numeric_limits<int>::max()) return 0;
        return result;
    }
};