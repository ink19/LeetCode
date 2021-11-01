#include <stack>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
  bool isTagNameValid(string::iterator begin_iter, string::iterator end_iter, string::iterator &next_iter) {
    bool is_finish = false;
    if (*begin_iter == '/') {
      is_finish = true;
      begin_iter++;
    }

    auto find_iter = std::find(begin_iter, end_iter, '>');
    if (find_iter == end_iter) {
      return false;
    }

    string tag_name(begin_iter, find_iter);
    if (tag_name.size() < 1 || tag_name.size() > 9) return false;
    next_iter = find_iter + 1;

    if (is_finish) {
      if (tag_stack.empty()) return false;
      if (tag_stack.top() == tag_name) {
        tag_stack.pop();
        if (tag_stack.empty()) {
          if (next_iter != end_iter) {
            return false;
          }
        }
        return true;
      } else {
        return false;
      }
    } else {
      for (int loop_i = 0; loop_i < tag_name.size(); ++loop_i) {
        if (!std::isupper(tag_name[loop_i])) {
          return false;
        }
      }
      tag_stack.push(tag_name);
      return true;
    }
  }

  bool isValidCData(string::iterator begin_iter, string::iterator end_iter, string::iterator &next_iter) {
    if (end_iter - begin_iter < 8) {
      return false;
    }
    string begin_tag(begin_iter, begin_iter + 8); 
    if (begin_tag != "![CDATA[") {
      return false;
    } 
    for (auto loop_iter = begin_iter; loop_iter != end_iter; ++loop_iter) {
      if (*loop_iter == ']' && end_iter - loop_iter >= 3) {
        if (*(loop_iter + 1) == ']' && *(loop_iter + 2) == '>') {
          next_iter = loop_iter + 3;
          return true;
        } 
      }
    }
    return false;
  }

  bool TagOrCData(string::iterator begin_iter, string::iterator end_iter, string::iterator &next_iter) {
    if (*begin_iter == '!') {
      return isValidCData(begin_iter, end_iter, next_iter);
    } else {
      return isTagNameValid(begin_iter, end_iter, next_iter);
    }
  }

  bool isValid(string code) {
    auto begin_iter = code.begin();
    auto end_iter = code.end();
    if (end_iter - begin_iter < 2) return false;
    if (*begin_iter != '<' || *(begin_iter + 1) == '!') return false;
    while (begin_iter != end_iter) {
      if (*(begin_iter) == '<') {
        begin_iter++;
        if (!TagOrCData(begin_iter, end_iter, begin_iter)) {
          return false;
        } 
      } else {
        begin_iter++;
      }
    }
    if (tag_stack.empty()) {
      return true;
    } else {
      return false;
    }
  }
private:
  std::stack<string> tag_stack;
};


int main() {
  string data = "<DIV>This is the first line <![CDATA[<div>]]></DIV>";
  std::cout << Solution().isValid(data) << std::endl;
}