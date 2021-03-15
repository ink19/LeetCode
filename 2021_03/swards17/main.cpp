#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
  vector<int> printNumbers(int n) {
    int nn = pow(10, n) - 1;
    vector<int> result(nn, 0);
    for (int loop_i = 0; loop_i < nn; ++loop_i) {
      result[loop_i] = loop_i + 1;
    }
    return result;
  }
};