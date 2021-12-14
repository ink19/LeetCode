#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    const int a_len = a.size();
    const int b_len = b.size();
    for (int loop_i = 0; loop_i < a_len; ++loop_i) {
      a[loop_i] -= '0';
    }
    for (int loop_j = 0; loop_j < b_len; ++loop_j) {
      b[loop_j] -= '0';
    }
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    std::string result;
    const int max_len = std::max(a_len, b_len);
    int into = 0;
    for (int loop_i = 0; loop_i < max_len; ++loop_i) {
      if (loop_i >= a_len) {
        result.push_back(b[loop_i] + into);
      } else if (loop_i >= b_len) {
        result.push_back(a[loop_i] + into);
      } else {
        result.push_back(a[loop_i] + b[loop_i] + into);
      }
      if (result.back() >= 2) {
        result.back() %= 2;
        into = 1;
      } else {
        into = 0;
      }
    }
    if (into != 0) result.push_back(1);
    
    for (int loop_i = 0; loop_i < result.size(); ++loop_i) result[loop_i] += '0';
    std::reverse(result.begin(), result.end());
    return result;
  }
};