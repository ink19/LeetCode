#include <iostream>
#include <string>
#include <stack>
#include <numeric>

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
    int data;
    int data_type;
    string::iterator s_iter = s.begin();
    int now_f = 1;
    int last_flag = 0;
    while (nextData(s_iter, s.end(), data, data_type)) {
      if (data_type == 1) {
        if (last_flag == 1) {
          int temp_data = data_stack.top();
          data_stack.pop();
          data_stack.push(temp_data * data * now_f);
          last_flag = 0;
        } else if (last_flag == 2) {
          int temp_data = data_stack.top();
          data_stack.pop();
          data_stack.push(temp_data / data * now_f);
          last_flag = 0;
        } else {
          data_stack.push(data * now_f);
        }
        now_f = 1;
      } else {
        if (data == '-') {
          now_f *= -1;
        } else if (data == '*') {
          last_flag = 1;
        } else if (data == '/') {
          last_flag = 2;
        } 
      }
    }
    int result = 0;
    while (!data_stack.empty()) {
      result += data_stack.top();
      data_stack.pop();
    }
    return result;
  }
};

int main() {
  Solution s;
  std::cout << s.calculate("3+2*2+3-3/2") << std::endl;
  return 0;
}