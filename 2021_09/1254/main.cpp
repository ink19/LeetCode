#include <vector>

using namespace std;

class Solution {
public:
  int closedIsland(vector<vector<int>> &grid) {
    const int grid_height = grid.size();
    const int grid_width = grid[0].size();
    mgrid = &grid;
    grid_view = vector<vector<int>>(grid_height, vector<int>(grid_width, 0));

    int result = 0;
    for (int loop_h = 0; loop_h < grid_height; ++loop_h) {
      for (int loop_w = 0; loop_w < grid_width; ++loop_w) {
        bool temp_i = true;
        result += is_view(loop_h, loop_w, temp_i);
      }
    }
    return result;
  }
private:
  vector<vector<int>> grid_view;
  vector<vector<int>> *mgrid;
  int is_view(int begin_h, int begin_w, bool &island) {
    if (!(begin_h >= 0 && begin_h <= grid_view.size() - 1 && begin_w >= 0 && begin_w <= grid_view[0].size() - 1)) return island;
    if ((*mgrid)[begin_h][begin_w] == 0 && grid_view[begin_h][begin_w] != 1) {
      if (island && (begin_h == 0 || begin_w == 0 || begin_h == grid_view.size() - 1 || begin_w == grid_view[0].size() - 1)) island = false;
      grid_view[begin_h][begin_w] = 1;
      is_view(begin_h + 1, begin_w, island);
      is_view(begin_h - 1, begin_w, island);
      is_view(begin_h, begin_w + 1, island);
      is_view(begin_h, begin_w - 1, island);
    } else {
      return 0;
    }
    return island;
  }
};

