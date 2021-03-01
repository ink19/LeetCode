#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
  int findRepeatNumber(vector<int> &nums) {
    std::set<int> mset;
    const int nums_len = nums.size();
    for (int loop_i = 0; loop_i < nums_len; ++loop_i) {
      if (mset.find(nums[loop_i]) == mset.end()) {
        mset.insert(nums[loop_i]);
      } else {
        return nums[loop_i];
      }
    }
    return -1;
  }
};