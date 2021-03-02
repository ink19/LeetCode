#include <string>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<pair<int, int>> neib(vector<vector<int>> &searched, int row, int col) {
    vector<pair<int, int>> result;
    if (row > 0 && searched[row - 1][col] == 0) result.push_back({row - 1, col});
    if (col > 0 && searched[row][col - 1] == 0) result.push_back({row, col - 1});
    if (row < searched.size() - 1 && searched[row + 1][col] == 0) result.push_back({row + 1, col});
    if (col < searched.at(0).size() - 1 && searched[row][col + 1] == 0) result.push_back({row, col + 1}); 
    return result;
  }
  bool search(vector<vector<char>> &board, vector<vector<int>> &searched, int row, int col, const string& word, int c) {
    if (c >= word.size()) return true;
    searched[row][col] = 1;
    auto neig = neib(searched, row, col);
    for (auto neig_item : neig) {
      if (board[neig_item.first][neig_item.second] == word[c]) {
        if (search(board, searched, neig_item.first, neig_item.second, word, c + 1)) {
          return true;
        }
      }
    }
    searched[row][col] = 0;
    return false;
  }
  bool exist(vector<vector<char>> &board, string word) {
    const int board_row_num = board.size();
    const int board_col_num = board.at(0).size();
    vector<vector<int>> searched(board_row_num, vector<int>(board_col_num, 0));
    if (word.size() == 0) return true;
    for (int loop_i = 0; loop_i < board_row_num; ++loop_i) {
      for (int loop_j = 0; loop_j < board_col_num; ++loop_j) {
        if (board[loop_i][loop_j] == word[0]) {
          if (search(board, searched, loop_i, loop_j, word, 1)) {
            return true;
          }
        }
      }
    }
    return false;
  }
};

int main() {
  vector<vector<char>> map_board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
  auto str = "ABCCED";
  Solution s;
  std::cout << s.exist(map_board, str) << std::endl;
}