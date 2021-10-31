#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void bfs(int x, int y, int &is_side, vector<vector<char>> &board, vector<vector<int>> &is_view, int is_color) {
        if (x < 0 || y < 0 || x >= board[0].size() || y >= board.size()) return;
        
        if (is_view[y][x] == 1) return;
        is_view[y][x] = 1;
        if (board[y][x] == 'X') return;
        if (x == 0 || y == 0 || x == board[0].size() - 1 || y == board.size() - 1) is_side = 1;
        bfs(x + 1, y, is_side, board, is_view, is_color);
        bfs(x - 1, y, is_side, board, is_view, is_color);
        bfs(x, y - 1, is_side, board, is_view, is_color);
        bfs(x, y + 1, is_side, board, is_view, is_color);
        if (is_color) {
            board[y][x] = 'X';
        }
    }

    void solve(vector<vector<char>> &board) {
        const int h = board.size();
        if (h == 0) return;
        const int w = board[0].size();
        if (w == 0) return;
        vector<vector<int>> viewed(h, vector<int>(w, 0));
        for (int loop_i = 0; loop_i < board.size(); ++loop_i) {
            for (int loop_j = 0; loop_j < board[0].size(); ++loop_j) {
                int is_side = 0;
                if (viewed[loop_j][loop_i]) continue;
                bfs(loop_j, loop_i, is_side, board, viewed, 0);
                if (!is_side) {
                    vector<vector<int>> viewed(h, vector<int>(w, 0));
                    bfs(loop_j, loop_i, is_side, board, viewed, 1);
                }
            }
        }
    }
};

int main() {
    vector<vector<char>> data =  {};
    Solution().solve(data);
    for (int loop_i = 0; loop_i < data.size(); ++loop_i) {
        for (int loop_j = 0; loop_j < data[0].size(); ++loop_j) {
            std::cout << data[loop_i][loop_j] << ", ";
        }
        std::cout << std::endl;
    }
}