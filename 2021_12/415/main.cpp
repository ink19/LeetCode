#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  string addStrings(string num1, string num2) {
    const int num1_len = num1.size();
    const int num2_len = num2.size();
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());
    for (int loop_i = 0; loop_i < num1_len; ++loop_i) {
      num1[loop_i] -= '0';
    }
    for (int loop_i = 0; loop_i < num2_len; ++loop_i) {
      num2[loop_i] -= '0';
    }
    
    std::string result;
    int flow_flag = 0;
    const int max_len = std::max(num1_len, num2_len);
    for (int loop_i = 0; loop_i < max_len; ++loop_i) {
      if (loop_i > num1_len) {
        result.push_back(flow_flag + num2[loop_i]);
      } else if (loop_i > num2_len) {
        result.push_back(flow_flag + num1[loop_i]);
      } else {
        result.push_back(flow_flag + num1[loop_i] + num2[loop_i]);
      }
      flow_flag = result.back() / 10;
      result.back() %= 10;
      result.back() += '0';
    }
    if (flow_flag != 0) {
      result.push_back('1');
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
};