#include <iostream>
#include <vector>
#include <queue>
#include <utility>

class Solution {
public:
  bool can_in(std::pair<int, int> &position, int k) {
    int n = position.first % 10 + position.first / 10;
    n += position.second % 10 + position.second / 10;
    if (n > k) return false;
    return true;
  }

  bool can_in_2(int row, int col, std::vector<std::vector<int>> &searched, int k) {
    if (row < 0 || col < 0) return false;
    if (row >= searched.size() || col >= searched.at(0).size()) return false;
    if (searched[row][col] == 1) return false;
    std::pair<int, int> position = {row, col};
    return can_in(position, k);
  }

  int movingCount(int m, int n, int k) {  
    std::vector<std::vector<int>> searched(m, std::vector<int>(n, 0));
    std::queue<std::pair<int, int>> searh_queue;
    searh_queue.push({0, 0});
    int count = 1;
    searched[0][0] = 1;
    while (!searh_queue.empty()) {
      auto search_position = searh_queue.front();
      searh_queue.pop();
      if (can_in_2(search_position.first - 1, search_position.second, searched, k)) {
        count += 1;
        searched[search_position.first - 1][search_position.second] = 1;
        searh_queue.push({search_position.first - 1, search_position.second});
      }
      if (can_in_2(search_position.first + 1, search_position.second, searched, k)) {
        count += 1;
        searched[search_position.first + 1][search_position.second] = 1;
        searh_queue.push({search_position.first + 1, search_position.second});
      }
      if (can_in_2(search_position.first, search_position.second - 1, searched, k)) {
        count += 1;
        searched[search_position.first][search_position.second - 1] = 1;
        searh_queue.push({search_position.first, search_position.second - 1});
      }
      if (can_in_2(search_position.first, search_position.second + 1, searched, k)) {
        count += 1;
        searched[search_position.first][search_position.second + 1] = 1;
        searh_queue.push({search_position.first, search_position.second + 1});
      }
    }
    return count;
  }
};