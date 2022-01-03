#include <vector>

using namespace std;

class Solution {
public:
  int findMagicIndex(vector<int> &nums) {
    for (int loop_i = 0; loop_i < nums.size(); ++loop_i) {
      if (loop_i == nums[loop_i]) return loop_i;
    }
    return -1;
  }
};
