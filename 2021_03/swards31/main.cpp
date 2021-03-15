#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    std::stack<int> msta;
    int loop_pop = 0;
    int loop_push = 0;
    const int stack_size = pushed.size();
    if (stack_size == 0) return true;

    while (true) {
      if (msta.empty()) {
        if (loop_push == stack_size) {
          return false;
        }
        msta.push(pushed[loop_push++]);
      }
      if (popped[loop_pop] == msta.top()) {
        msta.pop();
        loop_pop++;
        if (loop_pop == stack_size) return true;
      } else {
        if (loop_push == stack_size) {
          return false;
        } 
        msta.push(pushed[loop_push++]);
      }
    }
    return false;
  }
};