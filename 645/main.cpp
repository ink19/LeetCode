#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> findErrorNums(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    const int nums_len = nums.size();
    vector<int> result(2, -1);
    for (int loop_i = 0; loop_i < nums_len - 1; ++loop_i) {
      if (nums[loop_i] == nums[loop_i + 1]) {
        result[0] = nums[loop_i];
        nums.erase(nums.begin() + loop_i);
        break;
      }
    }
    for (int loop_i = 0; loop_i < nums_len - 1; ++loop_i) {
      if (nums[loop_i] != loop_i + 1) {
        result[1] = loop_i + 1;
        break;
      }
    }
    if (result[1] == -1) result[1] = nums_len;
    return result;
  }
};