#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
  vector<vector<int>> findContinuousSequence(int target) {
    std::vector<std::vector<int>> result;
    for (long long loop_i = 1; loop_i < target/2 + 1; ++loop_i) {
      if (std::sqrt((2 * loop_i - 1) * (2 * loop_i - 1) + 8 * target) == (long long)(std::sqrt((2 * loop_i - 1) * (2 * loop_i - 1) + 8 * target))) {
        std::vector<int> out_data((long long)((std::sqrt((2 * loop_i - 1) * (2 * loop_i - 1) + 8 * target) - 1)/ 2 - loop_i + 1), 0);
        for (int loop_j = 0; loop_j < out_data.size(); ++loop_j) {
          out_data[loop_j] = (loop_j + loop_i);
        }
        result.push_back(out_data);
      }
    }
    return result;
  }
};