#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<string> findWords(vector<string> &words) {
    const string level[] = {
      "qwertyuiop",
      "asdfghjkl",
      "zxcvbnm"
    };
    
    vector<int> char_map(26, -1);
    for (int loop_i = 0; loop_i < 3; ++loop_i) {
      for (int loop_j = 0; loop_j < level[loop_i].length(); ++loop_j) {
        char_map[std::tolower(level[loop_i][loop_j]) - 'a'] = loop_i;
      }
    } 

    vector<string> result;
    for (int loop_i = 0; loop_i < words.size(); ++loop_i) {
      auto temp_word = words.at(loop_i);
      int first_level = char_map[std::tolower(temp_word[0]) - 'a'];
      bool is_comm = true;
      for (int loop_j = 0; loop_j < temp_word.length(); ++loop_j) {
        if (first_level != char_map[std::tolower(temp_word[loop_j]) - 'a']) {
          is_comm = false;
          break;
        }
      }
      if (is_comm) {
        result.push_back(temp_word);
      }
    }

    return result;
  }
};

int main() {
  std::vector<string> data = {"Hello","Alaska","Dad","Peace"};
  Solution().findWords(data);
  return 0;
}