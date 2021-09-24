#include <vector>

using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    const int height = obstacleGrid.size();
    const int width = obstacleGrid[0].size();
    vector<vector<int>> dp(height, vector<int>(width, 0));
    if (obstacleGrid[0][0] != 1) {
        dp[0][0] = 1;
    } 
    for (int loop_i = 1; loop_i < height; ++loop_i) {
      if (obstacleGrid[loop_i][0] != 1) {
        dp[loop_i][0] = dp[loop_i - 1][0];
      } else {
        dp[loop_i][0] = 0;
      }
    }

    for (int loop_i = 1; loop_i < width; ++loop_i) {
      if (obstacleGrid[0][loop_i] != 1) {
        dp[0][loop_i] = dp[0][loop_i - 1];
      } else {
        dp[0][loop_i] = 0;
      }
    }

    for (int loop_h = 1; loop_h < height; ++loop_h) {
      for (int loop_w = 1; loop_w < width; ++loop_w) {
        if (obstacleGrid[loop_h][loop_w] == 1) {
          dp[loop_h][loop_w] = 0;
        } else {
          dp[loop_h][loop_w] = dp[loop_h][loop_w - 1] + dp[loop_h - 1][loop_w];
        }
      }
    }

    return dp[height - 1][width - 1];
  }
};