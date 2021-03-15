#include <vector>

using namespace std;


class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    const int row = matrix.size();
    if (row == 0) return vector<int>();
    const int col = matrix.at(0).size();
    if (col == 0) return vector<int>();
    vector<int> result(row * col, 0);
    int loop_i = 0;
    int loop_w = 0;
    int loop_h = 0;
    int inc_w = 1;
    int inc_h = 0;
    vector<vector<int>> tmatrix(row, vector<int>(col, 0));
    for (int loop_i = 0; loop_i < row * col; ++loop_i) {
      result[loop_i] = matrix[loop_h][loop_w];
      tmatrix[loop_h][loop_w] = 1;
      int next_w = loop_w + inc_w;
      int next_h = loop_h + inc_h;
      if (next_w < 0 || next_w >= col || 
        next_h < 0 || next_h >= row || tmatrix[next_h][next_w] == 1
      ) {
        if (inc_w == 1 && inc_h == 0) {
          inc_w = 0;
          inc_h = 1;
        } else if (inc_w == -1 && inc_h == 0) {
          inc_w = 0;
          inc_h = -1;
        } else if (inc_w == 0 && inc_h == 1) {
          inc_w = -1;
          inc_h = 0;
        } else if (inc_w == 0 && inc_h == -1) {
          inc_w = 1;
          inc_h = 0;
        }
        next_w = loop_w + inc_w;
        next_h = loop_h + inc_h;
      }
      loop_w = next_w;
      loop_h = next_h;
    }
    return result;
  }
};