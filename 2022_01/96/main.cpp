#include <iostream>
#include <vector>

class Solution {
public:
  int numTrees(int n) {
    std::vector<int> result_v;
    result_v.push_back(1);
    for (int loop_i = 1; loop_i <= n; ++loop_i) {
      int temp_result = 0;
      for (int loop_j = 1; loop_j <= loop_i; ++loop_j) {
        temp_result += result_v[loop_j - 1] * result_v[loop_i - loop_j];
      }
      result_v.push_back(temp_result);
    }
    return result_v[n];
  }
};