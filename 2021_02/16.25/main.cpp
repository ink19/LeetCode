#include <algorithm>
#include <iostream>
#include <list>
#include <utility>
#include <map>

class LRUCache {
public:
  LRUCache(int capacity): capacity(capacity) {}

  int get(int key) {
    auto re_data = data.find(key);
    if (re_data == data.end()) {
      return -1;
    } else {
      auto key_iter = std::find(stack.begin(), stack.end(), key);
      stack.erase(key_iter);
      stack.push_back(key);
      return re_data->second;
    }
  }

  void put(int key, int value) {
    auto re_data = data.find(key);
    if (re_data == data.end()) {
      data[key] = value;
      stack.push_back(key);
      if (stack.size() > capacity) {
        data.erase(data.find(*stack.begin()));
        stack.pop_front();

      }
    } else {
      data[key] = value;
      auto key_iter = std::find(stack.begin(), stack.end(), key);
      stack.erase(key_iter);
      stack.push_back(key);
    }
  }
private:
  int capacity;
  std::map<int, int> data;
  std::list<int> stack;
};

int main () {
  LRUCache obj(2);
  int param_1 = obj.get(1);
  obj.put(1, 2);
}