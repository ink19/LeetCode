#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool isXiaoShu(const string &s) {
    if (isZhengShu(s)) return true;
    int dot_n = 0;
    int dig_n = 0;
    int begin_index = 0;
    if (s[0] == '+' || s[0] == '-') {
      begin_index++;
    }
    
    for (int loop_i = begin_index; loop_i < s.size();++loop_i) {
      if (std::isdigit(s[loop_i])) dig_n++;
      else if (s[loop_i] == '.') dot_n++;
      else return false;
    }
    if (dig_n > 0 && dot_n == 1) return true;
    return false;
  }
  bool isZhengShu(const string &s) {
    int begin_index = 0;
    if (s[0] == '+' || s[0] == '-') {
      begin_index++;
    }
    if (s.size() <= begin_index) return false;
    for (int loop_i = begin_index; loop_i < s.size(); ++loop_i) {
      if (!std::isdigit(s[loop_i])) return false;
    }
    return true;
  }
  bool isNumber(string s) {
    auto e_pos = s.find('e');
    auto E_pos = s.find('E');
    if (e_pos != s.npos && E_pos != s.npos) return false;
    if (e_pos == s.npos) e_pos = E_pos;
    if (e_pos == s.npos) return isXiaoShu(s);
    if (e_pos == 0 || e_pos == s.size() - 1) return false;
    auto s1 = s.substr(0, e_pos);
    auto s2 = s.substr(e_pos + 1);
    return isXiaoShu(s1) && isZhengShu(s2);
  }
};

int main() {
  std::cout << Solution().isNumber("2e0");
}


class Solution1 {
public:
  bool isXiaoShu(const string &s) {
    if (isZhengShu(s)) return true;
    int dot_n = 0;
    int dig_n = 0;
    int begin_index = 0;
    if (s[0] == '+' || s[0] == '-') {
      begin_index++;
    }
    
    for (int loop_i = begin_index; loop_i < s.size();++loop_i) {
      if (std::isdigit(s[loop_i])) dig_n++;
      else if (s[loop_i] != '.') dot_n++;
      else return false;
    }
    if (dig_n > 0 && dot_n == 1) return true;
    return false;
  }
  bool isZhengShu(const string &s) {
    int begin_index = 0;
    if (s[0] == '+' || s[0] == '-') {
      begin_index++;
    }
    if (s.size() <= begin_index) return false;
    for (int loop_i = begin_index; loop_i < s.size(); ++loop_i) {
      if (!std::isdigit(s[loop_i])) return false;
    }
    return true;
  }
  bool isNumber(string s) {
    auto e_pos = s.find('e');
    auto E_pos = s.find('E');
    if (e_pos != s.npos || E_pos != s.npos) return false;
    if (e_pos == s.npos) e_pos = E_pos;
    if (e_pos == s.npos) return isXiaoShu(s);
    if (e_pos == 0 || e_pos == s.size() - 1) return false;
    auto s1 = s.substr(0, e_pos - 1);
    auto s2 = s.substr(e_pos + 1);
    return isXiaoShu(s1) && isZhengShu(s2);
  }
};