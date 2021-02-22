#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isToeplitzMatrix(vector<vector<int>> &matrix) { 
    int m = matrix.size();
    int n = matrix[0].size();
    for (int loop_i = 0; loop_i < n; ++loop_i) {
      int same_num = matrix[0][loop_i];
      for (int loop_j = 0; loop_j < std::min(n - loop_i, m); ++loop_j) {
        if (same_num != matrix[loop_j][loop_j + loop_i]) {
          return false;
        }
      }
    }

    for (int loop_i = 0; loop_i < m; ++loop_i) {
      int same_num = matrix[loop_i][0];
      for (int loop_j = 0; loop_j < std::min(m - loop_i, n); ++loop_j) {
        if (same_num != matrix[loop_j + loop_i][loop_j]) {
          return false;
        }
      }
    }
    return true; 
  }
};

int main() { return 0; }