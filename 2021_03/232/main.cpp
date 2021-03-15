#include <stack>

using namespace std;

class MyQueue {
public:
  /** Initialize your data structure here. */
  std::stack<int> in_stack;
  std::stack<int> out_stack;
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) {
    in_stack.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    if (empty()) {
      return -1;
    } else {
      if (out_stack.empty()) {
        switch_stack();
      }
      int data = out_stack.top();
      out_stack.pop();
      return data;
    }
  }

  /** Get the front element. */
  int peek() {
    if (empty()) {
      return -1;
    } else {
      if (out_stack.empty()) {
        switch_stack();
      }
      int data = out_stack.top();
      return data;
    }
  }

  /** Returns whether the queue is empty. */
  bool empty() {
    return in_stack.empty() && out_stack.empty();
  }

private:
  void switch_stack() {
    while (!in_stack.empty()) {
      out_stack.push(in_stack.top());
      in_stack.pop();
    }
  }
};