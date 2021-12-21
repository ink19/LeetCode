#include <vector>
#include <algorithm>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
  int removeCoveredIntervals(vector<vector<int>> &intervals) {
    int result = 0;
    std::sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
      return (a[1] - a[0]) > (b[1] - b[0]);
    });
    const int intervals_len = intervals.size();
    for (int loop_i = 0; loop_i < intervals_len; ++loop_i) {
      const auto item_i = intervals[loop_i];
      for (int loop_j = 0; loop_j < loop_i; ++loop_j) {
        const auto item_j = intervals[loop_j];
        if (item_i[0] >= item_j[0] && item_i[1] <= item_j[1]) {
          result++;
          break;
        }
      }
    }
    return intervals.size() - result;
  }
};


int main() {
  vector<vector<int>> data = {{1,4},{3,6},{2,8}};
  std::cout << Solution().removeCoveredIntervals(data) << std::endl;
}