#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
  int minFlipsMonoIncr(string s) {
    int result = 0;
    std::reverse(s.begin(), s.end());
    int one_count = 0;
    int zero_count = 0;
    for (int loop_i = 0; loop_i < s.size(); ++loop_i) {
      if (s[loop_i] == '0') zero_count++;
      if (s[loop_i] == '1' && zero_count != 0) {
        one_count++;
      }
      if (zero_count == one_count) {
        result += zero_count;
        zero_count = 0;
        one_count = 0;
      }
    }
    result += one_count;
    return result;
  }
};
