#include <vector>

using namespace std;

class Solution {
public:
  bool isValid(int x, int y, int m, int n) {
    if (0 <= x && 0 <= y && m > x && n > y) return true;
    return false;
  }

  int life_cell(const vector<vector<int>>& board, int x, int y) {
    const int m = board.size();
    const int n = board[0].size();
    int result = 0;
    if (isValid(x - 1, y, m, n)) result += board[x - 1][y];
    if (isValid(x - 1, y + 1, m, n)) result += board[x - 1][y + 1];
    if (isValid(x - 1, y - 1, m, n)) result += board[x - 1][y - 1];
    if (isValid(x + 1, y, m, n)) result += board[x + 1][y];
    if (isValid(x + 1, y + 1, m, n)) result += board[x + 1][y + 1];
    if (isValid(x + 1, y - 1, m, n)) result += board[x + 1][y - 1];
    if (isValid(x, y + 1, m, n)) result += board[x][y + 1];
    if (isValid(x, y - 1, m, n)) result += board[x][y - 1];
    return result;
  }

  void gameOfLife(vector<vector<int>> &board) {
    const int m = board.size();
    const int n = board[0].size();
    vector<vector<int>> new_board(m, vector<int>(n, 0));
    for (int loop_i = 0; loop_i < m; ++loop_i) {
      for (int loop_j = 0; loop_j < n; ++loop_j) {
        int life_n = life_cell(board, loop_i, loop_j);
        if (board[loop_i][loop_j]) {
          if (life_n < 2 || life_n > 3) new_board[loop_i][loop_j] = 0;
          else new_board[loop_i][loop_j] = 1;
        } else {
          if (life_n == 3) new_board[loop_i][loop_j] = 1;
          else new_board[loop_i][loop_j] = 0;
        }
      }
    }
    for (int loop_i = 0; loop_i < m; ++loop_i) {
      for (int loop_j = 0; loop_j < n; ++loop_j) {
        board[loop_i][loop_j] = new_board[loop_i][loop_j];
      }
    }
  }
};