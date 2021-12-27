#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
  long long C(int N, int M) {
    long long sum = 1;
    for(int i=1;i<=M; i++) {
        sum=sum*(N-M+i)/i;
    }
    return sum;
}
  int get_n(int number) {
    int max_1_n = (number + 1) / 2;
    int result = 0;
    for (int loop_i = 0; loop_i <= max_1_n; ++loop_i) {
      result += C(number - loop_i + 1, loop_i);
    } 
    return result;
  }

  int findIntegers(int n) {
    int result = 0;
    int temp_n = n;
    int nn = 0;
    while (temp_n != 0) {
      nn++;
      temp_n >>= 1;
    }
    int break_flag = 1;
    for (int loop_i = nn; loop_i >= 0; --loop_i) {
      if ((n & (1 << loop_i))) {
        result += get_n(loop_i);
        if (loop_i != nn && (n & (1 << loop_i)) && (n & (1 << (loop_i + 1)))) {
          break_flag = 0;
          break;
        }
      }
    }
    result += break_flag;
    return result;
  }
};


int main() {
  std::cout << Solution().findIntegers(10000000) << std::endl;
}
