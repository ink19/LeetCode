#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <utility>
#include <numeric>
using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int nums_len = nums.size();
    vector<int> max_len(nums_len, 0);
    for (int loop_i = 0; loop_i < nums_len; ++loop_i) {
      int temp_max_len = 1;
      for (int loop_j = 0; loop_j < loop_i; ++loop_j) {
        if (nums[loop_j] < nums[loop_i] && temp_max_len < max_len[loop_j] + 1) {
          temp_max_len = max_len[loop_j] + 1;
        }
      }
      max_len[loop_i] = temp_max_len;
    }
    return std::accumulate(max_len.begin(), max_len.end(), 0, [](int before, int now) {
      return std::max(before, now);
    });
  }
};

int main() {
  Solution s;
  vector<int> data = {3,5,6,2,5,4,19,5,6,7,12};
  std::cout << s.lengthOfLIS(data) << std::endl;
  return 0;
}