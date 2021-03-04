#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    const int envelopes_len = envelopes.size();
    if (envelopes_len == 0) return 0;
    std::vector<int> dp(envelopes_len + 1, 0);
    std::sort(envelopes.begin(), envelopes.end(),
              [](const vector<int> &a, const vector<int> &b) -> bool {
                if (a[0] == b[0]) {
                  return a[1] < b[1];
                } else {
                  return a[0] < b[0];
                }
              });
    int max_result = 0;
    for (int loop_i = 0; loop_i < envelopes_len; ++loop_i) {
      int max_env = 0;
      for (int loop_j = 1; loop_j < loop_i + 1; ++loop_j) {
        if (envelopes[loop_j - 1][1] < envelopes[loop_i][1] && envelopes[loop_j - 1][0] < envelopes[loop_i][0] && dp[loop_j] > max_env) {
          max_env = dp[loop_j];
        }
      }
      dp[loop_i + 1] = max_env + 1;
      if (dp[loop_i + 1] > max_result) max_result = dp[loop_i + 1];
    } 

    return max_result;
  }
};

int main() {
  Solution s;
  vector<vector<int>> data = {{5, 4}};
  std::cout << s.maxEnvelopes(data) << std::endl;
}