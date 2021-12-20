#include <string>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
  char firstUniqChar(string s) {
    const int s_len = s.size();
    std::vector<std::pair<int, int>> data(26, std::pair<int, int>(-1, 0));
    for (int loop_i = 0; loop_i < s_len; ++loop_i) {
      auto item = data[s[loop_i] - 'a'];
      if (item.first == -1) {
        data[s[loop_i] - 'a'] = {loop_i, 1};
      } else {
        data[s[loop_i] - 'a'] = {item.first, item.second + 1};
      }
    }
    int min_echo = 1000000;
    for (int loop_i = 0; loop_i < 26; ++loop_i) {
      if (data[loop_i].second == 1 && data[loop_i].first < min_echo) {
        min_echo = data[loop_i].first;
      }
    }
    if (min_echo != 1000000) return s[min_echo];
    return ' ';
  }
};