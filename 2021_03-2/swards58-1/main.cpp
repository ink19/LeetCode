#include <string>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
  bool non_blank(std::string::iterator &begin, const std::string::iterator &end) {
    while (begin != end && *begin == ' ') begin++;
    if (begin == end) {
      return false;
    } else {
      return true;
    }
  }
  bool blank(std::string::iterator &begin, const std::string::iterator &end) {
    while (begin != end && *begin != ' ') begin++;
    if (begin == end) {
      return false;
    } else {
      return true;
    }
  }
  std::vector<string> split(string s) {
    std::vector<string> result;
    std::string::iterator iter = s.begin();
    while (non_blank(iter, s.end())) {
      auto an_iter = iter;
      blank(an_iter, s.end());
      result.push_back(std::string(iter, an_iter));
      iter = an_iter;
    }
    return result;
  }

  std::string join(std::vector<std::string> data) {
    std::string result;
    for (int loop_i = 0; loop_i < data.size(); ++loop_i) {
      if (loop_i != data.size() - 1) {
        result.append(data.at(loop_i).begin(), data.at(loop_i).end());
        result.push_back(' ');
      } else {
        result.append(data.at(loop_i).begin(), data.at(loop_i).end());
      }
    }
    return result;
  }

  string reverseWords(string s) {
    auto split_s = split(s);
    std::reverse(split_s.begin(), split_s.end());
    return join(split_s);
  }
};