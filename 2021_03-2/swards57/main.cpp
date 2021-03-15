#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    int begin = 0;
    int end = nums.size() - 1;
    while (nums[begin] + nums[end] != target) {
      if (nums[begin] + nums[end] > target) {
        end--;
      } else {
        begin++;
      }
    }
    return {nums[begin], nums[end]};
  }
};