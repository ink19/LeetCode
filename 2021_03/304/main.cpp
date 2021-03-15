#include <vector>

using namespace std;

class NumMatrix {
public:
  NumMatrix(vector<vector<int>> &matrix) {
    int row_len = matrix.size();
    int col_len = 0;
    if (row_len == 0) {
      col_len = 0;
    } else {
      col_len = matrix.at(0).size();
    }

    tmatrix = vector<vector<int>> (row_len + 1, vector<int>(col_len + 1, 0));
    for (int loop_i = 0; loop_i < row_len; ++loop_i) {
      for (int loop_j = 0; loop_j < col_len; ++loop_j) {
        tmatrix[loop_i + 1][loop_j + 1] = matrix[loop_i][loop_j];
        tmatrix[loop_i + 1][loop_j + 1] += (tmatrix[loop_i + 1][loop_j] + tmatrix[loop_i][loop_j + 1] - tmatrix[loop_i][loop_j]);
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return tmatrix[row1][col1] + tmatrix[row2 + 1][col2 + 1] - tmatrix[row2 + 1][col1] - tmatrix[row1][col2 + 1];
  }

private:
  vector<vector<int>> tmatrix;
};