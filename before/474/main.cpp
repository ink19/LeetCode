#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    vector<pair<int, int>> nums;
    int nums_len = strs.size();
    for (int loop_i = 0; loop_i < nums_len; loop_i++) {
      int one_num = 0;
      int zero_num = 0;
      for (int loop_j = 0; loop_j < strs[loop_i].size(); ++loop_j) {
        if (strs[loop_i][loop_j] == '0')
          zero_num++;
        else
          one_num++;
      }
      nums.push_back(std::make_pair(zero_num, one_num));
    }

    vector<vector<vector<int>>> dp(
        m + 1, vector<vector<int>>(n + 1, vector<int>(nums_len + 1, 0)));

    for (int loop_m = 0; loop_m < m + 1; ++loop_m) {
      for (int loop_n = 0; loop_n < n + 1; ++loop_n) {
        for (int loop_k = 1; loop_k < nums_len + 1; ++loop_k) {
          if (loop_n < nums[loop_k - 1].second || loop_m < nums[loop_k - 1].first) {
            dp[loop_m][loop_n][loop_k] = dp[loop_m][loop_n][loop_k - 1];
          } else {
            dp[loop_m][loop_n][loop_k] = std::max({
              dp[loop_m - nums[loop_k - 1].first][loop_n - nums[loop_k - 1].second][loop_k - 1] + 1, 
              dp[loop_m][loop_n][loop_k - 1]
            });
          }
        }
      }
    }
    int max = 0;
    for (int loop_i = 0; loop_i < m + 1; ++loop_i) {
      for (int loop_j = 0; loop_j < n + 1; ++loop_j) {
        // std::cout << "<";
        int max = 0;
        for (int loop_k = 0; loop_k < nums_len + 1; ++loop_k) {
          // std::cout << dp[loop_i][loop_j][loop_k] << ", ";
          if (dp[loop_i][loop_j][loop_k] > max) max = dp[loop_i][loop_j][loop_k];
        }
        //std::cout << ">, ";
        std::cout << max << ", ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
    for (int loop_k = 0; loop_k < nums_len + 1; ++loop_k) {
      if (dp[m][n][loop_k] > max)
        max = dp[m][n][loop_k];
    }
    return max;
  }
};

int main() {
  vector<string> data = {"0","11","1000","01","0","101","1","1","1","0","0","0","0","1","0","0110101","0","11","01","00","01111","0011","1","1000","0","11101","1","0","10","0111"};
  Solution s;
  std::cout << s.findMaxForm(data, 9, 80) << std::endl;
  return 0;
}