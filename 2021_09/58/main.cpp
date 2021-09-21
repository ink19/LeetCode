#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    s += " ";
    const int s_len = s.size();
    int max_word_len = 0;
    int word_len = 0;
    for (int loop_i = 0; loop_i < s_len; ++loop_i) {
      if (s[loop_i] == ' ') {
        if (word_len == 0) continue;
        max_word_len = word_len;
        word_len = 0;
      } else {
        word_len++;
      }
    }
    return max_word_len;
  }
};