#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    const int s_len = s.size();
    if (s_len == 0) return 0;
    vector<int> dp(s_len, 0);
    dp[0] = 1;
    int max_it = 1;
    for (int loop_i = 1; loop_i < s_len; ++loop_i) {
      auto find_it = std::find(s.begin() + loop_i - dp[loop_i - 1], s.begin() + loop_i, s[loop_i]);
      if (find_it == s.begin() + loop_i) {
        dp[loop_i] = dp[loop_i - 1] + 1;
      } else {
        dp[loop_i] = s.begin() + loop_i - find_it;
      }
      // std::cout << dp[loop_i] << std::endl;
      max_it = std::max(max_it, dp[loop_i]);
    }
    return max_it;
  }
};

int main() {
  std::string data = "abcabcbb";
  Solution s;
  std::cout << s.lengthOfLongestSubstring(data) << std::endl;
  return 0;
}
