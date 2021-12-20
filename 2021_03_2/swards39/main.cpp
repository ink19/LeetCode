#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int number = 0;
    int nnumber = 0;
    const int nums_len = nums.size();
    for (int loop_i = 0; loop_i < nums_len; ++loop_i) {
      if (nums[loop_i] == number) {
        nnumber++;
      } else {
        if (nnumber > 0) {
          nnumber--;
        } else {
          nnumber = 1;
          number = nums[loop_i];
        }
      }
    }
    return number;
  }
};
