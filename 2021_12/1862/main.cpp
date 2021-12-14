#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int sumOfFlooredPairs(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    long long sum = 0;
    long long last = 0;
    for (int loop_i = 0; loop_i < nums.size(); ++loop_i) {
      if (loop_i != 0 && nums[loop_i] == nums[loop_i - 1]) {
        sum += last;
        sum %= 1000000007;
        continue;
      }
      auto iter_begin = std::upper_bound(nums.begin(), nums.end(), nums[loop_i] - 1);
      int rate = 1;
      last = 0;
      while (iter_begin != nums.end()) {
        rate = (*iter_begin)/nums[loop_i];
        auto iter_end = std::upper_bound(iter_begin, nums.end(), nums[loop_i] * (rate + 1) - 1);
        last += rate * (iter_end - iter_begin);
        sum += rate * (iter_end - iter_begin);
        sum %= 1000000007;
        iter_begin = iter_end;
      }
    }
    return sum;
  }
};

int main() {
  std::vector<int> data = {4,1,1,2,4};
  std::cout << Solution().sumOfFlooredPairs(data) << std::endl;
}