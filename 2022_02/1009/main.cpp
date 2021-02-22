#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
  int bitwiseComplement(int N) {
    if (N == 0) return 1;
    int nN = ~N;
    nN &= ((1 << int(std::floor(std::log2(N)) + 1)) - 1);
    return nN;
  }
};