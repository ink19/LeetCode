#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


#define MOD_DATA 1000000007
struct dataStruct {
  int sum;
  int plan_num;
};

class Solution {
public:
  vector<int> pathsWithMaxScore(vector<string> &board) {
    int result = 0, result_plan = 0;
    const int board_size = board.size();
    vector<vector<dataStruct>> board_view(board_size, vector<dataStruct>(board_size, dataStruct()));
    
    board_view[0][0].sum = 0;
    board_view[0][0].plan_num = 1;

    for (int loop_i = 1; loop_i < board_size; ++loop_i) {
      if (board[loop_i][0] == 'X' || board_view[loop_i - 1][0].plan_num == 0) {
        board_view[loop_i][0].plan_num = 0;
        board_view[loop_i][0].sum = -1;
      } else {
        board_view[loop_i][0].plan_num = 1;
        board_view[loop_i][0].sum = board[loop_i][0] - '0' + board_view[loop_i - 1][0].sum;
      }

      if (board[0][loop_i] == 'X' || board_view[0][loop_i - 1].plan_num == 0) {
        board_view[0][loop_i].plan_num = 0;
        board_view[0][loop_i].sum = -1;
      } else {
        board_view[0][loop_i].plan_num = 1;
        board_view[0][loop_i].sum = board[0][loop_i] - '0' + board_view[0][loop_i - 1].sum;
      }
    }

    for (int loop_i = 1; loop_i < board_size; ++loop_i) {
      for (int loop_j = 1; loop_j < board_size; ++loop_j) {
        if (board[loop_i][loop_j] == 'X') {
          board_view[loop_i][loop_j].plan_num = 0;
          continue;
        }
        
        int max_data = 0;
        int plan_sum = 0;
        max_data = std::max({board_view[loop_i - 1][loop_j].sum, board_view[loop_i][loop_j - 1].sum, board_view[loop_i - 1][loop_j - 1].sum});
        if (max_data == board_view[loop_i - 1][loop_j].sum) {
          plan_sum += board_view[loop_i - 1][loop_j].plan_num;
          plan_sum %= MOD_DATA;
        }

        if (max_data == board_view[loop_i - 1][loop_j - 1].sum) {
          plan_sum += board_view[loop_i - 1][loop_j - 1].plan_num;
          plan_sum %= MOD_DATA;
        }

        if (max_data == board_view[loop_i][loop_j - 1].sum) {
          plan_sum += board_view[loop_i][loop_j - 1].plan_num;
          plan_sum %= MOD_DATA;
        }

        board_view[loop_i][loop_j].plan_num = plan_sum;
        board_view[loop_i][loop_j].sum = max_data + board[loop_i][loop_j] - '0';
      }
    }

    result_plan = board_view[board_size - 1][board_size - 1].plan_num;
    result = board_view[board_size - 1][board_size - 1].sum + '0' - 'S';
    if (result_plan == 0) return {0, 0};
    return {result, result_plan};
  }
};

int main() {
  vector<string> data = {
    "E23",
    "2X2",
    "12S"};
  auto out = Solution().pathsWithMaxScore(data);
  std::cout << out[0] << ", " << out[1] << std::endl;
}