#include <stack>

class CQueue {
public:
  CQueue() {}

  void appendTail(int value) {
    instack.push(value);
  }

  int deleteHead() {
    if (outstack.empty()) {
      if (instack.empty()) {
        return -1;
      } else {
        switch_stack();
      }
    }
    int return_item = outstack.top();
    outstack.pop();
    return return_item;
  }

private:
  int switch_stack() {
    while (!instack.empty()) {
      outstack.push(instack.top());
      instack.pop();
    }
    return 0;
  }
  std::stack<int> instack;
  std::stack<int> outstack;
};
