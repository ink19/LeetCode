#include <vector>

using namespace std;

class Solution {
public:
  int missingNumber(vector<int> &nums) {
    if (nums.back() == nums.size() - 1) return nums.size();
    int begin = 0;
    int end = nums.size() - 1;
    while (begin < end){
      int mid = (begin + end) >> 1;
      if (nums[mid] == mid) {
        begin = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    if (begin == nums[begin]) return begin + 1;
    return begin;
  }
};