#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> findOcurrences(string text, string first, string second) {
    std::vector<string> result;
    std::vector<string> splited_vec;
    int last_begin = 0;
    for (int loop_i = 0; loop_i < text.size(); ++loop_i) {
      if (text[loop_i] == ' ') {
        splited_vec.push_back(std::string(text.begin() + last_begin, text.begin() + loop_i));
        last_begin = loop_i + 1;
      }
    }
    splited_vec.push_back(std::string(text.begin() + last_begin, text.end()));

    for (int loop_i = 0; loop_i < splited_vec.size() - 2; ++loop_i) {
      if (splited_vec[loop_i] == first && splited_vec[loop_i + 1] == second) {
        result.push_back(splited_vec[loop_i + 2]);
      }
    }
    return result;
  }
};