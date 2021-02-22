#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
    if (nums.size() == 0) return nums;
    int nums_size = nums.size() * nums[0].size();
    if (r * c != nums_size) return nums;
    std::vector<std::vector<int>> new_mat(r, vector<int>(c));
    int loop_old_r = 0;
    int loop_old_c = 0;
    for (int loop_i = 0; loop_i < r; ++loop_i) {
      for (int loop_j = 0; loop_j < c; ++loop_j) {
        new_mat[loop_i][loop_j] = nums[loop_old_c][loop_old_r];
        loop_old_r++;
        if (loop_old_r >= nums[0].size()) {
          loop_old_r = 0;
          loop_old_c++;
        }
      }
    }
    return new_mat;
  }
};