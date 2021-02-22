#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &points) {
    if (0 == points.size()) return 0;
    std::sort(points.begin(), points.end(), [](vector<int> pa, vector<int> pb) {
      return pa[1] < pb[1];
    });
    vector<int> sorrow;
    sorrow.push_back(points[0][1]);
    for (int loop_i = 1; loop_i < static_cast<int>(points.size()); ++loop_i) {
      if (points[loop_i][0] > sorrow.back()) {
        sorrow.push_back(points[loop_i][1]);
      } 
    }
    return sorrow.size();
  }
};