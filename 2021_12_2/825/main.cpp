#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
  int numFriendRequests(vector<int> &ages) {
    std::sort(ages.begin(), ages.end());
    int result = 0;
    for (int loop_i = 0; loop_i < ages.size(); ++loop_i) {
      int begin = ages[loop_i] * 0.5 + 7;
      int end = ages[loop_i];
      auto iter_begin = std::upper_bound(ages.begin(), ages.end(), begin);
      auto iter_end = std::upper_bound(ages.begin(), ages.end(), end);
      result += std::max<int>(iter_end - iter_begin, 1) - 1;
    }
    return result;
  }
};