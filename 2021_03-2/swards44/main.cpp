#include <vector>
#include <cmath>
#include <iostream>

class Solution {
public:
  int findNthDigit(int n) {
    int n_len = 1;
    long long temp_n = 10;
    long long last_temp_n = 0;
    while (temp_n <= n) {
      n_len++;
      last_temp_n = temp_n;
      temp_n += n_len * (9 * pow(10, n_len - 1));
    }
    n -= last_temp_n;
    int number = (n / n_len) + (n_len == 1? 0 : pow(10, n_len - 1));
    int number_di =  n_len - (n % n_len);
    return static_cast<int>(number/pow(10, number_di - 1))%10;
  }
};

int main () {
  Solution s;
  std::cout << s.findNthDigit(1000000000) << std::endl;
}