#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int h = 0;
    int w = 0;

    int dfs(vector<vector<char>>& grid, int x, int y) {
        grid[y][x] = '0';
        if (y != 0 && grid[y - 1][x] == '1') {
            dfs(grid, x, y - 1);
        }
        if (x != 0 && grid[y][x - 1] == '1') {
            dfs(grid, x - 1, y);
        }
        if (y != h - 1 && grid[y + 1][x] == '1') {
            dfs(grid, x, y + 1);
        }
        if (x != w - 1 && grid[y][x + 1] == '1') {
            dfs(grid, x + 1, y);
        }
        return 0;
    }

    int numIslands(vector<vector<char>>& grid) {
        h = grid.size();
        if (h == 0) return 0;
        w = grid.at(0).size();
        if (w == 0) return 0;
        int result = 0;

        for (int loop_i = 0; loop_i < h; ++loop_i) {
            for (int loop_j = 0; loop_j < w; ++loop_j) {
                if (grid[loop_i][loop_j] == '1') {
                    result ++;
                    dfs(grid, loop_j, loop_i);
                }
            }
        }
        return result;
    }
};