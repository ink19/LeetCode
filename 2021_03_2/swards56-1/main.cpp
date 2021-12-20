#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> singleNumbers(vector<int> &nums) {
    int temp_data = 0;
    const int nums_len = nums.size();
    for (int loop_i = 0; loop_i < nums_len; ++loop_i) {
      temp_data ^= nums.at(loop_i);
    }
    int result1 = 0;
    int result2 = 0;
    int temp_i = 0;
    while (((1 << temp_i) & temp_data) == 0) temp_i++;
    temp_data = 1 << temp_i;
    for (int loop_i = 0; loop_i < nums_len; ++loop_i) {
      if ((nums.at(loop_i) & temp_data) == 0) {
        result1 ^= nums.at(loop_i);
      } else {
        result2 ^= nums.at(loop_i);
      }
    }
    return {result2, result1};
  }
};