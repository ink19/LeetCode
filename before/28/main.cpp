#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    size_t haystack_len = haystack.size();
    size_t needle_len = needle.size();
    if (needle_len == 0) return 0;
    std::vector<int> kmp_table(needle_len, 0);
    for (int loop_i = 1; loop_i < needle_len; ++loop_i) {
      if (needle[loop_i] == needle[kmp_table[loop_i - 1]]) {
        kmp_table[loop_i] = kmp_table[loop_i - 1] + 1;
      } else {
        kmp_table[loop_i] = 0;
      }
    } 

    for (int loop_i = 0; loop_i < needle_len; ++loop_i) {
      std::cout << kmp_table[loop_i] << " ";
    }
    std::cout << std::endl;

    int kmp_index = 0;
    int match_index = 0;
    for (int loop_i = 0; loop_i < haystack_len; ++loop_i) {
      std::cout << loop_i << haystack[loop_i] << " " << match_index << needle[match_index] << std::endl;
      if (needle[match_index] == haystack[loop_i]) {
        
        match_index++;
        if (needle_len == match_index) return loop_i - match_index + 1;
        
      } else {
        if (match_index != 0) {
          match_index = kmp_table[match_index - 1];
          loop_i--;
        }
      }
    }
    return -1;
  }
};


int main() {
  Solution s;
  std::cout << s.strStr("aabaaabaaac", "aabaaac") << std::endl;
  return 0;
}