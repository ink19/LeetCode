#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int index = 1;
    const size_t nums_len = nums.size();
    for (int loop_i = 1; loop_i < nums_len; ++loop_i) {
      if (nums[loop_i] != nums[loop_i - 1]) {
        nums[index] = nums[loop_i];
        index++;
      } 
    } 
    if (nums_len == 0) index = 0;
    return index;
  }
};