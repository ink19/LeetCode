#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> result;
    const int words_len = words.size();
    std::vector<string> temp_line;
    int line_size = 0;
    for (int loop_i = 0; loop_i < words_len; ++loop_i) {
      if (temp_line.size() == 0) {
        if (line_size + words[loop_i].size() <= maxWidth) {
          temp_line.push_back(words[loop_i]);
          line_size += words[loop_i].size();
          continue;
        }
      } else {
        if (line_size + words[loop_i].size() + 1 <= maxWidth) {
          temp_line.push_back(words[loop_i]);
          line_size += words[loop_i].size() + 1;
          continue;
        }
      }
      
      loop_i--;
      int space_size = maxWidth - line_size;
      if (temp_line.size() == 1) {
        std::string space(space_size, ' ');
        result.push_back(temp_line[0] + space);
        line_size = 0;
        temp_line.clear();
        continue;
      }
      int avg_space = space_size / (temp_line.size() - 1);
      int ext_space = space_size % (temp_line.size() - 1);
      std::string temp_line_s;
      for (int loop_j = 0; loop_j < temp_line.size(); ++loop_j) {
        temp_line_s += temp_line[loop_j];
        if (loop_j != temp_line.size() - 1) {
          temp_line_s += string(avg_space + 1, ' ');
          if (ext_space != 0) {
            temp_line_s += ' ';
            ext_space--;
          }
        }
      }
      result.push_back(temp_line_s);
      line_size = 0;
      temp_line.clear();
    }

    if (temp_line.size() != 0) {
      std::string temp_line_s;
      for (int loop_i = 0; loop_i < temp_line.size(); ++loop_i) {
        temp_line_s += temp_line[loop_i];
        if (loop_i != temp_line.size() - 1) {
          temp_line_s += ' ';
        }
      }
      temp_line_s += std::string(maxWidth - temp_line_s.size(), ' ');
      result.push_back(temp_line_s);
    }

    return result;
  }
};