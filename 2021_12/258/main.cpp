#include <iostream>

class Solution {
public:
  int addDigits(int num) {
    while (num >= 10) {
      int temp_n = num;
      num = 0;
      while (temp_n != 0) {
        num += (temp_n % 10);
        temp_n /= 10;
      }
    }
    return num;
  }
};