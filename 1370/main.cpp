#include <string>
#include <iostream>
using std::string;

class Solution {
public:
  string sortString(string s) {
    int char_n[26];
    int s_len = s.size();
    string result;
    for (int loop_i = 0; loop_i < 26; ++loop_i) {
      char_n[loop_i] = 0;
    }
    for (auto ms : s) {
      char_n[ms - 'a']++;
    }
    int resever = 0;
    while (result.size() != s_len) {
      if (resever == 0) {
        for (int loop_i = 0; loop_i < 26; ++loop_i) {
          if (char_n[loop_i] != 0) {
            result += static_cast<char>('a' + loop_i);
            char_n[loop_i]--;
          }
        }
        resever = 1;
      } else {
        for (int loop_i = 25; loop_i >= 0; --loop_i) {
          if (char_n[loop_i] != 0) {
            result += static_cast<char>('a' + loop_i);
            char_n[loop_i]--;
          }
        }
        resever = 0;
      }
      
    }
    return result;
  }
};

int main() {
  Solution s;
  std::cout << s.sortString("abcdefg") << std::endl;
}