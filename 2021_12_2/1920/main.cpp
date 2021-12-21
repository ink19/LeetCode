#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> buildArray(vector<int> &nums) {
    const int nums_len = nums.size();
    std::vector<int> result(nums_len, 0);
    for (int loop_i = 0; loop_i < nums_len; ++loop_i) {
      result[loop_i] = nums[nums[loop_i]];
    }
    return result;
  }
};