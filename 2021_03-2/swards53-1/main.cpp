#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    return std::upper_bound(nums.begin(), nums.end(), target) - std::lower_bound(nums.begin(), nums.end(), target);
  }
};