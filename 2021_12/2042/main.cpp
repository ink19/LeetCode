#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool areNumbersAscending(string s) {
    const int s_len = s.size();
    int last_number = 0;
    for (int loop_i = 0; loop_i < s_len; ++loop_i) {
      if (std::isdigit(s[loop_i])) {
        int now_number = 0;
        int loop_j = 0;
        while (loop_i + loop_j < s_len && std::isdigit(s[loop_i + loop_j])) {
          now_number *= 10;
          now_number += s[loop_i + loop_j] - '0';
          loop_j++;
        }
        if (now_number <= last_number) return false;
        last_number = now_number;
        loop_i += loop_j;
      }
    }
    return true;
  }
};