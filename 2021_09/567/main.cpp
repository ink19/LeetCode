#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    const int s1_len = s1.size();
    const int s2_len = s2.size();
    if (s2_len < s1_len) return false;
    std::vector<int> s1_map(26, 0);
    std::vector<int> s2_win_map(26, 0);
    for (int loop_i = 0; loop_i < s1_len; ++loop_i) {
      s1_map[s1[loop_i] - 'a'] += 1;
      s2_win_map[s2[loop_i] - 'a'] += 1;
    }

    if (check_map(s1_map, s2_win_map)) return true;

    for (int loop_i = s1_len; loop_i < s2_len; ++loop_i) {
      s2_win_map[s2[loop_i] - 'a'] += 1;
      s2_win_map[s2[loop_i - s1_len] - 'a'] -= 1;

      if (check_map(s1_map, s2_win_map)) return true;
    }
    return false;
  }

  bool check_map(const std::vector<int> &s1_map, const std::vector<int> &s2_map) {
    for (int loop_i = 0; loop_i < 26; ++loop_i) {
      if (s1_map[loop_i] != s2_map[loop_i]) return false;
    }
    return true;
  }
};