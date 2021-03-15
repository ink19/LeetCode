#include <deque>
#include <queue>

class MaxQueue {
public:
  std::queue<int> data;
  std::deque<int> max_data;
  MaxQueue() {}

  int max_value() {
    if (data.size() == 0) return -1;
    return max_data.front();
  }

  void push_back(int value) {
    data.push(value);
    while (max_data.size() != 0 && max_data.back() < value) max_data.pop_back();
    max_data.push_back(value);
  }

  int pop_front() {
    if (data.size() == 0) return -1;
    int mdata = data.front();
    data.pop();
    if (max_data.front() == mdata) max_data.pop_front();
    return mdata;
  }
};
