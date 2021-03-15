#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

class Solution {
public:
    int deleteCost(vector<int>& cost, int begin, int end) {
      int sum = std::accumulate(cost.begin() + begin, cost.begin() + end, 0);
      int big = std::accumulate(cost.begin() + begin, cost.begin() + end, 0, [](int a, int b) {
        return std::max(a, b);
      });
      return sum - big;
    }
    int minCost(string s, vector<int>& cost) {
      const int s_len = s.size();
      int result = 0;
      for (int loop_i = 1; loop_i < s_len; ++loop_i) {
        if (s[loop_i] == s[loop_i - 1]) {
          int begin = loop_i - 1;
          int same_len = 0;
          while (loop_i + same_len < s_len && s[loop_i + same_len] == s[loop_i]) {
            same_len++;
          }
          result += deleteCost(cost, begin, loop_i + same_len);
          loop_i += same_len - 1;
        }
      }
      return result;
    }
};