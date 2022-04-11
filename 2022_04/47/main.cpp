#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  std::set<std::vector<int>> result;

  void iter_n(std::vector<int> &va, int n) {
    if (n == va.size() - 1) {
      result.insert(va);
      return;
    }
    iter_n(va, n + 1);
    for (int loop_i = n + 1; loop_i < va.size(); ++loop_i) {
      std::swap(va[n], va[loop_i]);
      iter_n(va, n + 1);
      std::swap(va[n], va[loop_i]);
    }
  }

  vector<vector<int>> permuteUnique(vector<int> &nums) {
    iter_n(nums, 0);
    return std::vector<std::vector<int>>(result.begin(), result.end());
  }
};
