#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    auto iter_i = nums.begin();
    while (iter_i != nums.end() && iter_i + 1 != nums.end()) {
      if (*iter_i == *(iter_i + 1)) {
        iter_i += 3;
      } else {
        return *iter_i;
      }
    }
    return *iter_i;
  }
};