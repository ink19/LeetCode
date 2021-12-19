#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
  int smallestRangeI(vector<int> &nums, int k) {
    const int nums_len = nums.size();
    if (nums_len <= 1) return 0;
    int max_num = *std::max_element(nums.begin(), nums.end());
    int min_num = *std::min_element(nums.begin(), nums.end());
    int find_result = (max_num - min_num) - 2 * k;
    return find_result > 0? find_result : 0;
  }
};