#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
  int findRadius(vector<int> &houses, vector<int> &heaters) {
    int last_heater = heaters[0];
    int heater_index = 0;
    int min_r = 0;
    std::sort(houses.begin(), houses.end());
    std::sort(heaters.begin(), heaters.end());
    for (int loop_i = 0; loop_i < houses.size(); ++loop_i) {
      while (heater_index < heaters.size() - 1 && heaters[heater_index] < houses[loop_i]) {
        last_heater = heaters[heater_index];
        heater_index++;
      }
      int local_min_r = std::min(std::abs(last_heater - houses[loop_i]), std::abs(heaters[heater_index] - houses[loop_i]));
      min_r = std::max(local_min_r, min_r);
    }
    return min_r;
  }
};