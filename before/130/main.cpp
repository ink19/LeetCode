#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    int height = 0;
    int width = 0;
    void width_search(vector<vector<char>>& board, vector<vector<int>> &tag, int begin_h, int begin_w) {
        if (tag[begin_h][begin_w] == 1) return;
        tag[begin_h][begin_w] = 1;
        if (begin_w > 0 && board[begin_h][begin_w - 1] == 'O') {
            width_search(board, tag, begin_h, begin_w - 1);
        }
        if (begin_w < width - 1 && board[begin_h][begin_w + 1] == 'O') {
            width_search(board, tag, begin_h, begin_w + 1);
        }
        if (begin_h > 0 && board[begin_h - 1][begin_w] == 'O') {
            width_search(board, tag, begin_h - 1, begin_w);
        }
        if (begin_h < height - 1 && board[begin_h + 1][begin_w] == 'O') {
            width_search(board, tag, begin_h + 1, begin_w);
        }
    }

    void solve(vector<vector<char>>& board) {
        height = board.size();
        if (height == 0) return;
        width = board[0].size();
        if (width == 0) return;
        vector<vector<int>> tag(height, vector<int>(width, 0));
        for (int loop_i = 0; loop_i < height; ++loop_i) {
            if (board[loop_i][0] == 'O') width_search(board, tag, loop_i, 0);
            if (board[loop_i][width - 1] == 'O') width_search(board, tag, loop_i, width - 1);
        }
        for (int loop_j = 0; loop_j < width; ++loop_j) {
            if (board[0][loop_j] == 'O') width_search(board, tag, 0, loop_j);
            if (board[height - 1][loop_j] == 'O') width_search(board, tag, height - 1, loop_j);
        }

        for (int loop_i = 0; loop_i < height; ++loop_i) {
            for (int loop_j = 0; loop_j < width; ++loop_j) {
                if (board[loop_i][loop_j] == 'O' && tag[loop_i][loop_j] == 0) {
                    board[loop_i][loop_j] = 'X';
                }
            }
        }
    }
};


int main() {
    // char **data = {
    //     {'X','X','X','X'},
    //     {'X','O','O','X'},
    //     {'X','X','O','X'},
    //     {'X','O','X','X'}
    // };
    std::vector<std::vector<char>> data;
    data.push_back({'X','X','X','X'});
    data.push_back({'X','O','O','X'});
    data.push_back({'X','X','O','X'});
    data.push_back({'X','O','X','X'});

    Solution s;
    s.solve(data);
}