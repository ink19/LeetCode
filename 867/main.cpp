#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
      const int m = matrix.size();
      const int n = matrix[0].size();
      vector<vector<int>> tmatrix(n, vector<int>(m, 0));
      for (int loop_i = 0; loop_i < m; ++loop_i) {
        for (int loop_j = 0; loop_j < n; ++loop_j) {
          tmatrix[loop_j][loop_i] = matrix[loop_i][loop_j];
        }
      }
      return tmatrix;
    }
};