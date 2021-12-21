#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int calPoints(vector<string> &ops) {
    std::stack<int> sk;
    for (int loop_i = 0; loop_i < ops.size(); ++loop_i) {
      if (ops[loop_i] == "D") sk.push(sk.top() * 2);
      else if (ops[loop_i] == "C") sk.pop();
      else if (ops[loop_i] == "+") {
        int temp_data = sk.top();
        sk.pop();
        int next_data = sk.top() + temp_data;
        sk.push(temp_data);
        sk.push(next_data);
      }
      else sk.push(std::atoi(ops[loop_i].c_str()));
    }
    int result = 0;
    while (!sk.empty()) {
      result += sk.top();
      sk.pop();
    }
    return result;
  }
};
