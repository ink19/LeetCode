#include <iostream>
#include <vector>
#include <set>
#include <deque>

using namespace std;

class SlowSolution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    std::multiset<int> data;
    std::vector<int> result;
    const int nums_len = nums.size();
    for (int loop_i = 0; loop_i < nums_len; ++loop_i) {
      if (data.size() >= k) {
        data.erase(data.find(nums[loop_i - k]));
      } 
      data.insert(nums[loop_i]);
      if (data.size() >= k) {
        result.push_back(*data.rbegin());
      }
    }
    return result;
  }
};

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    std::deque<int> data;
    std::vector<int> result;
    const int nums_len = nums.size();
    if (nums_len == 0) return result;
    for (int loop_i = 0; loop_i < k - 1; ++loop_i) {
      while (data.size() != 0 && data.back() < nums[loop_i]) data.pop_back();
      data.push_back(nums[loop_i]);
    }
    for (int loop_i = k - 1; loop_i < nums_len; ++loop_i) {
      if (loop_i != k - 1 && nums[loop_i - k] == data.front()) {
        data.pop_front();
      }

      while (data.size() != 0 && data.back() < nums[loop_i]) data.pop_back();
      
      data.push_back(nums[loop_i]);
      result.push_back(data.front());
    }
    return result;
  }
};