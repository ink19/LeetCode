#include <iostream>

class Solution {
public:
  bool isPowerOfThree(int n) {
    if (n <= 0) return false;
    while (n != 1) {
      if (n % 3) {
        return false;
      } else {
        n /= 3;
      }
    }
    return true;
  }
};