#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define PI 3.14159265358979323846

class Solution {
public:
  int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &location) {
    std::vector<double> point_angles;
    int base_result = 0;
    for (int loop_i = 0; loop_i < points.size(); ++loop_i) {
      int ax = points[loop_i][0] - location[0];
      int ay = points[loop_i][1] - location[1];
      if (ax == 0 && ay == 0) base_result++;
      else if (ay == 0) point_angles.push_back(ax > 0? 90: 270);
      else if (ax == 0) point_angles.push_back(ay > 0? 180: 0);
      else point_angles.push_back((ax > 0?90: 270) + std::atan(ay/(double)ax) * 180 / PI);
    }
    const int point_len = point_angles.size();
    // std::cout << base_result << std::endl;
    int result = 0;
    
    std::sort(point_angles.begin(), point_angles.end());

    

    for (int loop_i = 0; loop_i < point_len; ++loop_i) {
      double now_angle = point_angles[loop_i];
      if (now_angle + angle <= 360) {
        auto iter = std::upper_bound(point_angles.begin(), point_angles.end(), now_angle + angle);
        if (result < (iter - (point_angles.begin() + loop_i))) {
          result = iter - (point_angles.begin() + loop_i);
        }
      } else {
        double find_angle = (now_angle + angle) - 360;
        int watch_num = point_len - loop_i;
        auto iter = std::upper_bound(point_angles.begin(), point_angles.end(), find_angle);
        watch_num += iter - point_angles.begin();
        if (watch_num > result) result = watch_num;
      }
    }
    
    return base_result + result;
  }
};

int main() {
  std::vector<std::vector<int>> data = {{58, 47},{26, 50},{70, 21},{51, 24},{55, 14},{64, 21},{66, 33},{54, 35},{87, 38},{30, 0},{92, 12},{88, 24}};
  std::vector<int> p = {15,50};
  std::cout << Solution().visiblePoints(data, 44, p) << std::endl;
}
/*
[[60,61],[58,47],[17,26],[87,97],[63,63],[26,50],[70,21],[3,89],[51,24],[55,14],[6,51],[64,21],[66,33],[54,35],[87,38],[30,0],[37,92],[92,12],[60,73],[75,98],[1,11],[88,24],[82,92]]
44
[15,50]

*/