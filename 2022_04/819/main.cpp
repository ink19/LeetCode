#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
  std::vector<string> get_freq(string paragraph) {
    std::vector<string> result;
    int begin = -1;
    for (int loop_i = 0; loop_i < paragraph.size() + 1; ++loop_i) {
      if (loop_i == paragraph.size()) goto now;
      if ((paragraph[loop_i] >= 'a' && paragraph[loop_i] <= 'z')) {
        continue;
      }
      if (paragraph[loop_i] >= 'A' && paragraph[loop_i] <= 'Z') {
        paragraph[loop_i] = paragraph[loop_i] - ('A' - 'a');
        continue;
      }
      now:
      if (begin + 1 == loop_i) {
        begin = loop_i;
      } else {
        result.push_back(
          paragraph.substr(begin + 1, loop_i - (begin + 1))
        );
        begin = loop_i;
      }
    }
    return result;
  }
  string mostCommonWord(string paragraph, vector<string> &banned) {
    int max_num = 0;
    std::string max_word = "";
    auto split_word = get_freq(paragraph);
    std::map<std::string, int> word_freq;
    for (int loop_i  = 0; loop_i < split_word.size(); ++loop_i) {
      if (std::find(banned.begin(), banned.end(), split_word[loop_i]) == banned.end()) {
        word_freq[split_word[loop_i]]++;
      }
    }
    for (auto item : word_freq) {
      if (item.second > max_num) {
        max_word = item.first;
        max_num = item.second;
      }
    }
    return max_word;
  }
};


int main() {
  auto data = std::vector<std::string>({"hit"});
  std::cout << Solution().mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", data) << std::endl;;
}