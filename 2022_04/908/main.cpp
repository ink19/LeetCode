#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
  int smallestRangeI(vector<int> &nums, int k) {
    int max_num = *std::max_element(nums.begin(), nums.end());
    int min_num = *std::min_element(nums.begin(), nums.end());
    if (max_num - min_num > k * 2) {
      return max_num - min_num - k * 2;
    } else {
      return 0;
    }
  }
};
