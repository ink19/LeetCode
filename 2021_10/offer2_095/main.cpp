#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    const int text1_len = text1.size();
    const int text2_len = text2.size();
    vector<vector<int>> dp(text1_len + 1, vector<int>(text2_len + 1, 0));

    int max_len = 0;
    for (int loop_i = 1; loop_i <= text1_len; ++loop_i) {
      for (int loop_j = 1; loop_j <= text2_len; ++loop_j) {
        if (text1[loop_i - 1] == text2[loop_j - 1]) {
          dp[loop_i][loop_j] = dp[loop_i - 1][loop_j - 1] + 1;
          if (dp[loop_i][loop_j] > max_len) {
            max_len = dp[loop_i][loop_j];
          }
        } else {
          dp[loop_i][loop_j] = std::max({dp[loop_i][loop_j - 1], dp[loop_i - 1][loop_j]});
        }
      }
    }
    return max_len; 
  }
};

int main() {
  std::cout << Solution().longestCommonSubsequence("abcde", "ace") << std::endl;
}