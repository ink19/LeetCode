#include <set>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int longestSubarray(vector<int> &nums, int limit) {
    const int nums_len = nums.size();
    std::multiset<int> win_set;
    int max_len = 0;
    int right = 0;
    for (int loop_i = 0; loop_i < nums_len; ++loop_i) {
      win_set.insert(nums[loop_i]);
      while (*win_set.rbegin() - *win_set.begin() > limit) {
        win_set.erase(win_set.find(nums[right]));
        right++;
      }
      if (win_set.size() > max_len) {
        max_len = win_set.size();
      }
    }
    return max_len;
  }
};

int main() {
  Solution s;
  vector<int> data = {2,2,2,4,4,2,5,5,5,5,5,2};
  std::cout << s.longestSubarray(data, 2) << std::endl;
}
