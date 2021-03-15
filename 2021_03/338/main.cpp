#include <vector>

using namespace std;

class Solution {
public:
  vector<int> countBits(int num) {
    vector<int> result(num + 1, 0);
    result[0] = 0;
    if (num == 0) return result;
    result[1] = 1;
    int nn = 2;
    int loop_i = 2;
    while (loop_i < num + 1) {
      for (int loop_j = 0; loop_j < nn; ++loop_j) {
        result[loop_i] = result[loop_j] + 1;
        loop_i++;
        if (loop_i >= num + 1) break;
      }
      nn *= 2;
    }
    return result;
  }
};