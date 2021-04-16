#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int loop_i = 2, loop_j = 2;
    const int nums_len = nums.size();
    if (nums_len < 3) return nums_len;
    for (; loop_i < nums_len; ++loop_i) {
      if (nums[loop_i] != nums[loop_j - 2]){
        nums[loop_j] = nums[loop_i];
        loop_j++;
      }
    }
    return loop_j;
  }
};