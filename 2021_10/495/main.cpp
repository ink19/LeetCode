#include <vector>

using namespace std;

class Solution {
public:
  int findPoisonedDuration(vector<int> &timeSeries, int duration) {
    int now_time = 0;
    int du_time = 0;
    const int times_len = timeSeries.size();
    for (int loop_i = 0; loop_i < times_len; ++loop_i){
      int next_time = timeSeries[loop_i] + duration;
      du_time += next_time - std::max(now_time, timeSeries[loop_i]);
      now_time = next_time;
    }
    return du_time;
  }
};