#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
  bool is_vali(std::pair<int, int> pos,const std::vector<std::vector<int>> &data) {
    if (!(pos.first >= 0 && pos.first < data.size())) return false;
    if (!(pos.second >= 0 && pos.second < data.at(0).size())) return false;
    if (data[pos.first][pos.second] != 0) return false;
    return true;
  }
  vector<vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));
    std::pair<int, int> pos_to = {0, 1};
    std::pair<int, int> pos = {0, 0};
    for (int loop_i = 0; loop_i < n * n; ++loop_i) {
      result[pos.first][pos.second] = loop_i + 1;
      if (!is_vali({pos_to.first + pos.first, pos_to.second + pos.second}, result)) {
        if (pos_to.second == 1) {
          pos_to = {1, 0};
        } else if (pos_to.second == -1) {
          pos_to = {-1, 0};
        } else if (pos_to.first == 1) {
          pos_to = {0, -1};
        } else if (pos_to.first == -1) {
          pos_to = {0, 1};
        }
      }
      pos = {pos_to.first + pos.first, pos_to.second + pos.second};
    }
    return result;
  }
};