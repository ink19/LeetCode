#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    const int str1_len = word1.size();
    const int str2_len = word2.size();
    string result(str1_len + str2_len, 0);
    const int min_len = std::min(str1_len, str2_len);
    for (int loop_i = 0; loop_i < min_len; ++loop_i) {
      result[loop_i * 2] = word1[loop_i];
      result[loop_i * 2 + 1] = word2[loop_i];
    }
    const int max_len = std::max(str2_len, str1_len);
    const string& max_str = str1_len > str2_len? word1: word2;
    for (int loop_i = min_len; loop_i < max_len; ++loop_i) {
      result[min_len + loop_i] = max_str[loop_i];
    }
    return result;
  }
};