#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int> &colsum) {
    const int col_len = colsum.size();
    std::vector<std::vector<int>> result(2, std::vector<int>(col_len, 0));
    int mupper = 0;
    int mlower = 0;
    for (int loop_i = 0; loop_i < col_len; ++loop_i) {
      if (colsum[loop_i] == 2) {
        result[0][loop_i] = 1;
        result[1][loop_i] = 1;
        mupper++;
        mlower++;
      } 
    }

    for (int loop_i = 0; loop_i < col_len; ++loop_i) {
      if (colsum[loop_i] == 1) {
        if (upper != mupper) {
          result[0][loop_i] = 1;
          mupper++;
        } else {
          result[1][loop_i] = 1;
          mlower++;
        }
      }
    }
    if (mlower != lower || mupper != upper) return {};
    return result;
  }
};