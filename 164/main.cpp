#include <vector>

using std::vector;

class Solution {
public:
  int maximumGap(vector<int> &nums) {
    if (nums.size() <= 1) return 0;
    std::sort(nums.begin(), nums.end());
    int max = 0;
    for (int loop_i = 1; loop_i < static_cast<int>(nums.size()); ++loop_i) {
      if (nums[loop_i] - nums[loop_i - 1] > max) {
        max = nums[loop_i] - nums[loop_i - 1];
      }
    }
    return max;
  }
};