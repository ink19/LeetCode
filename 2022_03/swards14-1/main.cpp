#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
  int cuttingRope(int n) {
    if(n == 2) return 1;
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    for (int loop_i = 3; loop_i < n + 1; ++loop_i) {
      int max = 0;
      for (int loop_k = 1; loop_k < loop_i; ++loop_k) {
        max = std::max({max, dp[loop_i - loop_k] * dp[loop_k], dp[loop_i - loop_k] * loop_k, (loop_i - loop_k) * dp[loop_k], loop_k * (loop_i - loop_k)});
      }
      dp[loop_i] = max;
    }
    return dp[n];
  }
};


int main() {
  Solution s;
  std::cout << s.cuttingRope(58) << std::endl;
}