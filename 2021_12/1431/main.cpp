#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
    int max_candies = *std::max_element(candies.begin(), candies.end());
    std::vector<bool> result(candies.size(), false);
    for (int loop_i = 0; loop_i < candies.size(); ++loop_i) {
      if (candies[loop_i] + extraCandies >= max_candies) result[loop_i] = true;
    }
    return result;
  }
};