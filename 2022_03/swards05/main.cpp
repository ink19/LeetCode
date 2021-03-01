#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string replaceSpace(string s) {
    const int str_len = s.length();
    const int space_num = std::accumulate(s.begin(), s.end(), 0, [](int space_num, char c) {
      if (c == ' ') return space_num + 1;
      else return space_num;
    });
    const int result_str_len = str_len + space_num * 2;
    string result(result_str_len, 0);
    int result_loop = 0;
    for (int loop_i = 0; loop_i < str_len; ++loop_i) {
      if (s[loop_i] == ' ') {
        result[result_loop++] = '%';
        result[result_loop++] = '2';
        result[result_loop++] = '0';
      } else {
        result[result_loop++] = s[loop_i];
      }
    }
    return result;
  }
};