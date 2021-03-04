#include <stack>
#include <utility>

class MinStack {
public:
  std::stack<std::pair<int, int>> data;
  MinStack() {}

  void push(int x) {
    if (data.empty()) {
      data.push({x, x});
    } else {
      if (min() > x) {
        data.push({x, x});
      } else {
        data.push({x, min()});
      }
    }
  }

  void pop() {
    if (!data.empty()) {
      data.pop();
    }
  }

  int top() {
    return data.top().first;
  }

  int min() {
    return data.top().second;
  }
};