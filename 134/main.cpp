#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    const int road_len = gas.size();
    for (int loop_i = 0; loop_i < road_len; ++loop_i) {
      gas[loop_i] -= cost[loop_i];
    }

    cost[0] = gas[0];
    for (int loop_i = 1; loop_i < road_len; ++loop_i) {
      cost[loop_i] = gas[loop_i] + cost[loop_i - 1];
    }

    if (cost.back() < 0) return -1;

    int min_number = 1e9;
    int min_index = 0;
    for (int loop_i = 0; loop_i < road_len; ++loop_i) {
      if (cost[loop_i] < min_number) {
        min_number = cost[loop_i];
        min_index = loop_i;
      }
    }
    if (min_number >= 0) return 0;
    return (min_index + 1);
  }
};