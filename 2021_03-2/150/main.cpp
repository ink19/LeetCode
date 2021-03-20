#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
  bool isNumber(const std::string &str) {
    if (str.length() >= 2) {
      return true;
    }
    if (str[0] >= '0' && str[0] <= '9') return true;
    return false;
  }

  int evalRPN(vector<string> &tokens) {
    std::stack<int> data;
    const int tokens_len = tokens.size();
    for (int loop_i = 0; loop_i < tokens_len; ++loop_i) {
      if (isNumber(tokens[loop_i])) {
        data.push(std::atoi(tokens[loop_i].c_str()));
      } else {
        int data2 = data.top();
        data.pop();
        int data1 = data.top();
        data.pop();
        switch (tokens[loop_i][0]) {
          case '+':
            data1 += data2;
            break;
          case '-':
            data1 -= data2;
            break;
          case '*':
            data1 *= data2;
            break;
          case '/':
            data1 /= data2;
            break;
        }
        std::cout << data1 << std::endl;
        data.push(data1);
      }
    }
    return data.top();
  }
};


int main() {
  std::vector<std::string> data = {"4","13","5","/","+"};
  Solution s;
  std::cout << s.evalRPN(data) << std::endl;
}