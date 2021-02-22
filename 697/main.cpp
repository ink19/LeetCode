#include <iostream>
#include <vector>
#include <map>
#include <tuple>
using namespace std;

class Solution {
public:
  int findShortestSubArray(vector<int> &nums) {
    std::map<int, std::tuple<int, int, int>> temp_result;
    const int nums_len = nums.size();
    for (int loop_i = 0; loop_i < nums_len; ++loop_i) {
      if (temp_result.count(nums[loop_i]) == 0) {
        temp_result[nums[loop_i]] = {1, loop_i, loop_i};
      } else {
        temp_result[nums[loop_i]] = {std::get<0>(temp_result[nums[loop_i]]) + 1, std::get<1>(temp_result[nums[loop_i]]), loop_i};
      }
    }

    int max_du = -1;
    int min_len = 600000;
    for (auto iter : temp_result) {
      if (std::get<0>(iter.second) == max_du) {
        int now_len = std::get<2>(iter.second) - std::get<1>(iter.second) + 1;
        if (now_len < min_len) {
          min_len = now_len;
        }
      } else if (std::get<0>(iter.second) > max_du) {
        max_du = std::get<0>(iter.second);
        int now_len = std::get<2>(iter.second) - std::get<1>(iter.second) + 1;
        min_len = now_len;
      }
    }
    return min_len;
  }
};

int main() {
  Solution s;
  vector<int> data = {1, 2, 2, 3};
  std::cout << s.findShortestSubArray(data) << std::endl;
  return 0;
}