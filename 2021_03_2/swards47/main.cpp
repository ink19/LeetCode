#include <vector>

using namespace std;

class Solution {
public:
  int maxValue(vector<vector<int>> &grid) {
    const int grid_row = grid.size();
    const int grid_col = grid.at(0).size();
    vector<vector<int>> dp(grid_row, vector<int>(grid_col, 0));
    dp[0][0] = grid[0][0];
    for (int loop_i = 1; loop_i < grid_row; ++loop_i) {
      dp[loop_i][0] = dp[loop_i - 1][0] + grid[loop_i][0];
    }
    for (int loop_i = 1; loop_i < grid_col; ++loop_i) {
      dp[0][loop_i] = dp[0][loop_i - 1] + grid[0][loop_i];
    }

    for (int loop_i = 1; loop_i < grid_row; ++loop_i) {
      for (int loop_j = 1; loop_j < grid_col; ++loop_j) {
        dp[loop_i][loop_j] = std::max(dp[loop_i - 1][loop_j], dp[loop_i][loop_j - 1]) + grid[loop_i][loop_j];
      }
    }
    return dp[grid_row - 1][grid_col - 1];
  }
};