#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool findNumberIn2DArrayS(vector<vector<int>> &matrix, int target, int begin_x, int begin_y, int end_x, int end_y) {
    if (begin_x == end_x && begin_y == end_y) {
      if (matrix[begin_x][begin_y] == target) {
        return true;
      } else {
        return false;
      }
    } 
    int mid_x = (begin_x + end_x) >> 1;
    int mid_y = (begin_y + end_y) >> 1;
    bool result = false;
    if (matrix[begin_x][begin_y] <= target && matrix[mid_x][mid_y] >= target) {
      result = result || findNumberIn2DArrayS(matrix, target, begin_x, begin_y, mid_x, mid_y);
    }
    if (begin_y != end_y && matrix[begin_x][mid_y + 1] <= target && matrix[mid_x][end_y] >= target) {
      result = result || findNumberIn2DArrayS(matrix, target, begin_x, mid_y + 1, mid_x, end_y);
    }
    if (begin_x != end_x && matrix[mid_x + 1][begin_y] <= target && matrix[end_x][mid_y] >= target) {
      result = result || findNumberIn2DArrayS(matrix, target, mid_x + 1, begin_y, end_x, mid_y);
    }
    if (begin_x != end_x && begin_y != end_y && matrix[mid_x+ 1][mid_y + 1] <= target && matrix[end_x][end_y] >= target) {
      result = result || findNumberIn2DArrayS(matrix, target, mid_x + 1, mid_y + 1, end_x, end_y);
    }
    return result;
  } 

  bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
    if (matrix.size() == 0 || matrix.at(0).size() == 0) return false;
    return findNumberIn2DArrayS(matrix, target, 0, 0, matrix.size() - 1, matrix.at(0).size() - 1);
  }
};

int main(){
  vector<vector<int>> data = {
    {1,   4,  7, 11, 15},
    {2,   5,  8, 12, 19},
    {3,   6,  9, 16, 22},
    {10, 13, 14, 17, 24},
    {18, 21, 23, 26, 30}
  };
  Solution s;
  std::cout << s.findNumberIn2DArray(data, 20) << std::endl;
  return 0;
}