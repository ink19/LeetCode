#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool validTicTacToe(vector<string> &board) {
    int x_num = 0;
    int y_num = 0;
    int x_win = 0;
    int y_win = 0;
    for (int loop_i = 0; loop_i < 3; ++loop_i) {
      for (int loop_j = 0; loop_j < 3; ++loop_j) {
        if (board[loop_i][loop_j] == 'X') x_num++;
        if (board[loop_i][loop_j] == 'O') y_num++;
      }
    }
    if (!(x_num - y_num <= 1 && x_num >= y_num)) return false;
    for (int loop_i = 0; loop_i < 3; ++loop_i) {
      int x = 0;
      for (int loop_j = 0; loop_j < 3; ++loop_j) {
        if (board[loop_i][loop_j] == 'X') x += 1;
        if (board[loop_i][loop_j] == 'O') x += -1;
      }
      if (x == 3) x_win++;
      if (x == -3) y_win++;
    }
    for (int loop_i = 0; loop_i < 3; ++loop_i) {
      int x = 0;
      for (int loop_j = 0; loop_j < 3; ++loop_j) {
        if (board[loop_j][loop_i] == 'X') x += 1;
        if (board[loop_j][loop_i] == 'O') x += -1;
      }
      if (x == 3) x_win++;
      if (x == -3) y_win++;
    }

    {
      int x = 0;
      for (int loop_i = 0; loop_i < 3; ++loop_i) {
        if (board[loop_i][loop_i] == 'X') x += 1;
        if (board[loop_i][loop_i] == 'O') x += -1;
      }
      if (x == 3) x_win++;
      if (x == -3) y_win++;
      x = 0;
      for (int loop_i = 0; loop_i < 3; ++loop_i) {
        if (board[2 - loop_i][loop_i] == 'X') x += 1;
        if (board[2 - loop_i][loop_i] == 'O') x -= 1;
      }
      if (x == 3) x_win ++;
      if (x == -3) y_win ++;
    }
    if (x_win && y_win) return false;
    if (x_win && x_num == y_num) return false;
    if (y_win && x_num != y_num) return false;
    return true;
  }
};