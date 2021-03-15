#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  bool isDig(char c) {
    return c <= '9' && c >= '0';
  }
  
  int NoNumber(string s, int begin) {
    while (isDig(s[begin])) begin++;
    return begin;
  }
  
  string NoBlank(const string& s) {
    auto begin_iter = s.begin();
    auto end_iter = s.end();
    while (*begin_iter == ' ' && begin_iter != s.end()) begin_iter++;
    while (*(end_iter - 1) == ' ' && end_iter != begin_iter) end_iter--;
    if (end_iter == begin_iter) {
      return string();
    } else {
      return string(begin_iter, end_iter);
    }
  }

  bool isNumber(string s) {
    s = NoBlank(s);
    const int s_len = s.size();
    bool has_dot = false;
    bool has_e = false;
    // head
    int begin = 0;
    if (s_len == 0) return false;
    if (s[begin] == '-' || s[begin] == '+') {
      begin++;
      if (s_len == begin) return false;
    } 

    if (s[begin] == '.') {
      begin++;
      has_dot = true;
      if (s_len == begin) return false;
    }

    if (!isDig(s[begin])) return false;
    begin = NoNumber(s, begin);

    if (begin == s_len) return true;

    if (s[begin] == '.') {
      if (has_dot == true) return false;
      has_dot = true;
      begin++;
    }

    if (begin == s_len) return true;

    begin = NoNumber(s, begin);

    if (s[begin] == 'e' || s[begin] == 'E') {
      has_e = true;
      begin++;
      if (begin == s_len) return false;
      if (s[begin] == '+' || s[begin] == '-') begin++;
      if (begin == s_len) return false;
    }

    begin = NoNumber(s, begin);

    if (begin != s_len) return false;
    else return true;
  }
};


int main() {
  Solution s;
  std::cout << s.isNumber("1.431352e7") << std::endl;
}