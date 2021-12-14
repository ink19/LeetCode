#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
class Solution {
public:
  int getMoneyAmount(int n) {
    std::vector<std::vector<int>> data(n + 2, std::vector<int>(n + 2, 0));
    for (int loop_i = 1; loop_i < n + 1; ++loop_i) {
      for (int loop_j = 1; loop_j < n + 1; ++loop_j) {
        if (loop_i == 1) continue;
        int b = loop_j;
        int e = loop_i + loop_j - 1;
        if (e > n) break;
        int min_value = std::numeric_limits<int>::max();
        for (int loop_k = b; loop_k <= e; ++loop_k) {
          int temp_v = std::max(data[b][loop_k - 1] ,data[loop_k + 1][e]) + loop_k;
          if (temp_v < min_value) min_value = temp_v;
        }
        data[b][e] = min_value;
      }
    }
    return data[1][n];
  }
};

int main() {
  std::cout << Solution().getMoneyAmount(6) << std::endl;
}