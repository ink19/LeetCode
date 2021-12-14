#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
    const int m = mat.size();
    const int n = mat[0].size();
    std::pair<int, int> pos = {-1, 1};
    std::pair<int, int> index = {0, 0};
    std::vector<int> result;
    while (index.first != m - 1 || index.second != n - 1) {
      result.push_back(mat[index.first][index.second]);
      index = {pos.first + index.first, pos.second + index.second};
      if (index.first < 0 || index.first >= m || index.second < 0 || index.second >= n) {
        index = {index.first - pos.first, index.second - pos.second};
        if (index.first == m - 1) index = {index.first, index.second + 1};
        else if (index.second == n - 1) index = {index.first + 1, index.second};
        else if (index.first == 0) index = {index.first, index.second + 1};
        else index = {index.first + 1, index.second};;
        pos = {-pos.first, -pos.second};
      }
    }
    result.push_back(mat[m - 1][n - 1]);
    return result;
  }
};

int main() {
  std::vector<std::vector<int>> data = {{2, 3}};
  auto result = Solution().findDiagonalOrder(data);
  for (int loop_i = 0; loop_i < result.size(); ++loop_i) {
    std::cout << result[loop_i] << " ";
  }
  std::cout << std::endl;
}