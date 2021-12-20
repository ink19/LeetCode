#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    const int nums_len = nums.size();
    int nmax = nums[0];
    for (int loop_i = 1; loop_i < nums_len; ++loop_i) {
      nums[loop_i] = std::max(nums[loop_i], nums[loop_i] + nums[loop_i - 1]);
      if (nums[loop_i] > nmax) {
        nmax = nums[loop_i];
      }
    }
    return nmax;
  }
};