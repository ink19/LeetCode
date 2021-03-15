#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
  int translateNum(int num) {
    if (num == 0) return 1;
    std::vector<int> snum;
    while (num > 0) {
      snum.push_back(num%10);
      num /= 10;
    }
    
    if (snum.size() == 1) return 1;
    std::reverse(snum.begin(), snum.end());
    std::vector<int> dp(snum.size() + 1, 1);
    dp[1] = 1;
    for (int loop_i = 2; loop_i < snum.size() + 1; ++loop_i) {
      if (snum[loop_i - 2] != 0 && snum[loop_i - 2] * 10 + snum[loop_i - 1] <= 25) {
        dp[loop_i] = dp[loop_i - 2] + dp[loop_i - 1];
      } else {
        dp[loop_i] = dp[loop_i - 1];
      }
    }

    return dp[snum.size()];
  }
};

int main() {
  Solution s;
  std::cout << s.translateNum(12258) << std::endl;
}