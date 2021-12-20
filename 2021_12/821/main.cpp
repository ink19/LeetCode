#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
  vector<int> shortestToChar(string s, char c) {
    const int s_len = s.size();
    std::vector<int> c_pos;
    std::vector<int> result(s_len, 0);
    for (int loop_i = 0; loop_i < s_len; ++loop_i) {
      if (s[loop_i] == c) c_pos.push_back(loop_i);
    }

    int last_c = c_pos[0];
    int c_pos_index = 0;
    for (int loop_i = 0; loop_i < s_len; ++loop_i) {
      while(c_pos_index < c_pos.size() - 1 && c_pos[c_pos_index] < loop_i) {
        last_c = c_pos[c_pos_index];
        c_pos_index++;
      }
      result[loop_i] = std::min(std::abs(loop_i - last_c), std::abs(loop_i - c_pos[c_pos_index]));
    }
    return result;
  }
};