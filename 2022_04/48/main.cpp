#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    const int n = matrix.size();
    if (n <= 1) return;
    const int iter_n = (n + 1) / 2;
    const int iter_j = (n) / 2;
    for (int loop_i = 0; loop_i < iter_n; ++loop_i) {
      for (int loop_j = 0; loop_j < iter_j; ++loop_j) {
        const std::pair<int, int> swap_1 = {loop_i, loop_j};
        const std::pair<int, int> swap_2 = {loop_j, n - 1 - loop_i};
        const std::pair<int, int> swap_3 = {n - 1 - loop_i, n - 1 - loop_j};
        const std::pair<int, int> swap_4 = {n - 1 - loop_j, loop_i};
        std::swap(matrix[swap_1.first][swap_1.second], matrix[swap_4.first][swap_4.second]);
        std::swap(matrix[swap_3.first][swap_3.second], matrix[swap_4.first][swap_4.second]);
        std::swap(matrix[swap_2.first][swap_2.second], matrix[swap_3.first][swap_3.second]);
      }
    }
  }
};
