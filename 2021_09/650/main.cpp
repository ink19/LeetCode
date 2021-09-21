#include <iostream>
#include <string>

class Solution {
public:
  int minSteps(int n) {
    int result = 0;
    for (int loop_i = 2; loop_i <= n; ++loop_i) {
      if (n % loop_i == 0) {
        result += loop_i + 1;
        n /= loop_i;
        loop_i--;
      }
    }
    return result;
  }
};

int main() {
  std::cout << Solution().minSteps(100) << std::endl;
  return 0;
}