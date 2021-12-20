#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isHui(string::iterator begin, string::iterator end) {
    while (begin < end) {
      // std::cout << *begin << " " << *end << std::endl; 
      if (*begin != *end) return false;
      begin++;
      end--;
    }
    return true;
  }
  int minCut(string s) {
    const int s_len = s.size();
    std::vector<int> dp(s_len + 1, 0);
    for (int loop_i = 0; loop_i < s_len; ++loop_i) {
      int min_data = 1000000;
      for (int loop_j = 0; loop_j <= loop_i; ++loop_j) {
        if (isHui(s.begin() + loop_j, s.begin() + loop_i)) {
          if (min_data > dp[loop_j] + 1) {
            min_data = dp[loop_j] + 1;
          }
        }
      }
      dp[loop_i + 1] = min_data;
    }
    return dp[s_len] - 1;
  }
};

int main() {
  Solution s;
  std::string data = "tseTest";
  std::cout << s.minCut(data) << std::endl;
  return 0;
}