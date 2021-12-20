#include <vector>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
  int nthUglyNumber(int n) {
    std::vector<int> dp(n, 0);
    dp[0] = 1;
    int a = 0, b = 0, c = 0;
    for (int loop_i = 1; loop_i < n; ++loop_i) {
      int n2 = dp[a] * 2;
      int n3 = dp[b] * 3;
      int n5 = dp[c] * 5;
      dp[loop_i] = std::min({n2, n3, n5});
      if (dp[loop_i] == n2) a++;
      if (dp[loop_i] == n3) b++;
      if (dp[loop_i] == n5) c++;
    }
    return dp[n - 1];
  }
};

int main() {
  Solution s;
  std::cout << s.nthUglyNumber(1234) << std::endl;
}