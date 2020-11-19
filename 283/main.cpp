#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int loop_index = 0;
    for (int loop_i = 0; loop_i < static_cast<int>(nums.size()); ++loop_i) {
      if (nums[loop_i] != 0) {
        std::swap(nums[loop_index], nums[loop_i]);
        loop_index++;
      }
    }
  }
};