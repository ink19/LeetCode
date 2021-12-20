#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
  bool isDig(char c) {
    if (c >= '0' && c <= '9') return true;
    return false;
  }
  bool nextDigest(std::string::iterator &now, std::string::iterator end, int& data) {
    int num = 0;
    while (now != end && isDig(*now)) {
      num *= 10;
      num += *now - '0';
      now++;
    }
    data = num;
    return true;
  }
  bool nextData(std::string::iterator &now, std::string::iterator end, int &data, int &data_type) {
    while(now != end && *now == ' ') now++;
    if (now == end) return false;

    if (isDig(*now)) {
      nextDigest(now, end, data);
      data_type = 1;
      return true;
    }

    data = *now;
    data_type = 2;
    now++;
    return true;
  }
  int calculate(string s) {
    std::stack<int> data_stack;
    data_stack.push(1);
    int now_result = 0;
    int now_f = 1;
    int data = 0;
    int data_type = 0;
    string::iterator iter_s = s.begin();
    while (nextData(iter_s, s.end(), data, data_type)) {
      if (data_type == 1) {
        now_result += data * now_f * data_stack.top();
        now_f = 1;
      } else {
        if (data == '(') {
          data_stack.push(now_f * data_stack.top());
          now_f = 1;
        } else if (data == ')') {
          data_stack.pop();
          now_f = 1;
        } else if (data == '-') {
          now_f *= -1;
        }
      }
    }
    return now_result;
  }
};


int main() {
  Solution s;
  std::cout << s.calculate("(1+(4+5+2)-3)+(6+8)") << std::endl;
  return 0;
}