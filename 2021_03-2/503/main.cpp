#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    const int nums_len = nums.size();
    vector<int> res(nums_len, -1);
    stack<int> msta;
    for (int loop_i = 0; loop_i < nums_len * 2 - 1; ++loop_i) {
      while (!msta.empty() && nums[msta.top()] < nums[loop_i%nums_len]) {
        res[msta.top()] = nums[loop_i%nums_len];
        msta.pop();
      }
      msta.push(loop_i%nums_len);
    }
    return res;
  }
};