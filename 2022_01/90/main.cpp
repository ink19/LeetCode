#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    const int nums_len = nums.size();
    std::set<std::vector<int>> result_set;
    for (int loop_i = 0; loop_i < (1 << nums_len); ++loop_i) {
      std::vector<int> item;
      for (int loop_j = 0; loop_j < nums_len; ++loop_j) {
        if (loop_i & (1 << loop_j)) {
          item.push_back(nums[loop_j]);
        }
      }
      std::sort(item.begin(), item.end());
      result_set.insert(item);
    }
    return std::vector<std::vector<int>>(result_set.begin(), result_set.end());
  }
};